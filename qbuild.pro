# Copyright (c) 2011 Radek Polak

TEMPLATE=app

# The binary name
TARGET=qphysics

# This app uses Qtopia
CONFIG+=qtopia

DEFINES+=QTOPIA

QT += svg


INC = $$shellQuote($$path(,project))

INCLUDEPATH += $$INC/src \
    $$INC/src/Box2D \
	$$INC/src/Box2D/Dynamics \
	$$INC/src/Box2D/Dynamics/Joints \
	$$INC/src/Box2D/Dynamics/Contacts \
	$$INC/src/Box2D/Collision \
	$$INC/src/Box2D/Collision/Shapes \
	$$INC/src/Box2D/Common \


# Input
HEADERS += src/Box2D/Collision/b2BroadPhase.h \
    src/Box2D/Collision/b2Collision.h \
    src/Box2D/Collision/b2Distance.h \
    src/Box2D/Collision/b2DynamicTree.h \
    src/Box2D/Collision/b2TimeOfImpact.h \
    src/Box2D/Common/b2BlockAllocator.h \
    src/Box2D/Common/b2Math.h \
    src/Box2D/Common/b2Settings.h \
    src/Box2D/Common/b2StackAllocator.h \
    src/Box2D/Dynamics/b2Body.h \
    src/Box2D/Dynamics/b2ContactManager.h \
    src/Box2D/Dynamics/b2Fixture.h \
    src/Box2D/Dynamics/b2Island.h \
    src/Box2D/Dynamics/b2TimeStep.h \
    src/Box2D/Dynamics/b2World.h \
    src/Box2D/Collision/Shapes/b2CircleShape.h \
    src/Box2D/Collision/Shapes/b2PolygonShape.h \
    src/Box2D/Collision/Shapes/b2Shape.h \
    src/Box2D/Dynamics/Contacts/b2CircleContact.h \
    src/Box2D/Dynamics/Contacts/b2Contact.h \
    src/Box2D/Dynamics/Contacts/b2ContactSolver.h \
    src/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    src/Box2D/Dynamics/Contacts/b2PolygonContact.h \
    src/Box2D/Dynamics/Contacts/b2TOISolver.h \
    src/Box2D/Dynamics/Joints/b2DistanceJoint.h \
    src/Box2D/Dynamics/Joints/b2FrictionJoint.h \
    src/Box2D/Dynamics/Joints/b2GearJoint.h \
    src/Box2D/Dynamics/Joints/b2Joint.h \
    src/Box2D/Dynamics/Joints/b2LineJoint.h \
    src/Box2D/Dynamics/Joints/b2MouseJoint.h \
    src/Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    src/Box2D/Dynamics/Joints/b2PulleyJoint.h \
    src/Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    src/Box2D/Dynamics/Joints/b2WeldJoint.h
SOURCES += src/Box2D/Collision/b2BroadPhase.cpp \
    src/Box2D/Collision/b2CollideCircle.cpp \
    src/Box2D/Collision/b2CollidePolygon.cpp \
    src/Box2D/Collision/b2Collision.cpp \
    src/Box2D/Collision/b2Distance.cpp \
    src/Box2D/Collision/b2DynamicTree.cpp \
    src/Box2D/Collision/b2TimeOfImpact.cpp \
    src/Box2D/Common/b2BlockAllocator.cpp \
    src/Box2D/Common/b2Math.cpp \
    src/Box2D/Common/b2Settings.cpp \
    src/Box2D/Common/b2StackAllocator.cpp \
    src/Box2D/Dynamics/b2Body.cpp \
    src/Box2D/Dynamics/b2ContactManager.cpp \
    src/Box2D/Dynamics/b2Fixture.cpp \
    src/Box2D/Dynamics/b2Island.cpp \
    src/Box2D/Dynamics/b2World.cpp \
    src/Box2D/Dynamics/b2WorldCallbacks.cpp \
    src/Box2D/Collision/Shapes/b2CircleShape.cpp \
    src/Box2D/Collision/Shapes/b2PolygonShape.cpp \
    src/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    src/Box2D/Dynamics/Contacts/b2Contact.cpp \
    src/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    src/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    src/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    src/Box2D/Dynamics/Contacts/b2TOISolver.cpp \
    src/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    src/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    src/Box2D/Dynamics/Joints/b2GearJoint.cpp \
    src/Box2D/Dynamics/Joints/b2Joint.cpp \
    src/Box2D/Dynamics/Joints/b2LineJoint.cpp \
    src/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    src/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    src/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    src/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    src/Box2D/Dynamics/Joints/b2WeldJoint.cpp


SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/physicsitem.cpp \
    src/world.cpp \
    src/simulator.cpp \
    src/scenemanager.cpp \
    src/boltitem.cpp \
    src/revelutejoint.cpp \
    src/rectitem.cpp \
    src/material.cpp \
    src/welditem.cpp \
    src/grounditem.cpp \
    src/propertieseditor.cpp \
    src/itemfactory.cpp \
    src/itemeditor.cpp \
    src/physicsitemexample.cpp \
    src/circleitem.cpp

HEADERS += src/mainwindow.h \
    src/physicsitem.h \
    src/defs.h \
    src/world.h \
    src/simulator.h \
    src/scenemanager.h \
    src/boltitem.h \
    src/revelutejoint.h \
    src/rectitem.h \
    src/material.h \
    src/welditem.h \
    src/grounditem.h \
    src/propertieseditor.h \
    src/itemfactory.h \
    src/itemeditor.h \
    src/physicsitemexample.h \
    src/circleitem.h

FORMS += src/mainwindow.ui \
    src/propertieseditor.ui


pkg [
    name=qphysics
    desc="qphysics"
    version=$$QTOPIA_VERSION
    license=$$QTOPIA_LICENSE
    maintainer=$$QTOPIA_MAINTAINER
]

target [
    hint=sxe
    domain=trusted
]

desktop [
    hint=desktop
    files=qphysics.desktop
    path=/apps/Games
]

pics [
    hint=pics
    files=qphysics.svg
    path=/pics/qphysics
]
