import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
  id: listScreen
  anchors.fill: parent
  anchors.margins: 5

  ListView {
    id: listview
    anchors.fill: parent

    model: 6

    //    delegate: Rectangle {
    //      width: parent.width
    //      height: 45

    //      border.color: "grey"
    //      border.width: 2
    //      radius: 2

    //      Text {
    //        anchors.centerIn: parent
    //        text: "Poszła" + "\n" + "ola"
    //      }

    //      Button {
    //        anchors.right: parent.right
    //        text: qsTr("Dodaj")
    //      }
    //    }
    delegate: ColumnLayout {
      width: listview.width
      height: 55

      RowLayout {
        Layout.fillWidth: true
        spacing: 15

        Text {
          //color: "#fff"
          //background: Item {}
          // render data from model
          text: "TEST" //model.content
          Layout.fillWidth: true
        }

        RoundButton {
          text: "ADD" //"\u2796" // unicode heavy minus sign
          // remove this element from model
          onClicked: todoModel.remove(model.index)
          height: parent.height
        }
      }
      Rectangle {
        color: "#666"
        height: 1
        Layout.fillWidth: true
      }
    }
  }
}
