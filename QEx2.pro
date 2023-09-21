QT       += core gui network core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    ./headers \
    ./headers/windows \
    ./headers/pages \
    ./headers/Hash

SOURCES += \
    main.cpp \
    sources/Hash/htiger.cpp \
    sources/masterwindow.cpp \
    sources/mfileworker.cpp \
    sources/mlineedit.cpp \
    sources/mpushbutton.cpp \
    sources/pages/mfirstpage.cpp \
    sources/pages/minfopage.cpp \
    sources/pages/msecondpage.cpp \
    sources/solution.cpp \
    sources/user.cpp \
    sources/windows/mlobbywindow.cpp \
    sources/windows/mregisterwindow.cpp

HEADERS += \
    headers/Hash/htiger.h \
    headers/masterwindow.h \
    headers/mfileworker.h \
    headers/mlineedit.h \
    headers/mpushbutton.h \
    headers/pages/mfirstpage.h \
    headers/pages/minfopage.h \
    headers/pages/msecondpage.h \
    headers/solution.h \
    headers/user.h \
    headers/windows/mlobbywindow.h \
    headers/windows/mregisterwindow.h

FORMS += \
    forms/ThirdPage.ui \
    forms/mlobbywindow.ui \
    forms/registerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
