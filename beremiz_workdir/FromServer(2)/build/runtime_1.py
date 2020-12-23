#!/usr/bin/env python
# -*- coding: utf-8 -*-
## Code generated by Beremiz python mixin confnode
##

## Code for PLC global variable access
from targets.typemapping import TypeTranslator
import ctypes
_py_ext_0GlobalsDesc = []
__ext_name__ = "py_ext_0"
PLCGlobalsDesc.append(( "py_ext_0" , _py_ext_0GlobalsDesc ))
_debug_ctype, _debug_unpack, _debug_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_debug = PLCBinary.__SafeGetPLCGlob_debug
_PySafeGetPLCGlob_debug.restype = None
_PySafeGetPLCGlob_debug.argtypes = [ctypes.POINTER(_debug_ctype)]
_PySafeSetPLCGlob_debug = PLCBinary.__SafeSetPLCGlob_debug
_PySafeSetPLCGlob_debug.restype = None
_PySafeSetPLCGlob_debug.argtypes = [ctypes.POINTER(_debug_ctype)]
_py_ext_0GlobalsDesc.append((
    "debug",
    "INT",
    'Print Debug 1:info+warning+error, 2:warning+error, 3:error, 4:none',
    None,
    u''))

_PATH_ctype, _PATH_unpack, _PATH_pack = \
    TypeTranslator["STRING"]
_PySafeGetPLCGlob_PATH = PLCBinary.__SafeGetPLCGlob_PATH
_PySafeGetPLCGlob_PATH.restype = None
_PySafeGetPLCGlob_PATH.argtypes = [ctypes.POINTER(_PATH_ctype)]
_PySafeSetPLCGlob_PATH = PLCBinary.__SafeSetPLCGlob_PATH
_PySafeSetPLCGlob_PATH.restype = None
_PySafeSetPLCGlob_PATH.argtypes = [ctypes.POINTER(_PATH_ctype)]
_py_ext_0GlobalsDesc.append((
    "PATH",
    "STRING",
    'PATH to Source file',
    None,
    u''))

_i_status_ctype, _i_status_unpack, _i_status_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_i_status = PLCBinary.__SafeGetPLCGlob_i_status
_PySafeGetPLCGlob_i_status.restype = None
_PySafeGetPLCGlob_i_status.argtypes = [ctypes.POINTER(_i_status_ctype)]
_PySafeSetPLCGlob_i_status = PLCBinary.__SafeSetPLCGlob_i_status
_PySafeSetPLCGlob_i_status.restype = None
_PySafeSetPLCGlob_i_status.argtypes = [ctypes.POINTER(_i_status_ctype)]
_py_ext_0GlobalsDesc.append((
    "i_status",
    "INT",
    'Error servers',
    None,
    u''))

_host_ctype, _host_unpack, _host_pack = \
    TypeTranslator["STRING"]
_PySafeGetPLCGlob_host = PLCBinary.__SafeGetPLCGlob_host
_PySafeGetPLCGlob_host.restype = None
_PySafeGetPLCGlob_host.argtypes = [ctypes.POINTER(_host_ctype)]
_PySafeSetPLCGlob_host = PLCBinary.__SafeSetPLCGlob_host
_PySafeSetPLCGlob_host.restype = None
_PySafeSetPLCGlob_host.argtypes = [ctypes.POINTER(_host_ctype)]
_py_ext_0GlobalsDesc.append((
    "host",
    "STRING",
    'Name server',
    None,
    u''))

_PORT_ctype, _PORT_unpack, _PORT_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_PORT = PLCBinary.__SafeGetPLCGlob_PORT
_PySafeGetPLCGlob_PORT.restype = None
_PySafeGetPLCGlob_PORT.argtypes = [ctypes.POINTER(_PORT_ctype)]
_PySafeSetPLCGlob_PORT = PLCBinary.__SafeSetPLCGlob_PORT
_PySafeSetPLCGlob_PORT.restype = None
_PySafeSetPLCGlob_PORT.argtypes = [ctypes.POINTER(_PORT_ctype)]
_py_ext_0GlobalsDesc.append((
    "PORT",
    "INT",
    'number of port for communication',
    None,
    u''))

_INFO_ctype, _INFO_unpack, _INFO_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_INFO = PLCBinary.__SafeGetPLCGlob_INFO
_PySafeGetPLCGlob_INFO.restype = None
_PySafeGetPLCGlob_INFO.argtypes = [ctypes.POINTER(_INFO_ctype)]
_PySafeSetPLCGlob_INFO = PLCBinary.__SafeSetPLCGlob_INFO
_PySafeSetPLCGlob_INFO.restype = None
_PySafeSetPLCGlob_INFO.argtypes = [ctypes.POINTER(_INFO_ctype)]
_py_ext_0GlobalsDesc.append((
    "INFO",
    "INT",
    'Debug message level',
    None,
    u''))

_WARNING_ctype, _WARNING_unpack, _WARNING_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_WARNING = PLCBinary.__SafeGetPLCGlob_WARNING
_PySafeGetPLCGlob_WARNING.restype = None
_PySafeGetPLCGlob_WARNING.argtypes = [ctypes.POINTER(_WARNING_ctype)]
_PySafeSetPLCGlob_WARNING = PLCBinary.__SafeSetPLCGlob_WARNING
_PySafeSetPLCGlob_WARNING.restype = None
_PySafeSetPLCGlob_WARNING.argtypes = [ctypes.POINTER(_WARNING_ctype)]
_py_ext_0GlobalsDesc.append((
    "WARNING",
    "INT",
    'Debug message level',
    None,
    u''))

_ERROR_ctype, _ERROR_unpack, _ERROR_pack = \
    TypeTranslator["INT"]
_PySafeGetPLCGlob_ERROR = PLCBinary.__SafeGetPLCGlob_ERROR
_PySafeGetPLCGlob_ERROR.restype = None
_PySafeGetPLCGlob_ERROR.argtypes = [ctypes.POINTER(_ERROR_ctype)]
_PySafeSetPLCGlob_ERROR = PLCBinary.__SafeSetPLCGlob_ERROR
_PySafeSetPLCGlob_ERROR.restype = None
_PySafeSetPLCGlob_ERROR.argtypes = [ctypes.POINTER(_ERROR_ctype)]
_py_ext_0GlobalsDesc.append((
    "ERROR",
    "INT",
    'Debug message level',
    None,
    u''))


## User code in "global" scope


print "All python PLC load globals variables: ", PLCGlobalsDesc
print "Current extention name: ", __ext_name__



## Beremiz python runtime calls
def _runtime_1_init():
    PLCGlobals.PORT=8889
    PLCGlobals.debug=1

def _runtime_1_cleanup():
    pass

def _runtime_1_start():
    pass

def _runtime_1_stop():
    pass



del __ext_name__
