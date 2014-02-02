require("dumpinfo")

--dofile("test.lua")

print("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<current thread infomation>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")

local function DumpCallInfo()
    print("DumpCallInfo")
    print("length","memmory(Byte)")
    print(dumpinfo.ThreadStateCallInfo())
end

local function DumpCurThreadOpenValue()
    print("DumpCurThreadOpenValue")
    print("length","memmory(Byte)")
    print(dumpinfo.ThreadStateOpneUpValuesInfo())
end

local function DumpCurThreadGCObject()
    print("DumpCurThreadGCObject")
    print("length","memmory(Byte)")
    print(dumpinfo.ThreadStateGCObjectInfo())
end

DumpCallInfo()
DumpCurThreadOpenValue()
DumpCurThreadGCObject()

print("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<global state infomation>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")

local function DumpGlobalStateString()
    print("DumpGlobalStateString")
    print("memmory(Byte)")
    print(dumpinfo.GlobalStateStringTableInfo())
end

DumpGlobalStateString()

local Text = "\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()\
DumpCallInfo()\
DumpCurThreadOpenValue()\
DumpCurThreadGCObject()"

DumpGlobalStateString()