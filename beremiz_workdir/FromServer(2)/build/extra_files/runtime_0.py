#!/usr/bin/env python
# -*- coding: utf-8 -*-
## Code generated by Beremiz python mixin confnode
##

## Code for PLC global variable access
from targets.typemapping import TypeTranslator
import ctypes
_pythonGlobalsDesc = []
__ext_name__ = "python"
PLCGlobalsDesc.append(( "python" , _pythonGlobalsDesc ))


## User code in "global" scope


import sys, string, getopt, socket

from user.MesPacked import MesPacked
from user.NodeInfo import NodeInfo
from user.Nodes import Nodes
from user.PLCGlobals import PLCGlobals
from user.SocketClient import SocketClient

def loadSettings(key, mesPacked):
    if key==1:
        if len(PLCGlobals.host) < 1:
            return "localhost"
        else:
            return PLCGlobals.host
    elif key==2:
        if PLCGlobals.PORT < 1:
            return mesPacked.port
        else:
            return PLCGlobals.PORT
    else:
        pass

def set_socket_node(id_Node, id_Obj, d_value=0, idSubObj=0, host="", port=0):
    global mesPacked
    
    if len(host)<1:
        host = loadSettings(1, mesPacked)
    if port<1:
        port = loadSettings(2, mesPacked)
    socketClient = SocketClient()
    socketClient.set_socket_node(id_Node,id_Obj,socketClient.mesPacked.CODE_SINGLE_START,d_value)

def load_socket_node(id_Node, id_Obj, idSubObj=0, host="", port=0):
    global mesPacked

    if len(host)<1:
        host = loadSettings(1, mesPacked)
    if port<1:
        port = loadSettings(2, mesPacked)
    socketClient = SocketClient()
    d_value=socketClient.load_socket_node(id_Node, id_Obj)

    return d_value





## Beremiz python runtime calls
def _runtime_0_init():
    print "python init section..."
    global mesPacked, nodes
    mesPacked=MesPacked()
    nodes=Nodes()

def _runtime_0_cleanup():
    pass

def _runtime_0_start():
    messageErr="py_runtime start..."
    print "Debug: ", PLCGlobals.debug
    print "Bases: ", PLCGlobals.PATH
    print "Host: ", PLCGlobals.host
    print "Port ", PLCGlobals.PORT

def _runtime_0_stop():
    print "py_runtime stop"



del __ext_name__
