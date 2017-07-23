import QtQuick.Window 2.2
import QtQuick 2.5
import QtQuick.Controls 1.4

Window {
    visible: true

    width: 600
    height: 420
    minimumHeight: 420
    minimumWidth: 600

    Rectangle {
        id: mainForm

        anchors.fill: parent
        anchors.margins: 10
        anchors.rightMargin: 190

        Rectangle {
            id: one
            objectName: "00"
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

            MouseArea {
                id: areaOne
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: two
            objectName: "01"
            width: 120
            height: 120
            anchors.left: one.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10

            color: {
               // if (areaTwo.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaTwo
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: three
            objectName: "02"
            width: 120
            height: 120
            anchors.left: two.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10

            color: {
               // if (areaThree.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaThree
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: four
            objectName: "10"
            width: 120
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: one.bottom
            anchors.topMargin: 10

            color: {
               // if (areaFour.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaFour
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: five
            objectName: "11"
            width: 120
            height: 120
            anchors.left: four.right
            anchors.leftMargin: 10
            anchors.top: two.bottom
            anchors.topMargin: 10

            color: {
                //if (areaFive.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaFive
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: six
            objectName: "12"
            width: 120
            height: 120
            anchors.left: five.right
            anchors.leftMargin: 10
            anchors.top: three.bottom
            anchors.topMargin: 10

            color: {
               // if (areaSix.containsMouse)
                 //   return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaSix
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: seven
            objectName: "20"
            width: 120
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: four.bottom
            anchors.topMargin: 10

            color: {
                //if (areaSeven.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaSeven
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: eight
            objectName: "21"
            width: 120
            height: 120
            anchors.left: seven.right
            anchors.leftMargin: 10
            anchors.top: five.bottom
            anchors.topMargin: 10

            color: {
                //if (areaEight.containsMouse)
                    //return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaEight
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        Rectangle {
            id: nine
            objectName: "22"
            width: 120
            height: 120
            anchors.left: eight.right
            anchors.leftMargin: 10
            anchors.top: six.bottom
            anchors.topMargin: 10

            color: {
                //if (areaNine.containsMouse)
                  //  return "#000000"
                return "#ffffff"
            }
            MouseArea {
                id: areaNine
                anchors.fill: parent
                hoverEnabled: true

                onClicked: {
                    moveService.humanMove(parent.objectName)
                    parent.color = "#429bf4"
                }
            }
        }

        color: "#cccccc"
    }

    Button {
        id: restart

        width: 100
        height: 40

        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 30
        anchors.topMargin: 40

        text: "Restart"

        onClicked: {
            one.color = "#ffffff"
            two.color = "#ffffff"
            three.color = "#ffffff"
            four.color = "#ffffff"
            five.color = "#ffffff"
            six.color = "#ffffff"
            seven.color = "#ffffff"
            eight.color = "#ffffff"
            nine.color = "#ffffff"

            moveService.restart()
        }
    }
}

