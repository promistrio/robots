import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id: instruments
        width: 80
        height: parent.height
        anchors.left: parent.left
        color: "#BBBBBB"
        z:5

        Column{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            Label{
                text: "Стена:"
            }

            Rectangle{
                width: 50
                height: 50
                color: "black"
            }
            Label{
                text: "Робот:"
            }
            Rectangle{
                width: 50
                height: 50
                color: "green"
            }
        }

        Column{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            spacing: 5

            Label{
                text: "Текущий:"
            }

            Rectangle{
                width: 50
                height: 50
                color: "black"
            }
            Label{
                text: "  " // Медленно опускаете глаза ниже незамечая этот костыль
            }
        }


    }

    Field{
        anchors.left: instruments.right
        width: parent.width - instruments.width
        height: parent.height
        z:0
    }




}
