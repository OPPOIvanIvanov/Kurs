QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_m.cpp \
    edit_f.cpp \
    edit_us.cpp \
    flight_db.cpp \
    flights.cpp \
    k_sales.cpp \
    kas_m.cpp \
    list_pass.cpp \
    main.cpp \
    mainwindow.cpp \
    passengers.cpp \
    reg.cpp \
    us_flights.cpp \
    user_m.cpp \
    users_db.cpp

HEADERS += \
    admin_m.h \
    edit_f.h \
    edit_us.h \
    flight_db.h \
    flights.h \
    k_sales.h \
    kas_m.h \
    list_pass.h \
    mainwindow.h \
    passengers.h \
    reg.h \
    us_flights.h \
    user_m.h \
    users_db.h

FORMS += \
    admin_m.ui \
    edit_f.ui \
    edit_us.ui \
    flights.ui \
    k_sales.ui \
    kas_m.ui \
    list_pass.ui \
    mainwindow.ui \
    reg.ui \
    us_flights.ui \
    user_m.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
