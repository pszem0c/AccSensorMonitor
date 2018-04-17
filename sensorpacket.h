#ifndef SENSORPACKET_H
#define SENSORPACKET_H

#include <QtGlobal>

struct  SensorPacket {
    qint16  sensor[32];
    quint32 destinationAddress;
    qint32  destinationPort;
    quint32 senderAddress;
    qint32  senderPort;
};

#endif // SENSORPACKET_H
