QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data_struct/data_struct.cpp \
    data_struct/global_data.cpp \
    dialog/configure_dialog.cpp \
    dialog/mail_dialog.cpp \
    get_sys_info/get_sys_info.cpp \
    main.cpp \
    utils/dealtConfigFile.cpp \
    utils/pop3.cpp \
    utils/threads.cpp \
    widget/widget.cpp \
    widget/widget_ConfigFile.cpp \
    widget/widget_Content.cpp \
    widget/widget_Ending.cpp \
    widget/widget_EventFunc.cpp \
    widget/widget_Initial.cpp \
    widget/widget_RightContextMenu.cpp \
    widget/widget_UIAndPaintEvent.cpp \
    widget/widget_WindowPositionStyle.cpp

HEADERS += \
    header/configure_dialog.h \
    header/data_struct.h \
    header/define.h \
    header/get_sys_info.h \
    header/widget.h \ \
    interface/plugins_interface.h \
    header/mail_dialog.h \
    utils/dealtConfigFile.h \
    utils/pop3.h \
    utils/threads.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/mail.svg

RESOURCES += \
    res/clock.qrc \
    res/mail.qrc

FORMS += \
    configure_dialog.ui \
    mail_dialog.ui
