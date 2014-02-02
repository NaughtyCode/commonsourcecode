#ifndef TPACKET_H
#define TPACKET_H

#include <msgpack.hpp>
#include "TMutex.h"
#include <string.h>
#include <windows.h>

#define PACKETBUFFERSIZE 1024*1024

class TMutex;

enum TPacketType {
    None=0,
    PACK=1,
    UNPACK=2,
};

class TPacket
{
public:
    TPacket();
    ~TPacket();
    
	void Prepare(TPacketType type);
    void PackUint8(const   uint8_t  value);
    void PackUint16(const  uint16_t value);
    void PackUint32(const  uint32_t value);
    void PackUint64(const  uint64_t value);
    void PackInt8(const    int8_t   value);
    void PackInt16(const   int16_t  value);
    void PackInt32(const   int32_t  value);
    void PackInt64(const   int64_t  value);
    void PackFloat(const   float    value);
    void PackDouble(const  double   value);
    void PackStr(const     char*    value);
    
    int UnPackUint8(uint8_t* data);
    int UnPackUint16(uint16_t* data);
    int UnPackUint32(uint32_t* data);
    int UnPackUint64(uint64_t* data);
    int UnPackInt8(int8_t* data);
    int UnPackInt16(int16_t* data);
    int UnPackInt32(int32_t* data);
    int UnPackInt64(int64_t* data);
    int UnPackFloat(float* data);
    int UnPackDouble(double* data);
    int UnPackStr(char* buffer);
    
private:
    msgpack::sbuffer  packbuffer;
    msgpack::unpacker unpackbuffer;
    msgpack::unpacked packet;
    msgpack::object   object;
    TMutex            locker;
};

#endif