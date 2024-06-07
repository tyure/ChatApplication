QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatclient.cpp \
    chatroom.cpp \
    chatwindow.cpp \
    friend.cpp \
    friendlistwindow.cpp \
    groupchatdialog.cpp \
    groupchatwindow.cpp \
    main.cpp \
    chatapplication.cpp \
    mainwindow.cpp \
    message.cpp \
    registerform.cpp \
    user.cpp

HEADERS += \
    chatapplication.h \
    chatclient.h \
    chatroom.h \
    chatwindow.h \
    friend.h \
    friendlistwindow.h \
    groupchatdialog.h \
    groupchatwindow.h \
    mainwindow.h \
    message.h \
    registerform.h \
    user.h

FORMS += \
    chatapplication.ui \
    chatwindow.ui \
    friendlistwindow.ui \
    groupchatdialog.ui \
    groupchatwindow.ui \
    mainwindow.ui \
    registerform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
