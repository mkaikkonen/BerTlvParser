import QtQuick 2.3
import QtQuick.Controls 1.2
import BerTlvParser 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    color: "#ffff00"
    title: qsTr("SIM Toolkit command parser")

    BerTlvParser{
        id: berTlvParser;
        name: "Mika";
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Save")
                onTriggered: console.log("Save action triggered");
            }
            MenuItem {
                text: qsTr("Save As...")
                onTriggered: console.log("Save As... action triggered");
            }

            MenuSeparator { }

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&Help")
            MenuItem {
                text: qsTr("Contents")
                onTriggered: console.log("Contents action triggered");
            }

            MenuSeparator { }

            MenuItem {
                text: qsTr("&About SIM Toolkit Command Parser")
                onTriggered: console.log("About... action triggered");
            }
        }
    }



    TextInput {
        x: 20
        width: 513
        height: 20
        anchors.top: parent.top
        anchors.topMargin: 32
        id: textInputBerTlv
        color: "#606552"
        text: "0xD0,0x09,0x81,0x03,0x01,0x01,0x03,0x82,0x02,0x81,0x82"
        clip: false
        font.pixelSize: 12
    }

    Text {
        id: textOutput
        height: 346
        text: qsTr("")
        styleColor: "#d41919"
        font.family: "Courier"
        font.pixelSize: 12
        anchors.top: buttonParse.bottom
        anchors.topMargin: 16
        anchors.right: parent.right
        anchors.rightMargin: 23
        anchors.left: parent.left
        anchors.leftMargin: 20
        Connections{
            target: berTlvParser;
            onTlvDecoded: textOutput.text += decodedData;
        }
    }

    Button {
        id: buttonParse
        y: 29
        height: 23
        text: "Parse"
        anchors.right: parent.right
        anchors.rightMargin: 23
        anchors.left: textInputBerTlv.right
        anchors.leftMargin: 12
        onClicked: berTlvParser.decode(textInputBerTlv.text);
    }

    Text {
        id: textStatus
        x: 18
        width: 597
        text: qsTr("")
        textFormat: Text.RichText
        anchors.top: textOutput.bottom
        anchors.topMargin: 18
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 11
        font.pixelSize: 12
        Connections{
            target: berTlvParser;
            onTlvStatus: {
                textStatus.text = statusString;
                if( status ) {
                    textStatus.color = "red";
                }
            }
        }
    }

    Text {
        id: textInputLabel
        x: 20
        y: 5
        text: qsTr("Insert hex string (0x8B, 0x12...)")
        font.pixelSize: 12
    }
}
