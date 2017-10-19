import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property int x_count: fieldModel.columnCount()
    property int y_count: fieldModel.rowCount()
    property int size: 20
    property string src: ""
    Flickable{

        anchors.fill: parent
        contentWidth: cellGrid.width
        contentHeight: cellGrid.height

        /*ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
        ScrollBar.horizontal: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }*/
        Grid {
            id: cellGrid

            rows: y_count
            columns: x_count

            Repeater {
                id: repeater

                model: fieldModel

                Rectangle{
                    border.width: 1
                    border.color: "#888888"
                    color: "white"
                    width: size
                    height: size
                    z: 1

                    Label{
                        anchors.centerIn: parent
                        text: value
                    }

                    MouseArea{
                        id: column
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        onClicked: {
                            fieldModel.calculatePath(1,1,79, 39)
                            var x = index % x_count
                            var y = Math.floor( index / x_count)
                            console.log(x_count, y_count );
                            console.log(x, y, index);
                            if (mouse.button == Qt.RightButton){
                                robotsModel.addRobot(x,y)
                            }
                        }
                        z:1
                    }
                }
            }
        }

        Repeater{
            model: robotsModel
            delegate: Rectangle{
                x: posX * size
                y: posY * size
                color: robot_color
                border.color: "black"
                border.width: 1
                width: size
                height: size
                z: 2

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log(posX,posY, robot_color);
                    }
                    z:2
                }
                Behavior on x {
                    ParallelAnimation {
                        PropertyAnimation {
                            duration: 1001
                            easing.type: Easing.Linear
                        }
                    }
                }
            }
        }
    }
}
