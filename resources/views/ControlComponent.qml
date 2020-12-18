import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: element
    property var context

    Rectangle {
        anchors.fill: parent
        border {
            width: 1
            color: "black"
        }
    }

    Slider {
        id: positionSlider
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            leftMargin: 5
            rightMargin: 5
        }

        onValueChanged: context.onPositionChanged(value)
    }

    ImageButton {
        id: muteButton
        imageSource: "qrc:/imgs/mute.png"

        anchors {
            top: positionSlider.bottom
            left: parent.left
            topMargin: 5
            leftMargin: 5
        }

        checkable: true
        onClicked: context.onMuteClicked(checked)
    }

    Slider {
        id: volumeSlider
        anchors {
            left: muteButton.right
            leftMargin: 5
            verticalCenter: muteButton.verticalCenter
        }

        from: 0
        to: 100

        onValueChanged: context.onVolumeChanged(value)
    }

    ImageButton {
        id: backwardButton
        imageSource: "qrc:/imgs/backward.png"

        anchors {
            top: positionSlider.bottom
            topMargin: 5
            rightMargin: 5
            right: playButton.left
        }

        onClicked: context.onBackwardClicked()
    }

    ImageButton {
        id: playButton
        imageSource: "qrc:/imgs/play.png"

        anchors {
            top: positionSlider.bottom
            topMargin: 5
            rightMargin: 5
            right: stopButton.left
        }

        onClicked: context.onPlayClicked()
    }

    ImageButton {
        id: stopButton
        imageSource: "qrc:/imgs/stop.png"

        anchors {
            top: positionSlider.bottom
            topMargin: 5
            rightMargin: 5
            right: forwardButton.left
        }

        onClicked: context.onStopClicked()
    }

    ImageButton {
        id: forwardButton
        imageSource: "qrc:/imgs/forward.png"

        anchors {
            top: positionSlider.bottom
            topMargin: 5
            rightMargin: 15
            right: shuffleButton.left
        }

        onClicked: context.onForwardClicked()
    }

    ImageButton {
        id: shuffleButton
        imageSource: "qrc:/imgs/shuffle.png"

        anchors {
            top: positionSlider.bottom
            topMargin: 5
            rightMargin: 5
            right: repeatButton.left
        }

        checkable: true
        onClicked: context.onShuffleClicked(checked)
    }

    ImageButton {
        id: repeatButton
        imageSource: "qrc:/imgs/repeat.png"

        anchors {
            top: positionSlider.bottom
            right: parent.right
            topMargin: 5
            rightMargin: 5
        }

        checkable: true
        onClicked: context.onRepeatClicked(checked)
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
