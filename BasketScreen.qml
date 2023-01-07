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
    id: footerTotal
    anchors.bottom: parent.bottom
    width: parent.width
    height: 50

    Text {
      id: fullPriceText
      text: qsTr("Total price: %1").arg(
              Number(basketModel.totalPrice / 100).toLocaleCurrencyString(
                Qt.locale("pl_PL")))
      Layout.alignment: Qt.AlignCenter
    }

    RoundButton {
      text: "BUY"
      implicitWidth: 100
      Layout.alignment: Qt.AlignCenter

      onClicked: {
        shopController.buy()
        popup.open()
      }
    }
  }

  Popup {
    id: popup
    anchors.centerIn: parent

    width: 200
    height: 200

    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

    background: Rectangle {
      anchors.fill: parent
      radius: 10
      border.width: 1
      border.color: "lightgrey"
    }

    ColumnLayout {
      anchors.fill: parent
      spacing: 10

      Text {
        text: "ORDER"
        Layout.alignment: Qt.AlignHCenter
      }

      Text {
        text: shopController.orderPrice === 0 ? "Error" : Number(
                                                  shopController.orderPrice
                                                  / 100).toLocaleCurrencyString(
                                                  Qt.locale("pl_PL"))
        Layout.alignment: Qt.AlignHCenter
      }

      RoundButton {
        text: "Close"
        Layout.alignment: Qt.AlignHCenter
        implicitWidth: 100
        onClicked: popup.close()
      }
    }
  }
}
