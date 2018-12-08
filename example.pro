#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T11:54:17
#
#-------------------------------------------------

QT       -= gui
QT       += xml

TARGET = example
TEMPLATE = lib
DESTDIR = ../

DEFINES += EXAMPLE_LIBRARY
#uncomment next line to disable mutexes
#DEFINES += QT_NO_DEBUG

SOURCES += exampleplugin.cpp 

HEADERS += exampleplugin.h\
        example_global.h \
        ../../../include/ihwbrokerplugin.h 

INCLUDEPATH += ../../../include/
INCLUDEPATH += ../../../icore/

#LIBS += -L../../../lib/ftdi \
#        -lftd2xx \
#        -lklen 
