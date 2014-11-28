#include "bertlvfactory.h"

BerTlv* BerTlvFactory::GetBerTlv(vector<unsigned char> &data){

    BerTlv *bt;
    vector<unsigned char> tlvdata;

    // Copy the TLV data to new vector
    tlvdata.insert(tlvdata.begin(), data.begin() + 2, data.end());

    switch(data.at(0)){
        case ProactiveCommand:
            bt = dynamic_cast<BerTlv*>(new BerTlvProactiveCommand(data.at(0), data.at(1), tlvdata));
        break;
        default:
            bt = dynamic_cast<BerTlv*>(new BerTlvUnidentified(data.at(0), data.at(1), tlvdata));
        break;
    }

    return bt;
}
