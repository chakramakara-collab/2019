######################################################################
# Automatically generated by qmake (2.01a) ter Out 20 17:24:36 2015
######################################################################

TEMPLATE = app
TARGET = AudienceClient
DEPENDPATH += . ../config/
INCLUDEPATH += . ../config/ /usr/include/vtk-5.8/

# Input
HEADERS += ConfigXML.h FieldWidget3D.h mainwindow.h Param.h ../config/field.conf.hxx \
    Team.h
FORMS += mainwindow.ui
SOURCES += ConfigXML.cpp FieldWidget3D.cpp main.cpp mainwindow.cpp Param.cpp  ../config/field.conf.cxx

QT += network
LIBS += -lQVTK -lvtkRendering -lvtkGraphics -lvtkCommon -lvtkIO -lvtkFiltering -lvtkHybrid -lxerces-c -lqjson
