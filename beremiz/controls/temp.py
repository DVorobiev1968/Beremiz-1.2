def RefreshTree(self):
    """
    Refresh LibraryPanel values displayed in controls
    """
    # Get function and function blocks library
    blocktypes = self.BlockList
    if blocktypes is None and self.Controller is not None:
        # Get library from project controller if not defined
        blocktypes = self.Controller.GetBlockTypes()

    # Refresh TreeCtrl values if a library is defined
    if blocktypes is not None:
        # List that will contain tree items to be deleted when TreeCtrl
        # will be refreshed
        items_to_delete = []

        # Get current selected item for selected it when values refreshed
        selected_item = self.Tree.GetSelection()
        selected_pydata = (self.Tree.GetPyData(selected_item)
                           if (selected_item.IsOk() and
                               selected_item != self.Tree.GetRootItem())
                           else None)
        # Don't save selected item if it is a category
        selected_infos = ((self.Tree.GetItemText(selected_item),
                           selected_pydata["inputs"])
                          if (selected_pydata is not None and
                              selected_pydata["type"] == BLOCK)
                          else (None, None))

        # Get TreeCtrl root item (hidden)
        root = self.Tree.GetRootItem()
        if not root.IsOk():
            # Create root if not present
            root = self.Tree.AddRoot("")

        # Iterate over functions and function blocks library categories and
        # add a tree item to root item for each of them

        # Get first child under root item
        category_item, root_cookie = self.Tree.GetFirstChild(root)
        for category in blocktypes:
            # Store category name in a local variable to prevent script
            # extracting translated strings for gettext to consider "name"
            # to be translated
            category_name = category["name"]

            # Tree item already exists, set item label
            if category_item.IsOk():
                self.Tree.SetItemText(category_item, _(category_name))

            # Tree item doesn't exist, add new one to root
            else:
                category_item = self.Tree.AppendItem(root, _(category_name))
                # On Windows, needs to get next child of root to have a
                # reference to the newly added tree item
                if wx.Platform != '__WXMSW__':
                    category_item, root_cookie = \
                        self.Tree.GetNextChild(root, root_cookie)

            # Set data associated to tree item (only save that item is a
            # category)
            self.Tree.SetPyData(category_item, {"type": CATEGORY})

            # Iterate over functions and function blocks defined in library
            # category add a tree item to category tree item for each of
            # them

            # Get first child under category tree item
            blocktype_item, category_cookie = \
                self.Tree.GetFirstChild(category_item)
            for blocktype in category["list"]:

                # Tree item already exists, set item label
                if blocktype_item.IsOk():
                    self.Tree.SetItemText(blocktype_item, blocktype["name"])

                # Tree item doesn't exist, add new one to category item
                else:
                    blocktype_item = self.Tree.AppendItem(
                                        category_item, blocktype["name"])
                    # See comment when adding category
                    if wx.Platform != '__WXMSW__':
                        blocktype_item, category_cookie = \
                            self.Tree.GetNextChild(category_item,
                                                   category_cookie)

                # Define data to associate to block tree item
                comment = blocktype["comment"]
                block_data = {
                    "type":       BLOCK,
                    "block_type": blocktype["type"],
                    "inputs":     tuple([type
                                         for name, type, modifier
                                         in blocktype["inputs"]]),
                    "extension":  (len(blocktype["inputs"])
                                   if blocktype["extensible"] else None),
                    "comment":    _(comment) + blocktype.get("usage", "")
                }
                self.Tree.SetPyData(blocktype_item, block_data)

                # Select block tree item in tree if it corresponds to
                # previously selected one
                if selected_infos == (blocktype["name"],
                                      blocktype["inputs"]):
                    self.Tree.SelectItem(blocktype_item)

                    # Update TextCtrl value
                    self.Comment.SetValue(block_data["comment"])

                # Get next block tree item under category tree item
                blocktype_item, category_cookie = \
                    self.Tree.GetNextChild(category_item, category_cookie)

            # Add every remaining tree item under category tree item after
            # updating all block items to the list of items to delete
            while blocktype_item.IsOk():
                items_to_delete.append(blocktype_item)
                blocktype_item, category_cookie = \
                    self.Tree.GetNextChild(category_item, category_cookie)

            # Get next category tree item under root item
            category_item, root_cookie = \
                self.Tree.GetNextChild(root, root_cookie)

        # Add every remaining tree item under root item after updating all
        # category items to the list of items to delete
        while category_item.IsOk():
            items_to_delete.append(category_item)
            category_item, root_cookie = \
                self.Tree.GetNextChild(root, root_cookie)

        # Remove all items in list of items to delete from TreeCtrl
        for item in items_to_delete:
            self.Tree.Delete(item)
