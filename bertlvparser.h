//=================================
// include guard
#ifndef TLVPARSER_H
#define TLVPARSER_H

//=================================
// included dependencies
#include <QObject>
#include <QDebug>
#include <cctype>
#include <QRegularExpression>
#include "bertlvfactory.h"
#include "berTlv/bertlv.h"

using namespace std;

class BerTlvParser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString tlv READ tlv WRITE setTlv NOTIFY tlvDecoded)

public:
    explicit BerTlvParser(QObject * parent = 0);
    QString name() const { return _name; }
    void setName(const QString &name) { _name = name; }

    QString tlv() const { return _tlv; }
    void setTlv(const QString &tlv) { _tlv = tlv; }

private:
    unsigned char lookup(char digit);
    bool validate(const QString &in);
    void simplify(const QString &in, QString &out);
    void convertToByteVector(const QString &in, vector<unsigned char> &myVector );

public slots:
    // This method needs to take either a QString or a const reference to one.
    // (QML doesn't support returning values via the parameter list.)
    void buttonClicked(const QString& in);
    void decode(const QString &in);
signals:
    void tlvStatus(const QString statusString, unsigned char status);
    void tlvDecoded(const QString decodedData);

private:
    QString _name;
    QString _tlv;
};

#endif // TLVPARSER_H
