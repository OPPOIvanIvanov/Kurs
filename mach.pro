QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_m.cpp \
    edit_us.cpp \
    flights.cpp \
    kas_m.cpp \
    main.cpp \
    mainwindow.cpp \
    reg.cpp \
    user_m.cpp \
    users_db.cpp

HEADERS += \
    admin_m.h \
    edit_us.h \
    flights.h \
    kas_m.h \
    mainwindow.h \
    reg.h \
    user_m.h \
    users_db.h

FORMS += \
    admin_m.ui \
    edit_us.ui \
    flights.ui \
    kas_m.ui \
    mainwindow.ui \
    reg.ui \
    user_m.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
