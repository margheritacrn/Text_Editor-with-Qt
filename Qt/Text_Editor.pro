QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    search_dialog.cpp \
    text_editor.cpp

HEADERS += \
    search_dialog.h \
    text_editor.h

FORMS += \
    search_dialog.ui \
    text_editor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

SUBDIRS += \
    ../../../Users/asus/Desktop/QT_MERD/save_as_dialog/save_as_dialog.pro \
    save_as_dialog.pro
