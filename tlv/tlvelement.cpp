#include "tlvelement.h"

bool TlvElement::Decode(string &output, unsigned char indent){

    for( unsigned char i = 0; i < indent; ++i){
        output.append(1, ' ');
    }

    output.append(_name + "(");

    for(vector<unsigned char>::const_iterator i = _value.begin();
        i != _value.end(); ++i ){
        output.append(1, *i);
        output.append(" ");
    }
    output.append(")");

    return true;
}
