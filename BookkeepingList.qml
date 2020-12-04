import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import Bookkeeping.model 1.0

ColumnLayout {
    spacing: 2
    Frame {
//        height: parent.height
        height: 300
        width: 300

        background: Rectangle {
            color: "lightgreen"
            border.color: "black"
            radius: 5
        }
//        anchors.right: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter


        ListView {
            id: debit_credit

            height: parent.height
            width: parent.width

            model: BookkeepingModel_qml {}
            spacing: 4
            clip: true


            delegate: RowLayout {
                id: _entryDelegate
                //height: debit_credit.height
                width: debit_credit.width


                CheckBox {
                    checked: model.done
                    onClicked: {
                        model.done = checked
                    }
                }
                TextField {
                    text: model.description
                    Layout.fillWidth: true
                    onEditingFinished: {
                        model.description = text
                    }
                }
            }
        }

    }

    RowLayout {
        Button {
            text: qsTr("add new entry")
        }

        Button {
            text: qsTr("remove completed tasks")
        }

    }
}
