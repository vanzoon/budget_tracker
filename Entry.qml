import QtQuick 2.0


Rectangle {
    id: _entry

    property string budgetLine: budget_line.text
    property real cost: qsTr(cost.text)

    border.color: "black"
    border.width: 1
    radius: 2

    Text {
        id: budget_line
        text: qsTr("expenditure")
        anchors.left: left


        font {
            pointSize: _entry.height * 0.33
            italic: true
        }
    }
    Text {
        id: cost
        text: qsTr("text")
    }
}
