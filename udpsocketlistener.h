#ifndef UDPSOCKETLISTENER_H
#define UDPSOCKETLISTENER_H

#include <QObject>
#include "udppacket.h"

class QUdpSocket;
class QNetworkDatagram;

class UdpSocketListener : public QObject {
    Q_OBJECT
private:
    QUdpSocket* socket;
    QNetworkDatagram* datagram;

public:
    explicit UdpSocketListener(QObject *parent = nullptr);
    ~UdpSocketListener();

signals:
    void dataReceived(UdpPacket);

public slots:
    void dataReceivedSlot();
};

#endif // UDPSOCKETLISTENER_H
