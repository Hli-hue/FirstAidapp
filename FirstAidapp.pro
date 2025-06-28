QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QT += sql network multimedia positioning multimediawidgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FirstAid.cpp \
    aedlocator.cpp \
    emergencyguide.cpp \
    emergencymodel.cpp \
    heartratepage.cpp \
    kits.cpp \
    knowledgepage.cpp \
    learningmenu.cpp \
    main.cpp \
    mypage.cpp \
    respirationratepage.cpp \
    search.cpp \
    searchengine.cpp \
    symptomcheckdialog.cpp \
    widget.cpp

HEADERS += \
    FirstAid.h \
    aedlocator.h \
    emergencyguide.h \
    emergencymodel.h \
    heartratepage.h \
    kits.h \
    knowledgepage.h \
    learningmenu.h \
    mypage.h \
    respirationratepage.h \
    search.h \
    searchengine.h \
    symptomcheckdialog.h \
    widget.h

FORMS += \
    FirstAid.ui \
    kits.ui \
    knowledgepage.ui \
    learningmenu.ui \
    mypage.ui \
    search.ui \
    widget.ui

TRANSLATIONS += \
    FirstAidapp_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    res.qrc
