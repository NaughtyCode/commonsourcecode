#include "TPacket.h"

#include <cassert>
#include <cstdlib>
#include <cstdio>

TPacket::TPacket():packbuffer(PACKETBUFFERSIZE),unpackbuffer(PACKETBUFFERSIZE),locker(){
    
}

TPacket::~TPacket(){
    
}

void TPacket::PackUint8(const  uint8_t  value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackUint16(const  uint16_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackUint32(const  uint32_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackUint64(const  uint64_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackInt8(const  int8_t  value){
    
}

void TPacket::PackInt16(const  int16_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackInt32(const  int32_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackInt64(const  int64_t value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackFloat( const  float  value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackDouble(const  double value){
    msgpack::pack(packbuffer, value);
}

void TPacket::PackStr(const char* value){
    std::string str(value);
    msgpack::pack(packbuffer,str);
}

int TPacket::UnPackUint8(uint8_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(uint8_t*)&object.via.u64;
    return 1;
}

int TPacket::UnPackUint16(uint16_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(uint16_t*)&object.via.u64;
    return 1;
}

int TPacket::UnPackUint32(uint32_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(uint32_t*)&object.via.u64;
    return 1;
}

int TPacket::UnPackUint64(uint64_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=object.via.u64;
    return 1;
}

int TPacket::UnPackInt8(int8_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(int8_t*)&object.via.i64;
    return 1;
}

int TPacket::UnPackInt16(int16_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(int16_t*)&object.via.i64;
    return 1;
}

int TPacket::UnPackInt32(int32_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(int32_t*)&object.via.i64;
    return 1;
}

int TPacket::UnPackInt64(int64_t* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(int64_t*)&object.via.i64;
    return 1;
}

int TPacket::UnPackFloat(float* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(float*)&object.via.dec;
    return 1;
}

int TPacket::UnPackDouble(double* data){
    unpackbuffer.next(&packet);
    object = packet.get();
    if (object.is_nil())return 0;
    *data=*(double*)&object.via.dec;
    return 1;
}

int TPacket::UnPackStr(char* buffer){
    unpackbuffer.next(&packet);
    object = packet.get();
    if(object.via.raw.ptr){
        std::string str(object.via.raw.ptr);
        int size = str.size();
        assert(size+1<=PACKETBUFFERSIZE);
        memcpy(buffer,str.c_str(),size);
        buffer[size+1]=0;
        return 1;
    }
    return 0;
}

void TPacket::Prepare(TPacketType type){
    locker.Lock();
    switch (type)
    {
        case PACK:
            memset(packbuffer.data(),0,packbuffer.size());
            break;
        case UNPACK:
            printf("数据长度%d\n",packbuffer.size());
            memcpy(unpackbuffer.buffer(), packbuffer.data(), packbuffer.size());
            break;
        default:
            printf("类型错误%d\n",type);
            assert(0);
            break;
    }
    locker.UnLock();
}
