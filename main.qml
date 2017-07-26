import QtQuick.Window 2.2
import QtQuick 2.5
import QtQuick.Controls 1.4

Window {
    visible: true

    width: 600
    height: 420
    minimumHeight: 420
    minimumWidth: 600

    color: "#42d9f4"

    Rectangle {
        id: mainForm

        anchors.fill: parent
        anchors.margins: 10
        anchors.rightMargin: 190

        Rectangle {
            id: oner
            //objectName: "00"
            width: 120
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10

            color: {
               // if (areaOne.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }

            Image{
                id: one
                anchors.fill: parent
                objectName: "00"
            }

            MouseArea {
                id: areaOne
                anchors.fill: parent
                hoverEnabled: true
                objectName: "1"
                onClicked: {
                    moveService.humanMove(one.objectName)
                    one.source = "qrc:/img/x.png"
                    enabled = false;
                   // parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: twor
            //objectName: "01"
            width: 120
            height: 120
            anchors.left: oner.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10

            color: {
               // if (areaTwo.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            Image{
                id: two
                anchors.fill: parent
                objectName: "01"
            }
            MouseArea {
                id: areaTwo
                anchors.fill: parent
                hoverEnabled: true
                objectName: "2"
                onClicked: {
                    moveService.humanMove(two.objectName)
                    two.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: threer
            //objectName: "02"
            width: 120
            height: 120
            anchors.left: twor.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10

            color: {
               // if (areaThree.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            Image{
                id: three
                anchors.fill: parent
                objectName: "02"
            }
            MouseArea {
                id: areaThree
                anchors.fill: parent
                hoverEnabled: true
                objectName: "3"
                onClicked: {
                    moveService.humanMove(three.objectName)
                    three.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: fourr
            //objectName: "10"
            width: 120
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: oner.bottom
            anchors.topMargin: 10

            color: {
               // if (areaFour.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            Image{
                id: four
                anchors.fill: parent
                objectName: "10"
            }
            MouseArea {
                id: areaFour
                anchors.fill: parent
                hoverEnabled: true
                objectName: "4"
                onClicked: {
                    moveService.humanMove(four.objectName)
                    four.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: fiver
            //objectName: "11"
            width: 120
            height: 120
            anchors.left: fourr.right
            anchors.leftMargin: 10
            anchors.top: twor.bottom
            anchors.topMargin: 10

            color: {
                //if (areaFive.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            Image{
                id: five
                anchors.fill: parent
                objectName: "11"
            }
            MouseArea {
                id: areaFive
                anchors.fill: parent
                hoverEnabled: true
                objectName: "5"
                onClicked: {
                    moveService.humanMove(five.objectName)
                    five.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: sixr
            //objectName: "12"
            width: 120
            height: 120
            anchors.left: fiver.right
            anchors.leftMargin: 10
            anchors.top: threer.bottom
            anchors.topMargin: 10

            color: {
               // if (areaSix.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            Image{
                id: six
                anchors.fill: parent
                objectName: "12"
            }
            MouseArea {
                id: areaSix
                anchors.fill: parent
                hoverEnabled: true
                objectName: "6"
                onClicked: {
                    moveService.humanMove(six.objectName)
                    six.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: sevenr
            //objectName: "20"
            width: 120
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: fourr.bottom
            anchors.topMargin: 10

            color: {
                //if (areaSeven.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            Image{
                id: seven
                anchors.fill: parent
                objectName: "20"
            }
            MouseArea {
                id: areaSeven
                anchors.fill: parent
                hoverEnabled: true
                objectName: "7"
                onClicked: {
                    moveService.humanMove(seven.objectName)
                    seven.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: eightr
            //objectName: "21"
            width: 120
            height: 120
            anchors.left: sevenr.right
            anchors.leftMargin: 10
            anchors.top: fiver.bottom
            anchors.topMargin: 10

            color: {
                //if (areaEight.containsMouse)
                    //return "#000000"
                return "#ffffff"
            }
            Image{
                id: eight
                anchors.fill: parent
                objectName: "21"
            }
            MouseArea {
                id: areaEight
                anchors.fill: parent
                hoverEnabled: true
                objectName: "8"
                onClicked: {
                    moveService.humanMove(eight.objectName)
                    eight.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: niner
            //objectName: "22"
            width: 120
            height: 120
            anchors.left: eightr.right
            anchors.leftMargin: 10
            anchors.top: sixr.bottom
            anchors.topMargin: 10

            color: {
                //if (areaNine.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            Image{
                id: nine
                anchors.fill: parent
                objectName: "22"
            }
            MouseArea {
                id: areaNine
                anchors.fill: parent
                hoverEnabled: true
                objectName: "9"
                onClicked: {
                    moveService.humanMove(nine.objectName)
                    nine.source = "qrc:/img/x.png"
                    enabled = false;
                    //parent.color = "#429bf4"
                }
            }
        }

        color: "#cccccc"
    }

    Text {
        id: endGameText
        objectName: "endGameText"

        width: 100
        height: 60

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 30
        anchors.topMargin: 200

        font.bold: true
        font.pixelSize: 20
    }

    CustomButton {
        id: restart

        width: 100
        height: 40

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 30
        anchors.topMargin: 40

        text: "Restart"

        onClicked: {
            one.source = ""
            two.source = ""
            three.source = ""
            four.source = ""
            five.source = ""
            six.source = ""
            seven.source = ""
            eight.source = ""
            nine.source = ""

            endGameText.text = ""
            moveService.restart()
        }

        enabled: {
            one.source != ""
            || two.source != ""
            || three.source != ""
            || four.source != ""
            || five.source != ""
            || six.source != ""
            || seven.source != ""
            || eight.source != ""
            || nine.source != ""}
    }
}

