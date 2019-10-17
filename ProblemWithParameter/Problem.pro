#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T16:18:45
#
#-------------------------------------------------

QT       -= gui

TARGET = Problem
TEMPLATE = lib

DEFINES += PROBLEM_LIBRARY \
    SHARED_EXPORTS

SOURCES += \
    Problem.cpp

HEADERS += \
    error.h \
    Problem.h \
    IProblem.h \
    SHARED_EXPORT.h \
    ILog.h \
    IVector.h \
    IBrocker.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE373E6FC
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Problem.dll
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

LIBS += \
    "$$PWD/ILog.dll" \
    "$$PWD/math.dll"

QMAKE_CXXFLAGS += -std=gnu++0x







