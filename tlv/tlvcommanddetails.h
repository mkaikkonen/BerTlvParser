#ifndef TLVCOMMANDDETAILS_H
#define TLVCOMMANDDETAILS_H

#include "tlv.h"

class TlvCommandDetails : public Tlv
{
public:
    TlvCommandDetails();
    TlvCommandDetails(vector<unsigned char> &tlvdata);
};

#endif // TLVCOMMANDDETAILS_H
