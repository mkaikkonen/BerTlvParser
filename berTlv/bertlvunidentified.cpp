#include "bertlvunidentified.h"

BerTlvUnidentified::BerTlvUnidentified(unsigned char tag,
    unsigned char length, vector<unsigned char> &data) :
    BerTlv("Unidentified TLV", tag, length, data)
{
}
