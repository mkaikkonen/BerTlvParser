#ifndef TLV_H
#define TLV_H

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "tlvelement.h"

using namespace std;

class Tlv
{
public:
    Tlv();
    Tlv(vector<unsigned char> &tlvdata);
    Tlv(string name, vector<unsigned char> &tlvdata);
    bool Validate(string &output);
    bool Decode(string &output, unsigned char indent);
    bool Encode();
    string Name(){ return " " + _name + "\n"; }
protected:
    string _name;

private:
    unsigned char _tag;
    unsigned char _length;
    vector<unsigned char> _data;
    vector<TlvElement*> _elements;
};

#endif // TLV_H
