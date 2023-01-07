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

    model: shopModel

    delegate: ColumnLayout {
      width: listview.width
      height: 55

      RowLayout {
        Layout.fillWidth: true
        spacing: 15

        Text {
          text: model.name + "\n" + model.weight.toFixed(2) + "kg\n" + Number(
                  model.price / 100).toLocaleCurrencyString(Qt.locale("pl_PL"))

          Layout.fillWidth: true
        }

        RoundButton {
          text: "\u2795"
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
