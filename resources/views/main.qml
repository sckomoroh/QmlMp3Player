import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ControlComponent {
        id: controlComponent
        height: 80

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            topMargin: 10
            leftMargin: 10
            rightMargin: 10
        }

        context: rootContext.controlModel
    }


    PlaylistComponent {
        id: playlistComponent
        anchors {
            left: parent.left
            right: parent.right
            top: controlComponent.bottom
            bottom: parent.bottom
            topMargin: 10
            bottomMargin: 10
            leftMargin: 10
            rightMargin: 10
        }

        context: rootContext.playlistModel
    }

    Connections {
        target: rootContext.controlModel
        onCurrentIndexChanged: function(index) {
            console.log("Current index:" + index)
            playlistComponent.setCurrentIndex(index)
        }
    }
}
