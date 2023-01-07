import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Row {
  id: settingsScreen
  anchors.fill: parent
  anchors.margins: 5
  spacing: 30

  Text {
    text: "<b>Server IP:<b>"
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
    }
  }

  RoundButton {
    text: "Reload"
    width: 100
    height: 30
    onClicked: {
      shopController.setAdress(serverAdress.text)
      console.log(shopController.adress)
    }
  }
}
