#ifndef BERTLVUNIDENTIFIED_H
#define BERTLVUNIDENTIFIED_H

#include <vector>
#include "bertlv.h"

using namespace std;

class BerTlvUnidentified : public BerTlv
{
public:
    BerTlvUnidentified(){}
    BerTlvUnidentified(unsigned char tag,
        unsigned char length, vector<unsigned char> &data);
};

#endif // BERTLVUNIDENTIFIED_H
