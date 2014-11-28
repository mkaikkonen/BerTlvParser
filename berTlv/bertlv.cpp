// Class header inclusion
#include "bertlv.h"

// Class declaration
BerTlv::BerTlv(string name, unsigned char tag, unsigned char length, vector<unsigned char> &tlvData) :
    _name(name), _tag(tag), _length(length)
{
    _data.insert(_data.begin(), tlvData.begin(), tlvData.end());
}

BerTlv::BerTlv(const BerTlv &berTlv):
    _name(berTlv._name), _tag(berTlv._tag), _length(berTlv._length)
{
    _data.insert(_data.begin(), berTlv._data.begin(), berTlv._data.end());
}

BerTlv& BerTlv::operator=(const BerTlv &berTlv){
    // Check self assignment
    if( this != &berTlv ) {
        _name = berTlv._name;
        _tag = berTlv._tag;
        _length = berTlv._length;

        _data.insert(_data.begin(), berTlv._data.begin(), berTlv._data.end());
    }
    return *this;
}

bool BerTlv::operator==(const BerTlv & berTlv){
    if(_tag == berTlv._tag){
        return true;
    }
    return false;
}

bool BerTlv::Validate(void){
    if(_data.size() != _length){
        return false;
    }
    if(_data.size() % 2 != 0){
        return false;
    }

    return true;
}

bool BerTlv::Parse(void){
    vector<unsigned char> tmpTlv;

    // Validate Data
    // Identify TLV's and create list
    vector<unsigned char>::iterator i = _data.begin();

    // Get TLV length from index 1 and add tag and length
    unsigned char tlvLength = *(i + 1) + 2;

    TlvFactory tlvFactory;

    while(i != _data.end()){

        // Copy TLV data from BER TLV data
        tmpTlv.insert(tmpTlv.begin(), i, (i + tlvLength));

        // Construct TLV and store pointer to it
        _tlvList.push_back(tlvFactory.getTlv(tmpTlv));

        // Clear vector
        tmpTlv.clear();

        // move iterator to beginning of next tlv
        i += tlvLength;

        // Get length of next TLV
        tlvLength = *(i + 1) + 2;
    }

    // Go trough the TLV's
    // Return data using callback
    return true;
}

bool BerTlv::Decode(string &output, unsigned char indent){

    Tlv* tmpTlv;
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

    for(vector<Tlv*>::const_iterator i = _tlvList.begin();
        i != _tlvList.end(); ++i ){
        tmpTlv = static_cast<Tlv*>(*i);
        tmpTlv->Decode(output, indent);
    }

    return true;
}

bool BerTlv::Encode(std::vector<unsigned char> data)
{    
    // Go trough the TLV's and
    // Return new BerTlv data
    ( void )data;
    return true;
}
