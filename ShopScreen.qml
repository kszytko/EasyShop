import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
  id: listScreen
  anchors.fill: parent
  anchors.margins: 5

  ListView {
    id: listview
    anchors.fill: parent

    model: shopModel

    delegate: ColumnLayout {
      width: listview.width
      height: 55

      RowLayout {
        Layout.fillWidth: true
        spacing: 15

        Text {
          text: model.name
          font.bold: true
          color: "green"

          Layout.preferredWidth: 100
          Layout.maximumWidth: 150
        }

        Text {
          text: model.weight.toFixed(2) + qsTr("kg")
          Layout.preferredWidth: 100
          Layout.maximumWidth: 150
        }

        Text {
          text: Number(model.price / 100).toLocaleCurrencyString(
                  Qt.locale("pl_PL"))
          color: "red"

          Layout.preferredWidth: 100
          Layout.maximumWidth: 150
        }

        Item {
          Layout.fillWidth: true
        }

        RoundButton {
          text: qsTr("\u2795")
          Layout.rightMargin: 10
          onClicked: {
            shopController.addToBasket(model.index)
          }
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
