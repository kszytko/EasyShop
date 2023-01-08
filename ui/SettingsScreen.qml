import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Item {
  id: settingsScreen
  anchors.fill: parent
  anchors.margins: 10

  Row {
    id: settingsRow
    width: parent.width
    height: 30
    spacing: 30

    Text {
      text: qsTr("Server IP:")
      font.bold: true

      width: 50
      height: 30
      topPadding: 5
    }

    Rectangle {
      id: rec
      border.color: "black"
      border.width: 1
      radius: 5
      width: 200
      height: 30

      TextInput {
        id: serverAdress
        text: shopController.adress
        anchors.fill: parent
        anchors.margins: 5

        onTextEdited: {
          shopController.setShopListInfo("")
        }

        onEditingFinished: {
          shopController.setAdress(serverAdress.text)
        }
      }
    }

    RoundButton {
      id: connectButton
      text: qsTr("Connect")
      width: 100
      height: 30
      onClicked: {
        shopController.refreshShopList()
      }
    }
  }

  Text {
    id: status
    text: shopController.shopListInfo
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: settingsRow.bottom
    anchors.topMargin: 20
  }
}
