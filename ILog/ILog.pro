#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T15:10:12
#
#-------------------------------------------------

QT       -= gui

TARGET = ILog
TEMPLATE = lib

DEFINES += ILOG_LIBRARY \
    SHARED_EXPORTS

SOURCES += ILog.cpp

HEADERS += ILog.h \
    error.h \
    SHARED_EXPORT.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2C9299C
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ILog.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

