#ifndef BERTLVPROACTIVECOMMAND_H
#define BERTLVPROACTIVECOMMAND_H

//=================================
// included dependencies
#include "bertlv.h"
#include "bertlvname.h"

class BerTlvProactiveCommand : public BerTlv
{
public:
    BerTlvProactiveCommand();
    BerTlvProactiveCommand(unsigned char tag,
        unsigned char length,
        vector<unsigned char> &data);
    ~BerTlvProactiveCommand(){}
};

#endif // BERTLVPROACTIVECOMMAND_H
