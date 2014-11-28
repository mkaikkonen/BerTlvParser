#include "tlvcommanddetails.h"

TlvCommandDetails::TlvCommandDetails(vector<unsigned char> &tlvData) :
    Tlv( tlvData )
{
    _name = "Command Details";
}
