#include "udpsocketlistener.h"
#include <QUdpSocket>
#include <QNetworkDatagram>
#include "udppacket.h"



UdpSocketListener::UdpSocketListener(QObject *parent) : QObject(parent) {

    socket = new QUdpSocket();
    socket->bind(QHostAddress::Any, 1026);
    datagram = new QNetworkDatagram();

    connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceivedSlot()));
}

UdpSocketListener::~UdpSocketListener() {
    delete socket;
}

void UdpSocketListener::dataReceivedSlot() {
    *datagram = socket->receiveDatagram();
    char* data = datagram->data().data();
    struct UdpPacket packet;
    std::copy(data, data+64, (char*)packet.sensor);
    packet.destinationAddress = datagram->destinationAddress();
    packet.destinationPort = datagram->destinationPort();
    packet.senderAddress = datagram->senderAddress();
    packet.senderPort = datagram->senderPort();
    emit dataReceived(packet);
}

