import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1

Item {
    id: playlistComponent

    property var context

    function setCurrentIndex(index) {
        playListView.currentIndex = index
    }

    Rectangle {
        anchors.fill: parent
        border {
            width: 1
            color: "black"
        }
    }

    Component {
        id: playlistItemDelegate

        Item {
            anchors {
                left: parent.left
                right: parent.right
            }

            height: 50

            Text {
                id: titleText
                anchors {
                    left: parent.left
                    top: parent.top
                    right: bitrateText.left
                    leftMargin: 5
                    topMargin: 5
                    rightMargin: 5
                }

                text: item.title
                font.bold: true
                elide: Text.ElideRight
            }

            Text {
                id: artistText

                anchors {
                    left: parent.left
                    top: titleText.bottom
                    leftMargin: 5
                    topMargin: 5
                }

                text: item.artist
            }

            Text {
                id: lengthText

                anchors {
                    top: parent.top
                    right: parent.right
                    topMargin: 5
                    rightMargin: 5
                }

                text: item.length
            }

            Text {
                id: bitrateText

                anchors {
                    top: lengthText.bottom
                    right: parent.right
                    topMargin: 5
                    rightMargin: 5
                }

                text: item.bitrate
            }

            Rectangle {
                anchors {
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                    leftMargin: 5
                    rightMargin: 5
                }

                height: 2
                color: "black"
            }


            MouseArea {
                anchors.fill: parent
                onDoubleClicked: context.onItemDoubleClicked(index)
            }
        }
    }

    ListView {
        id: playListView
        anchors {
            top: parent.top
            bottom: openFolderButton.top
            left: parent.left
            right: parent.right
            topMargin: 5
            bottomMargin: 5
            leftMargin: 5
            rightMargin: 5
        }

        model: context
        delegate: playlistItemDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
    }

    Button {
        id: openFolderButton

        anchors {
            left: parent.left
            bottom: parent.bottom
            leftMargin: 5
            bottomMargin: 5
        }

        onClicked: openFolderDialog.open()
        text: "Open folder"
    }

    Button {
        id: clearPlaylistButton

        anchors {
            right: parent.right
            bottom: parent.bottom
            rightMargin: 5
            bottomMargin: 5
        }

        onClicked: context.clearPlaylist()
        text: "Clear playlist"
    }

    FolderDialog {
        id: openFolderDialog
        onAccepted: {
            context.openFolder(openFolderDialog.folder)
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

