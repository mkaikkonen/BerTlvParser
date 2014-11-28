#ifndef TLVDEVICEIDENTITY_H
#define TLVDEVICEIDENTITY_H

#include "tlv.h"

class TlvDeviceIdentity : public Tlv
{
public:
    TlvDeviceIdentity();
    TlvDeviceIdentity(std::vector<unsigned char> tlvdata);
};

#endif // TLVDEVICEIDENTITY_H
