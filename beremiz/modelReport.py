#!/usr/bin/python
"""modelReport Module for building documentation on control algorithms of an automatic control system (ACS)."""
import wx
import abstractmodel
#from ProjectController import ProjectController, GetAddMenuItems, MATIEC_ERROR_MODEL, ITEM_CONFNODE

CODE_SHOW_XML = 1
CODE_REPORT = 2
CODE_SAVE_DB = 3
CODE_RESERV = 4
WIDTH_FRAME = 900
HIGHT_FRAME = 500
TYPE_VALUE=[str,unicode]

class switch(object):
    def __init__(self, value):
        self.value = value
        self.fall = False

    def __iter__(self):
        yield self.match
        raise StopIteration

    def match(self, *args):
        if self.fall or not args:
            return True
        elif self.value in args:
            self.fall = True
            return True
        return False


class SimpleName(abstractmodel.AbstractModel):
    def __init__(self, code=0, protocol=""):
        abstractmodel.AbstractModel.__init__(self)
        self.set(code, protocol)

    def set(self, code, protocol):
        self.code = code
        for case in switch(code):
            if case("{0:d}".format(CODE_SHOW_XML)):
                self.protocol = "Starting: {0:<100}".format(protocol)
                break
            if case():
                self.protocol = "Under construction: {0:s}".format(protocol)
                break
        self.update()


class PCNT():
    def __init__(self):
        self.name = "Initial"
        self.dict_infos= {}
        self.list_vars=[]

    def setName(self, s_name):
        self.name = s_name

    def getName(self):
        return self.name

    def setInfos(self, infos):
        pass

    def getInfos(self,dict_infos):
        tmp_str = "getInfos:\n"
        index = 0
        for k, v in dict_infos.items():
            tmp_str = tmp_str + "{0:d};{1};{2}\n".format(index, k, v)
            index = index + 1
        return tmp_str

    def getVars(self,list_vars):
        tmp_str = "getVars:\n"
        index = 0
        for each in list_vars:
            for k, v in each.items():
                tmp_str = tmp_str + "{0:d};{1};{2}\n".format(index, k, v)
                index = index + 1
        return tmp_str

    def getList(self):
        tmp_str = "getVars:\n"
        index = 1
        for each in self.list_vars:
            tmp_str=tmp_str+"{0:d};".format(index)
            for k, v in each.items():
                if type(v) in TYPE_VALUE:
                    tmp_str = tmp_str + "{0:s};{1:s};".format(k, v.encode('ascii','ignore').decode('ascii'))
                else:
                    tmp_str = tmp_str + "{0:s};{1};".format(k, v)
            index = index + 1
            tmp_str=tmp_str+'\n'
        return tmp_str

class ModelReport(wx.Frame):
    def __init__(self, parent, id, infos):
        wx.Frame.__init__(self, parent, id, 'Reporting documentation ACS',
                          size=(WIDTH_FRAME, HIGHT_FRAME))
        self.pcnt = PCNT(infos)
        panel = wx.Panel(self)
        panel.SetBackgroundColour("White")
        self.Bind(wx.EVT_CLOSE, self.OnCloseWindow)
        self.textFields = {}
        self.createTextFields(panel)
        self.model = SimpleName()
        self.model.addListener(self.OnUpdate)
        self.createButtonBar(panel)
        self.debug = False


    def buttonData(self):
        return (("Show XML", self.OnShowXML),
                ("Report", self.OnReport),
                ("Save DB", self.OnSaveDB),
                ("Reserv", self.OnReserv))

    def createButtonBar(self, panel, yPos=0):
        xPos = 0
        for eachLabel, eachHandler in self.buttonData():
            pos = (xPos, yPos)
            button = self.buildOneButton(panel, eachLabel, eachHandler, pos)
            xPos += button.GetSize().width

    def buildOneButton(self, parent, label, handler, pos=(0, 0)):
        button = wx.Button(parent, -1, label, pos)
        self.Bind(wx.EVT_BUTTON, handler, button)
        return button

    def textFieldData(self):
        return (("Code", (10, 50), (50, -1)),
                ("Protocol", (10, 80), (800, 300)))

    def createTextFields(self, panel):
        for eachLabel, eachPos, eachSize in self.textFieldData():
            for case in switch(eachLabel):
                if case("Code"):
                    self.createCaptionedText(panel, eachLabel, eachPos, eachSize)
                    break
                if case():
                    self.createCaptionedText_HSCROLL(panel, eachLabel, eachPos, eachSize)
                    break

    def createCaptionedText(self, panel, label, pos, size):
        static = wx.StaticText(panel, wx.NewId(), label, pos, size)
        static.SetBackgroundColour("Yellow")
        textPos = (pos[0], pos[1])
        size = (size[0], size[1])
        self.textFields[label] = wx.TextCtrl(panel,
                                             wx.NewId(),
                                             "", size=size, pos=textPos,
                                             style=wx.TE_READONLY)

    def createCaptionedText_HSCROLL(self, panel, label, pos, size):
        static = wx.StaticText(panel, wx.NewId(), label, pos, size)
        static.SetBackgroundColour("White")
        textPos = (pos[0], pos[1])
        size = (size[0], size[1])
        self.textFields[label] = wx.TextCtrl(panel,
                                             wx.NewId(),
                                             "", size=size, pos=textPos,
                                             style=wx.TE_READONLY | wx.TE_MULTILINE)

    def OnUpdate(self, model):
        self.textFields["Code"].SetValue(model.code)
        self.textFields["Protocol"].SetValue(model.protocol)

    def printvarsGlobal(self):
        tmp_str = "Global variables:\n"
        index = 0
        for k, v in globals().items():
            if not k.startswith("_"):
                tmp_str = tmp_str + "{0:d};{1};{2}\n".format(index, k, v)
                index = index + 1
        return tmp_str

    def printvarsArea(self):
        tmp_str = "Area variables:\n"
        index = 0
        for each in dir():
            tmp_str = tmp_str + "{0:d};{1}\n".format(index, each)
            index = index + 1
        return tmp_str

    def printvarsLocal(self):
        tmp_str = "Area variables:\n"
        index = 0
        for k, v in locals().items():
            if not k.startswith("_"):
                tmp_str = tmp_str + "{0:d};{1};{2}\n".format(index, k, v)
                index = index + 1
        return tmp_str

    def printvarsBuiltin(self):
        tmp_str = "Builint variables:\n"
        index = 0
        for k, v in __builtins__.items():
            tmp_str = tmp_str + "{0:d};{1};{2}\n".format(index, k, v)
            index = index + 1
        return tmp_str

    def OnShowXML(self, event):
        # out_str = self.pcnt.getInfos()
        # out_str=self.printvarsGlobal()
        out_str=self.pcnt.getVars()
        self.model.set("{0:d}".format(CODE_SHOW_XML), out_str)

    def OnSaveDB(self, event):
        out_str = self.printvarsBuiltin()
        self.model.set("{0:d}".format(CODE_SAVE_DB), out_str)

    def OnReport(self, event):
        out_str = self.printvarsArea()
        self.model.set("{0:d}".format(CODE_REPORT), out_str)

    def OnReserv(self, event):
        out_str = self.printvarsLocal()
        self.model.set("{0:d}".format(CODE_RESERV), out_str)

    def OnCloseWindow(self, event):
        self.Destroy()


if __name__ == '__main__':
    app = wx.PySimpleApp()
    frame = ModelReport(parent=None, id=-1)
    frame.Show()
    app.MainLoop()
