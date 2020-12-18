QT += quick multimedia

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp \
        src/RootContext.cpp \
        src/ControlModel.cpp \
        src/PlaylistModel.cpp \
        src/PlaylistItem.cpp \
        src/SongInfoReaderThread.cpp

HEADERS += \
        src/RootContext.h \
        src/ControlModel.h \
        src/PlaylistModel.h \
        src/PlaylistItem.h \
        src/SongInfoReaderThread.h \

RESOURCES += \
        resources/qml.qrc

INCLUDEPATH += \
        /home/yzvihunov/libs/taglib-1.11.1/out/usr/local/include/taglib

LIBS += \
    -L"/home/yzvihunov/libs/taglib-1.11.1/out/usr/local/lib" \
    -ltag \
    -lz \

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
