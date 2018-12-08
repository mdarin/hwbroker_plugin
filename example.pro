#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T11:54:17
#
#-------------------------------------------------

#QT       -= gui
QT += xml

DESTDIR = ..
TARGET = example
TEMPLATE = lib

DEFINES += EXAMPLE_LIBRARY

INCLUDEPATH += ../../../include/
INCLUDEPATH += ../../../icore/
INCLUDEPATH += ../../../imitator_plugins/hardware/

SOURCES += exampleplugin.cpp 

HEADERS += exampleplugin.h \
        example_global.h \
        ihardwarewrapper.h \
    ../../../imitator_plugins/hardware/hardwareimitator.h


DEFINES += __x86__
win32 {
    INCLUDEPATH += $$(OMNIORB_BASE)/include/
    DEFINES += __WIN32__ \
        WIN32 \
        _WIN32_WINNT=0x0400 \
        __NT__ \
        __OSVERSION__=4
    CONFIG(debug, debug|release) {
        LIBS += -L$$(OMNIORB_BASE)/lib/x86_win32 \
            -lomniDynamic4_rtd \
            -lomniORB4_rtd \
            -lomnithread_rtd
    } else {
    LIBS += -L$$(OMNIORB_BASE)/lib/x86_win32 \
            -lomniDynamic4_rt \
            -lomniORB4_rt \
            -lomnithread_rt
    }
    LIBS +=../../../lib/orbhelper1.lib
    LIBS +=../../../lib/icore.lib
    LIBS +=../../../imitator_plugins/hardware.lib
    MOC_DIR = _moc
    OBJECTS_DIR = _obj
}

unix {
    DEFINES += __OS_VERSION__=2 \
        __linux__
    OMNIBASE = /usr/local
    INCLUDEPATH += /usr/include/omniORB4 \
        /usr/include/COS
    LIBS += -L../../lib \
        -lomniDynamic4 \
        -lomniORB4 \
        -lomnithread
    LIBS += -L../../../lib/ -lorbhelper -licore
    LINS += -L../../../imitator_plugins/ -lhardware
    MOC_DIR = .moc
    OBJECTS_DIR = .obj
}

