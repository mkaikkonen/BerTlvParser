#include "tlvfactory.h"

enum TlvTypes{
    CommandDetails = 0x81,
    DeviceIdentity = 0x82
};

TlvFactory::TlvFactory()
{

}

Tlv* TlvFactory::getTlv(vector<unsigned char> &tlvData){

    Tlv* tlv;

    switch(tlvData.at(0)){
        case CommandDetails:
            tlv = new TlvCommandDetails(tlvData);
            break;
        case DeviceIdentity:
            tlv = new TlvDeviceIdentity(tlvData);
            break;
        // Todo add more Tlv's
        default:
            tlv = new TlvUnidentified(tlvData);
            break;
    }

    return tlv;
}
