#ifndef UDPPACKET_H
#define UDPPACKET_H

#include <QtGlobal>
#include <QHostAddress>

struct UdpPacket{
    quint16         sensor[32];
    QHostAddress    destinationAddress;
    qint32          destinationPort;
    QHostAddress    senderAddress;
    qint32          senderPort;
};

#endif // UDPPACKET_H
