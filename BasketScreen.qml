import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
  id: basketScreen
  anchors.fill: parent
  anchors.margins: 5

  ListView {
    id: basketView
    anchors.fill: parent

    model: basketModel

    delegate: ColumnLayout {
      width: basketView.width
      height: 55

      RowLayout {
        Layout.fillWidth: true
        spacing: 15

        Text {
          text: model.name
          Layout.fillWidth: true
          Layout.maximumWidth: 80
        }

        Text {
          text: model.amount
          Layout.fillWidth: true
          Layout.maximumWidth: 80
        }

        Text {
          text: model.price
          Layout.fillWidth: true
          Layout.maximumWidth: 80
        }

        Text {
          text: model.price * model.amount
          Layout.fillWidth: true
          Layout.maximumWidth: 80
        }

        RoundButton {
          text: "DELETE"
          onClicked: {
            shopController.removeFromBasket(model.index)
            fullPriceText.text = shopController.getFullPrice()
          }
          height: parent.height
        }
      }
      Rectangle {
        color: "#666"
        height: 1
        Layout.fillWidth: true
      }
    }

    header: RowLayout {
      Layout.fillWidth: true
      spacing: 15

      Text {
        text: "Name"
        Layout.fillWidth: true
        Layout.minimumWidth: 80
      }

      Text {
        text: "Amount"
        Layout.fillWidth: true
        Layout.minimumWidth: 80
      }

      Text {
        text: "Price"
        Layout.fillWidth: true
        Layout.minimumWidth: 80
      }

      Text {
        text: "Full Price"
        Layout.fillWidth: true
        Layout.minimumWidth: 80
      }

      Text {
        text: ""
        Layout.fillWidth: true
        Layout.minimumWidth: 80
      }
    }
  }

  RowLayout {
    anchors.bottom: parent.bottom
    width: parent.width
    spacing: 50

    Text {
      id: fullPriceText
      text: shopController.getFullPrice()
      Layout.margins: 40
    }

    RoundButton {
      text: "BUY"
      onClicked: {
        shopController.buy()
        fullPriceText.text = shopController.getFullPrice()
      }
      height: parent.height
      Layout.margins: 40
    }
  }
}
