TARGET = QPhysics
QT += opengl

DESTDIR = ../bin
# LIBS += -lbox2d
INCLUDEPATH += Box2D \
    Box2D/Dynamics \
    Box2D/Dynamics/Joints \
    Box2D/Dynamics/Contacts \
    Box2D/Collision \
    Box2D/Collision/Shapes \
    Box2D/Common
LIBS += ../bin/libBox2D.a
TARGETDEPS += ../bin/libBox2D.a
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    physicsitem.cpp \
    world.cpp \
    simulator.cpp \
    scenemanager.cpp \
    boltitem.cpp \
    revelutejoint.cpp \
    rectitem.cpp \
    material.cpp \
    welditem.cpp \
    grounditem.cpp \
    propertieseditor.cpp \
    itemfactory.cpp \
    itemeditor.cpp \
    physicsitemexample.cpp \
    circleitem.cpp
HEADERS += mainwindow.h \
    physicsitem.h \
    defs.h \
    world.h \
    simulator.h \
    scenemanager.h \
    boltitem.h \
    revelutejoint.h \
    rectitem.h \
    material.h \
    welditem.h \
    grounditem.h \
    propertieseditor.h \
    itemfactory.h \
    itemeditor.h \
    physicsitemexample.h \
    circleitem.h
FORMS += mainwindow.ui \
    propertieseditor.ui
