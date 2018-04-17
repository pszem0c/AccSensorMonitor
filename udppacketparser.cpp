#include "udppacketparser.h"

#include <QDebug>

UdpPacketParser::UdpPacketParser(QObject *parent) : QObject(parent) {

}

qint16 UdpPacketParser::revertLsbMsb(quint16 val) {
    return ((val & 0xFF00) >> 8) | ((val & 0xFF) << 8);
}

void UdpPacketParser::parseData(UdpPacket packet) {
    struct SensorPacket sensorPacket;
    //std::transform(packet.sensor, packet.sensor+32, sensorPacket.sensor, revertLsbMsb);
    std::copy(packet.sensor, packet.sensor+32, sensorPacket.sensor);
    sensorPacket.destinationAddress = packet.destinationAddress.toIPv4Address();
    sensorPacket.destinationPort = packet.destinationPort;
    sensorPacket.senderAddress = packet.senderAddress.toIPv4Address();
    sensorPacket.senderPort = packet.senderPort;
    emit dataParsed(sensorPacket);
}
