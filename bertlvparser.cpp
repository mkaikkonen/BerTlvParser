// Class header inclusion
#include "bertlvparser.h"

// Local definitions
struct mapDecToVal{
    unsigned char Dec;
    unsigned char Value;
};

mapDecToVal lookUpTable[] = {
    {48, 0x00},
    {49, 0x01},
    {50, 0x02},
    {51, 0x03},
    {52, 0x04},
    {53, 0x05},
    {54, 0x06},
    {55, 0x07},
    {56, 0x08},
    {57, 0x09},
    {65, 0x0A},
    {66, 0x0B},
    {67, 0x0C},
    {68, 0x0D},
    {69, 0x0E},
    {70, 0x0F}
};

// Class declaration
BerTlvParser::BerTlvParser(QObject * parent)
    : QObject(parent){

}

void BerTlvParser::buttonClicked(const QString &in){
    qDebug() << in;
}

unsigned char BerTlvParser::lookup(char digit){
    for(unsigned char i = 0; i < (sizeof(lookUpTable)/sizeof(mapDecToVal)); i++){
        if( digit == lookUpTable[i].Dec ){
            return(lookUpTable[i].Value );
        }
    }
    qDebug() << "Decode: failure in conversion" << digit;
    return(-1);
}

void BerTlvParser::decode(const QString &in){
    QString out;
    BerTlvFactory factory;
    vector<unsigned char> byteVector;
    BerTlv* br;
    string output;

    qDebug() << "BerTlvParser::decode: " << in;

    // Validations
    if( false == validate(in) )
        return;

    simplify(in, out);

    emit tlvDecoded("BerTlv\r\n");

    // Convert to byte array
    convertToByteVector(out, byteVector);

    // Create BerTlv
    br = factory.GetBerTlv(byteVector);

    // Decode the BerTlv
    emit tlvStatus("Parsing...\r\n", 0);
    br->Parse();

    emit tlvStatus("Decoding...\r\n", 0);
    br->Decode(output, 1);

    emit tlvDecoded(QString::fromStdString(output));
    emit tlvStatus("Decoded succesfully!", 0);

    delete br;
}

bool BerTlvParser::validate(const QString &in){

    // Size
    if( in.size() == 0){
        emit tlvStatus("Empty string", 1);
        return false;
    }

    // Check bad characters
    //QRegularExpression re("/[0-9A-F]+/");

    //if(!tmpIn.contains( re )){
    //    emit tlvStatus("Bad characters", 1);
    //    return;
    //}

    return true;
}

void BerTlvParser::simplify(const QString &in, QString &out){
    // Convert to uppercase
    out = in.toUpper();
    qDebug() << "Simplify (toUpper): " << out;

    // Remove whitespace from start and end and multiple instances from middle
    out = out.simplified();
    qDebug() << "Simplify (simplified): " << out;

    // Remove dashes
    out = out.remove(QChar(','));
    qDebug() << "Simplify (remove dashes): " << out;

    // Remove rest of the whitespace
    out = out.remove(QChar(' '));
    qDebug() << "Simplify (remove whitespace): " << out;

    // Remove "0X"
    if( out.indexOf(QString("0X") < 0 )){
        out = out.remove(QString("0X"));
    }
    qDebug() << "Simplify (remove 0X): " << out;

    // Remove rest of the whitespace
    out = out.remove(QChar(' '));

    qDebug() << "Simplify (rest of whitespace): " << out;

    // Emit the whole data
    emit tlvDecoded(out.toLocal8Bit().constData());
    emit tlvDecoded("\r\n");
}

void BerTlvParser::convertToByteVector(const QString &in, vector<unsigned char> &myVector){

    //vector<unsigned char>* myvector = new vector<unsigned char>();
    unsigned char converted_byte;

    char one_digit;
    const char* pTemp;

    // Handle each character pair and convert to byte vector
    pTemp = in.toLocal8Bit().constData();

    for (int i = 0; i < in.size(); i += 2){
        // Get the hexadecimal value
        one_digit = *pTemp;

        // Convert character and and shift it to right position
        converted_byte = lookup(one_digit);
        converted_byte = converted_byte << 4;

        // Get the lower nibble
        one_digit = *(pTemp + 1);

        // Convert character
        converted_byte |= lookup(one_digit);

        // push final byte to vector
        myVector.push_back(converted_byte);

        // Move to next character pair
        pTemp += 2;
    }

    // Print vector
    for(std::vector<unsigned char>::const_iterator i = myVector.begin();
        i != myVector.end(); ++i ){
        qDebug() << "Vector: " << *i << ", ";
    }

    //for(  c: myvector)
    // std::for_each(
    //            myvector.begin(),
    //            myvector.end(),
    //            [](const unsigned char c){qDebug() << "Vector: " << c << ' ';}
    //            );

    //return myVector;
}
