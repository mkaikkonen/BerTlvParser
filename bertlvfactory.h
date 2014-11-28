#ifndef BERTLVFACTORY_H
#define BERTLVFACTORY_H

#include "berTlv/bertlv.h"
#include "berTlv/bertlvunidentified.h"
#include "berTlv/bertlvproactivecommand.h"

using namespace std;

// Local data type
//
enum BerTlvTypes{
    ProactiveCommand = 0xD0
};

// Actual class
//
class BerTlvFactory
{
public:
    BerTlvFactory(){}
    BerTlv* GetBerTlv(vector<unsigned char> &data);
};

#endif // BERTLVFACTORY_H
