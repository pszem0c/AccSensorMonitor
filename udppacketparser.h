#ifndef UDPPACKETPARSER_H
#define UDPPACKETPARSER_H

#include <QObject>
#include "udppacket.h"
#include "sensorpacket.h"

class UdpPacketParser : public QObject {
    Q_OBJECT
private:
    static qint16 revertLsbMsb(quint16 val);

public:
    explicit UdpPacketParser(QObject *parent = nullptr);

signals:
    void dataParsed(SensorPacket);

public slots:
    void parseData(UdpPacket packet);
};

#endif // UDPPACKETPARSER_H
