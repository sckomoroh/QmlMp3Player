import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: rootComponent

    property var imageSource
    property var imageHeight: 16
    property var imageWidth: 16
    flat: true
    width:32
    height: 32

    Image {
        source: rootComponent.imageSource
        width: rootComponent.imageWidth
        height: rootComponent.imageHeight
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }
    }
}
