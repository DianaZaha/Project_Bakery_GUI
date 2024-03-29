QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Action.cpp \
    Controller.cpp \
    FileRepo.cpp \
    FilteringCriteria.cpp \
    Pastry.cpp \
    Repo.cpp \
    RepoExceptions.cpp \
    SortingCriteria.cpp \
    Tests.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Action.h \
    Controller.h \
    FileRepo.h \
    FilteringCriteria.h \
    Pastry.h \
    Repo.h \
    SortingCriteria.h \
    Tests.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BakeryInfo.csv \
    teste.csv
