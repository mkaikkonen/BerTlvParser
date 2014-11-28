//=================================
// include guard
#ifndef BERTLV_H
#define BERTLV_H

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <vector>
#include <string>
#include "tlv/tlv.h"
#include "tlvfactory.h"
#include "berTlv/bertlvname.h"
#include "stdio.h"

using namespace std;

//=================================
// the actual class
class BerTlv
{
public:
    BerTlv() : _tag(0x00), _length(0x00) {}
    BerTlv(string name, unsigned char tag, unsigned char length, vector<unsigned char> &tlvData);
    BerTlv(vector<unsigned char> data);
    BerTlv(const BerTlv &berTlv);
    bool Validate(void);
    virtual bool Parse(void);
    virtual bool Decode(string &output, unsigned char indent);
    virtual bool Encode(vector<unsigned char> data);
    string Name(void){ return _name; }
    BerTlv& operator=(const BerTlv & berTlv);
    bool operator==(const BerTlv & berTlv);
    virtual ~BerTlv(){}

protected:
    vector<Tlv*> _tlvList;
    string _name;
    unsigned char _tag;
    unsigned int _length;
    vector<unsigned char> _data;
};

#endif // BERTLV_H
