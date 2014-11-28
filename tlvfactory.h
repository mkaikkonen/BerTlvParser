#ifndef TLVFACTORY_H
#define TLVFACTORY_H

#include <vector>
#include "tlv/tlv.h"
#include "tlv/tlvunidentified.h"
#include "tlv/tlvcommanddetails.h"
#include "tlv/tlvdeviceidentity.h"

using namespace std;
class TlvFactory
{
public:
    TlvFactory();
    Tlv* getTlv(vector<unsigned char> &tlvdata);
private:
};

#endif // TLVFACTORY_H
