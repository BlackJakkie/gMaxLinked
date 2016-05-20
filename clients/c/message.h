#ifndef _message_h_
#define _message_h_

#include "size.h"

////////////////////////////////////
// type values in THeader
////////////////////////////////////
const unsigned short MT_CONTROL = 0x0001;
const unsigned short MT_ACCOUNT = 0x0002;
const unsigned short MT_SERVICE = 0x0003;

const unsigned short MT_SIGN_ACK = 0x0010;
const unsigned short MT_SIGN_LOG = 0x0020;
const unsigned short MT_SIGN_FEE = 0x0040;

////////////////////////////////////
// cmd values in THeader
////////////////////////////////////
// network messages: 0xXXXX except 0x8XXX
const unsigned short MC_HAND_SHAKE = 0x0001;
const unsigned short MC_HEART_BEAT = 0x0002;

// internal messages: 0x8XXX
const unsigned short MC_ON_TIMER = 0x8001;
const unsigned short MC_ON_OVER = 0x8002;

////////////////////////////////////
// lang values in THeader
////////////////////////////////////
const unsigned char ML_CN = 0x01;
const unsigned char ML_TW = 0x02;
const unsigned char ML_EN = 0x03;

////////////////////////////////////
// PDUs
////////////////////////////////////
#pragma pack(1)

struct THeader {
    unsigned short size;
    unsigned short type;
    unsigned short cmd;
    unsigned short ver;
    unsigned char lang;
    unsigned int seq;
    unsigned long int stmp;
    unsigned long int ext;
};

struct TAck {
    unsigned short code;
};

struct TPDUHandShake {
    struct THeader header;
    unsigned int build;
    char sessionId[SIZE_SESSION_ID];
};

struct TPDUHandShakeAck {
    struct THeader header;
    struct TAck ack;
};

struct TPDUHeartBeat {
    struct THeader header;
};

struct TPDUHeartBeatAck {
    struct THeader header;
    struct TAck ack;
};

struct TPDUOnTimer {
    struct THeader header;
    unsigned long int timerId;
    unsigned long int parameter;
};

struct TPUDOnOver {
    struct THeader header;
    int reason;
};

#pragma pack()

#endif // _message_h_