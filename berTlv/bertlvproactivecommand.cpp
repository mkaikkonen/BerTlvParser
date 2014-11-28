#include "bertlvproactivecommand.h"

BerTlvProactiveCommand::BerTlvProactiveCommand(unsigned char tag,
    unsigned char length, vector<unsigned char> &data) :
    BerTlv("Proactive Command", tag, length, data)
{
}
