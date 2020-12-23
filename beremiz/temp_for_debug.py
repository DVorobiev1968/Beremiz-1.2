for i, enum in enumerate(infos.get('values')): 
    if enum.get('type')==11:
        tag=enum.get('values')
        tagName=tag[0].get('tagname')
        print tagName
        break

enum.get('values')[0].get('tagname')
tagName=[enum.get('values')[0].get('tagname') for enum in infos.get('values') if enum.get('type')==11]