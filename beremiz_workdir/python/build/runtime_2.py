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
_SomeVarName_ctype, _SomeVarName_unpack, _SomeVarName_pack = \
    TypeTranslator["DINT"]
_PySafeGetPLCGlob_SomeVarName = PLCBinary.__SafeGetPLCGlob_SomeVarName
_PySafeGetPLCGlob_SomeVarName.restype = None
_PySafeGetPLCGlob_SomeVarName.argtypes = [ctypes.POINTER(_SomeVarName_ctype)]
_PySafeSetPLCGlob_SomeVarName = PLCBinary.__SafeSetPLCGlob_SomeVarName
_PySafeSetPLCGlob_SomeVarName.restype = None
_PySafeSetPLCGlob_SomeVarName.argtypes = [ctypes.POINTER(_SomeVarName_ctype)]
_py_ext_0GlobalsDesc.append((
    "SomeVarName",
    "DINT",
    u'',
    None,
    u''))

_Grumpf_ctype, _Grumpf_unpack, _Grumpf_pack = \
    TypeTranslator["STRING"]
_PySafeGetPLCGlob_Grumpf = PLCBinary.__SafeGetPLCGlob_Grumpf
_PySafeGetPLCGlob_Grumpf.restype = None
_PySafeGetPLCGlob_Grumpf.argtypes = [ctypes.POINTER(_Grumpf_ctype)]
_PySafeSetPLCGlob_Grumpf = PLCBinary.__SafeSetPLCGlob_Grumpf
_PySafeSetPLCGlob_Grumpf.restype = None
_PySafeSetPLCGlob_Grumpf.argtypes = [ctypes.POINTER(_Grumpf_ctype)]
_py_ext_0GlobalsDesc.append((
    "Grumpf",
    "STRING",
    u'',
    None,
    u''))


## User code in "global" scope




## Beremiz python runtime calls
def _runtime_2_init():
    pass

def _runtime_2_cleanup():
    pass

def _runtime_2_start():
    pass

def _runtime_2_stop():
    pass



del __ext_name__

