#ifndef TLVUNIDENTIFIED_H
#define TLVUNIDENTIFIED_H

#include <vector>
#include "tlv.h"

class TlvUnidentified : public Tlv
{
public:
    TlvUnidentified();
    TlvUnidentified(std::vector<unsigned char> tlvdata);
};

#endif // TLVUNIDENTIFIED_H
