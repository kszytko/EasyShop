import QtQuick 2.6
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

ApplicationWindow {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  header: ToolBar {
    id: toolBar

    RowLayout {
      anchors.fill: parent

      ToolButton {
        text: qsTr("Lista produktów")
        icon.source: "qrc:/list.png"
        onClicked: pageLoader.source = "ShopScreen.qml"
      }

      NewToolSeparator {}

      ToolButton {
        text: qsTr("Koszyk zakupów")
        icon.source: "qrc:/basket.png"
        onClicked: pageLoader.source = "BasketScreen.qml"
      }

      Item {
        Layout.fillWidth: true
      }

      ToolButton {
        //text: qsTr("Opcje")
        icon.source: "qrc:/options.png"
        onClicked: pageLoader.source = "SettingsScreen.qml"
      }
    }
  }

  Rectangle {
    anchors.top: toolBar.bottom
    anchors.fill: parent

    Loader {
      id: pageLoader
      anchors.fill: parent
      source: "./ShopScreen.qml"
    }
  }
}
