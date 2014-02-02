#include "EditorSync.h"
#include "TPacket.h"

#include <cassert>
#include <cstdlib>
#include <cstdio>

class TPacket;

static TPacket EditorDataStream;
static TPacket EngineDataStream;

#ifdef __cplusplus
extern "C" {
#endif

//打包相关接口
void _PackInt(TPacket& packet,void *data,int size){
    int8_t  v8;
    int16_t v16;
    int32_t v32;
    int64_t v64;
    switch(size)
    {
        case sizeof(int8_t):
            v8=*((int8_t*)data);
            packet.PackInt8(v8);
        case sizeof(int16_t):
            v16=*((int16_t*)data);
            packet.PackInt16(v16);
        case sizeof(int32_t):
            v32=*((int32_t*)data);
            packet.PackInt32(v32);
        case sizeof(int64_t):
            v64=*((int64_t*)data);
            packet.PackInt64(v64);
    }
}

void _PackUint(TPacket& packet,void *data,int size){
    uint8_t  v8;
    uint16_t v16;
    uint32_t v32;
    uint64_t v64;
    switch(size)
    {
        case sizeof(uint8_t):
            v8=*((uint8_t*)data);
            packet.PackUint8(v8);
        case sizeof(uint16_t):
            v16=*((uint16_t*)data);
            packet.PackUint16(v16);
        case sizeof(uint32_t):
            v32=*((uint32_t*)data);
            packet.PackUint32(v32);
        case sizeof(uint64_t):
            v64=*((uint64_t*)data);
            packet.PackUint64(v64);
    }
}

void _PackFloat(TPacket& packet,void *data,int size){
    float  f;
    double d;
    switch(size)
    {
        case sizeof(float):
            f=*((float*)data);
            packet.PackFloat(f);
        case sizeof(double):
            d=*((double*)data);
            packet.PackDouble(d);
    }
}

void _PackStr(TPacket& packet,const char* value){
    if (!value){
        packet.PackStr(value);
    }
}

//解包相关接口
int _UnPackUint(TPacket& packet,void *data,int size){
    int ret=0;
    switch(size)
    {
        case sizeof(uint8_t):
            ret=packet.UnPackUint8((uint8_t*)data);
        case sizeof(uint16_t):
            ret=packet.UnPackUint16((uint16_t*)data);
        case sizeof(uint32_t):
            ret=packet.UnPackUint32((uint32_t*)data);
        case sizeof(uint64_t):
            ret=packet.UnPackUint64((uint64_t*)data);
    }
    return ret;
}

int _UnPackInt(TPacket& packet,void *data,int size){
    int ret=0;
    switch(size)
    {
        case sizeof(int8_t):
            ret=packet.UnPackInt8((int8_t*)data);
        case sizeof(int16_t):
            ret=packet.UnPackInt16((int16_t*)data);
        case sizeof(int32_t):
            ret=packet.UnPackInt32((int32_t*)data);
			printf("<<<<<<<<<<%d>>>>>>>>>>>>\n", ret);
        case sizeof(int64_t):
           ret=packet.UnPackInt64((int64_t*)data);
    }
    return ret;
}

int _UnPackFloat(TPacket& packet,void *data,int size){
    int ret=0;
    switch(size)
    {
        case sizeof(float):
            ret=packet.UnPackFloat((float*)data);
        case sizeof(double):
            ret=packet.UnPackDouble((double*)data);
    }
    return ret;
}

int _UnPackStr(TPacket& packet,void *buffer){
   return packet.UnPackStr((char*)buffer);
}

//编辑器相关

EDITORSYNCAPI void EditorBeginPack(){
    EditorDataStream.Prepare(PACK);
}
EDITORSYNCAPI void EditorBeginUnPack(){
    EditorDataStream.Prepare(UNPACK);
}

EDITORSYNCAPI void EditorPackInt(void *data,int size){
    _PackInt(EditorDataStream,data,size);
}

EDITORSYNCAPI void EditorPackUint(void *data,int size){
    _PackUint(EditorDataStream,data,size);
}

EDITORSYNCAPI void EditorPackFloat(void *data,int size){
    _PackFloat(EditorDataStream,data,size);
}

EDITORSYNCAPI void EditorPackStr(const char* value){
    _PackStr(EditorDataStream, value);
}

EDITORSYNCAPI int EditorUnPackInt(void *data,int size)
{
    assert(data);
    return _UnPackInt(EditorDataStream,data,size);
}

EDITORSYNCAPI int EditorUnPackUint(void *data,int size)
{
    assert(data);
    return _UnPackUint(EditorDataStream,data,size);
}

EDITORSYNCAPI int EditorUnPackFloat(void *data,int size)
{
    assert(data);
    return _UnPackFloat(EditorDataStream,data,size);
}

EDITORSYNCAPI int EditorUnPackStr(void *buffer)
{
    assert(buffer);
    return _UnPackStr(EditorDataStream,buffer);
}

//引擎相关
EDITORSYNCAPI void EngineBeginPack(){
    EngineDataStream.Prepare(PACK);
}

EDITORSYNCAPI void EngineBeginUnPack(){
    EngineDataStream.Prepare(UNPACK);
}

EDITORSYNCAPI void EnginePackInt(void *data,int size){
    _PackInt(EngineDataStream,data,size);
}

EDITORSYNCAPI void EnginePackUint(void *data,int size){
    _PackUint(EngineDataStream,data,size);
}

EDITORSYNCAPI void EnginePackFloat(void *data,int size){
    _PackFloat(EngineDataStream,data,size);
}

EDITORSYNCAPI void EnginePackStr(const char* value){
    _PackStr(EngineDataStream, value);
}

EDITORSYNCAPI int EngineUnPackInt(void *data,int size)
{
    assert(data);
    return _UnPackInt(EngineDataStream,data,size);
}

EDITORSYNCAPI int EngineUnPackUint(void *data,int size)
{
    assert(data);
    return _UnPackUint(EngineDataStream,data,size);
}

EDITORSYNCAPI int EngineUnPackFloat(void *data,int size)
{
    assert(data);
    return _UnPackFloat(EngineDataStream,data,size);
}

EDITORSYNCAPI int EngineUnPackStr(void *buffer)
{
    assert(buffer);
    return _UnPackStr(EngineDataStream,buffer);
}

#ifdef __cplusplus
}
#endif
