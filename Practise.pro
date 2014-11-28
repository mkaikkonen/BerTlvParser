TEMPLATE = app

QT += core qml quick widgets

SOURCES += main.cpp \
    berTlv/bertlv.cpp \
    berTlv/bertlvcellbroadcastdownload.cpp \
    berTlv/bertlveventdownload.cpp \    
    berTlv/bertlvmmstransfer.cpp \
    berTlv/bertlvname.cpp \
    berTlv/bertlvproactivecommand.cpp \
    berTlv/bertlvsmsppdownload.cpp \
    berTlv/bertlvtimerexpiration.cpp \
    berTlv/bertlvunidentified.cpp \
    berTlv/bertlvussddownload.cpp \
    tlv/tlv.cpp \
    tlv/tlvcommanddetails.cpp \
    tlv/tlvdeviceidentity.cpp \
    tlv/tlvelement.cpp \
    tlv/tlvresult.cpp \
    tlv/tlvunidentified.cpp \
    tlvfactory.cpp \
    bertlvfactory.cpp \
    bertlvparser.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    bertlv.h \
    bertlvproactivecommand.h \
    bertlvsmsppdownload.h \
    bertlvcellbroadcastdownload.h \
    bertlveventdownload.h \
    bertlvtimerexpiration.h \
    bertlvussddownload.h \
    bertlvmmstransfer.h \
    tlv.h \
    tlvcommanddetails.h \
    tlvdeviceidentity.h \
    tlvresult.h \
    bertlvfactory.h \
    tlvfactory.h \
    tlvunidentified.h \
    bertlvunidentified.h \
    bertlvname.h \
    tlvelement.h \
    berTlv/bertlv.h \
    berTlv/bertlvcellbroadcastdownload.h \
    berTlv/bertlveventdownload.h \
    berTlv/bertlvmmstransfer.h \
    berTlv/bertlvname.h \
    berTlv/bertlvproactivecommand.h \
    berTlv/bertlvsmsppdownload.h \
    berTlv/bertlvtimerexpiration.h \
    berTlv/bertlvunidentified.h \
    berTlv/bertlvussddownload.h \
    tlv/tlv.h \
    tlv/tlvcommanddetails.h \
    tlv/tlvdeviceidentity.h \
    tlv/tlvelement.h \
    tlv/tlvresult.h \
    tlv/tlvunidentified.h \
    bertlvparser.h

OTHER_FILES += \
    lineedit.png \
    lineedit.sci

