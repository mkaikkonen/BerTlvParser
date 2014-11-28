#include "tlvdeviceidentity.h"

TlvDeviceIdentity::TlvDeviceIdentity(vector<unsigned char> tlvData) :
    Tlv( "Device Identity", tlvData )
{
}
