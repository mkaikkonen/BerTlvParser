#include "tlv.h"

Tlv::Tlv():
    _name(""), _tag(0x00), _length(0x00)
{
}

Tlv::Tlv(vector<unsigned char> &tlvdata) :
    _name("Tlv"), _tag(tlvdata.at(0)), _length(tlvdata.at(1))
{
    _data.insert(_data.begin(), tlvdata.begin() + 2, tlvdata.end());
}

Tlv::Tlv(string name, vector<unsigned char> &tlvdata) :
     _name(name), _tag(tlvdata.at(0)), _length(tlvdata.at(1))
{
    _data.insert(_data.begin(), tlvdata.begin() + 2, tlvdata.end());
}

bool Tlv::Decode(string &output, unsigned char indent){

    TlvElement* tmpTlvElement;
    char tmpBuf[100];
    char* tmp;

    for( unsigned char i = 0; i < indent; ++i){
        output.append(1, ' ');
    }

    sprintf(tmpBuf, "%X", _tag);
    output.append(tmpBuf);
    output.append(" ");
    output.append(_name);
    output.append("\r\n");
    indent++;

    for( unsigned char i = 0; i < indent; ++i){
        output.append(1, ' ');
    }

    sprintf(tmpBuf, "%d", _length);
    output.append(tmpBuf);
    output.append(" Length, Data:");
    tmp = tmpBuf;
    for(unsigned char i = 0; i < _length; ++i){
        tmp = tmp + sprintf(tmp, "%02X ", _data.at(i));
    }

    output.append(tmpBuf);
    output.append("\r\n");
    indent++;

    for(vector<TlvElement*>::const_iterator i = _elements.begin();
        i != _elements.end(); ++i ){
        tmpTlvElement = static_cast<TlvElement*>(*i);
        tmpTlvElement->Decode(output, indent + 1);
    }

    return true;
}
