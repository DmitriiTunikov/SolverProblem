#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T15:03:39
#
#-------------------------------------------------

QT       -= gui

TARGET = Solver
TEMPLATE = lib

DEFINES += SOLVER_LIBRARY \
    SHARED_EXPORTS

SOURCES += solver.cpp

HEADERS +=\
    ISolver.h \
    IProblem.h \
    Solver.h \
    IVector.h \
    Vector.h \
    error.h \
    ILog.h \
    SHARED_EXPORT.h \
    Compact.h \
    ICompact.h \
    IBrocker.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE2DA66ED
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Solver.dll
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















