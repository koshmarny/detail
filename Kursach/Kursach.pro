QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accounts.cpp \
    adminpanel.cpp \
    createproduct.cpp \
    dispatcherpanel.cpp \
    main.cpp \
    mainwindow.cpp \
    profiledlg.cpp \
    storage.cpp \
    supplierpanel.cpp

HEADERS += \
    accounts.h \
    adminpanel.h \
    createproduct.h \
    dispatcherpanel.h \
    mainwindow.h \
    profiledlg.h \
    storage.h \
    supplierpanel.h

FORMS += \
    accounts.ui \
    adminpanel.ui \
    createproduct.ui \
    dispatcherpanel.ui \
    mainwindow.ui \
    profiledlg.ui \
    storage.ui \
    supplierpanel.ui

TRANSLATIONS += \
    Kursach_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
