import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
  id: basketScreen
  anchors.fill: parent
  anchors.margins: 5

  ListView {
    id: basketView
    width: parent.width
    height: parent.height - footer.height

    clip: true

    model: basketModel

    header: RowLayout {
      Layout.fillWidth: true
      spacing: 15

      Text {
        text: qsTr("Name")
        Layout.preferredWidth: 80
      }

      Text {
        text: qsTr("Amount")
        Layout.preferredWidth: 80
      }

      Text {
        text: qsTr("Price")
        Layout.preferredWidth: 80
      }

      Text {
        text: qsTr("Full Price")
        Layout.fillWidth: true
      }
    }

    delegate: ColumnLayout {
      width: basketView.width
      height: 55

      RowLayout {
        Layout.fillWidth: true
        spacing: 15

        Text {
          text: model.name
          Layout.preferredWidth: 80
        }

        Text {
          text: model.amount
          Layout.preferredWidth: 80
        }

        Text {
          text: Number(model.price / 100).toLocaleCurrencyString(
                  Qt.locale("pl_PL"))
          Layout.preferredWidth: 80
        }

        Text {
          text: Number(model.price * model.amount / 100).toLocaleCurrencyString(
                  Qt.locale("pl_PL"))
          Layout.fillWidth: true
        }

        RoundButton {
          text: qsTr("DELETE")
          height: parent.height
          onClicked: {
            shopController.removeFromBasket(model.index)
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

  RowLayout {
    id: footer
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
      text: qsTr("MAKE ORDER")
      Layout.preferredWidth: 100
      Layout.alignment: Qt.AlignCenter

      onClicked: {
        if (basketView.count > 0) {
          shopController.makeOrder()
          popup.open()
        }
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
        text: qsTr("ORDER")
        Layout.alignment: Qt.AlignHCenter
      }

      Text {
        text: shopController.orderInfo
        Layout.alignment: Qt.AlignHCenter
      }

      RoundButton {
        text: qsTr("OK")
        Layout.alignment: Qt.AlignHCenter
        implicitWidth: 100
        onClicked: popup.close()
      }
    }
  }
}
