import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import "ui"

ApplicationWindow {
  id: root
  width: 450
  height: 480
  visible: true
  title: qsTr("Shop")

  header: ToolBar {
    id: toolBar

    RowLayout {
      anchors.fill: parent

      ToolButton {
        text: qsTr("Product list")
        icon.source: "qrc:/ui/icons/list.png"
        onClicked: pageLoader.source = "ui/ShopScreen.qml"
      }

      NewToolSeparator {}

      ToolButton {
        id: basketToolButton
        text: qsTr("Basket")
        icon.source: "qrc:/ui/icons/basket.png"
        onClicked: pageLoader.source = "ui/BasketScreen.qml"
      }

      Item {
        Layout.fillWidth: true
      }

      ToolButton {
        icon.source: "qrc:/ui/icons/options.png"
        onClicked: pageLoader.source = "ui/SettingsScreen.qml"
      }
    }
  }

  Rectangle {
    anchors.top: toolBar.bottom
    anchors.fill: parent

    Loader {
      id: pageLoader
      anchors.fill: parent
      source: "./ui/ShopScreen.qml"
    }
  }
}
