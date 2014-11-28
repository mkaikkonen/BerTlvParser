#ifndef TLVELEMENT_H
#define TLVELEMENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TlvElement
{
public:
    TlvElement(){}
    bool Decode(string &output, unsigned char indent);
private:
    string _name;
    vector<unsigned char> _value;
};

#endif // TLVELEMENT_H
