TEMPLATE = lib
CONFIG += debug \
    staticlib \
    warn_off



DESTDIR = ../../bin
CONFIG -= release \
    warn_on
    
    
INCLUDEPATH += Dynamics \
Dynamics/Joints \
Dynamics/Contacts \
Collision \
Collision/Shapes \
Common \



# Input
HEADERS += Collision/b2BroadPhase.h \
    Collision/b2Collision.h \
    Collision/b2Distance.h \
    Collision/b2DynamicTree.h \
    Collision/b2TimeOfImpact.h \
    Common/b2BlockAllocator.h \
    Common/b2Math.h \
    Common/b2Settings.h \
    Common/b2StackAllocator.h \
    Dynamics/b2Body.h \
    Dynamics/b2ContactManager.h \
    Dynamics/b2Fixture.h \
    Dynamics/b2Island.h \
    Dynamics/b2TimeStep.h \
    Dynamics/b2World.h \
    Dynamics/b2WorldCallbacks.h \
    Collision/Shapes/b2CircleShape.h \
    Collision/Shapes/b2PolygonShape.h \
    Collision/Shapes/b2Shape.h \
    Dynamics/Contacts/b2CircleContact.h \
    Dynamics/Contacts/b2Contact.h \
    Dynamics/Contacts/b2ContactSolver.h \
    Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Dynamics/Contacts/b2PolygonContact.h \
    Dynamics/Contacts/b2TOISolver.h \
    Dynamics/Joints/b2DistanceJoint.h \
    Dynamics/Joints/b2FrictionJoint.h \
    Dynamics/Joints/b2GearJoint.h \
    Dynamics/Joints/b2Joint.h \
    Dynamics/Joints/b2LineJoint.h \
    Dynamics/Joints/b2MouseJoint.h \
    Dynamics/Joints/b2PrismaticJoint.h \
    Dynamics/Joints/b2PulleyJoint.h \
    Dynamics/Joints/b2RevoluteJoint.h \
    Dynamics/Joints/b2WeldJoint.h \
    B2D.h
SOURCES += Collision/b2BroadPhase.cpp \
    Collision/b2CollideCircle.cpp \
    Collision/b2CollidePolygon.cpp \
    Collision/b2Collision.cpp \
    Collision/b2Distance.cpp \
    Collision/b2DynamicTree.cpp \
    Collision/b2TimeOfImpact.cpp \
    Common/b2BlockAllocator.cpp \
    Common/b2Math.cpp \
    Common/b2Settings.cpp \
    Common/b2StackAllocator.cpp \
    Dynamics/b2Body.cpp \
    Dynamics/b2ContactManager.cpp \
    Dynamics/b2Fixture.cpp \
    Dynamics/b2Island.cpp \
    Dynamics/b2World.cpp \
    Dynamics/b2WorldCallbacks.cpp \
    Collision/Shapes/b2CircleShape.cpp \
    Collision/Shapes/b2PolygonShape.cpp \
    Dynamics/Contacts/b2CircleContact.cpp \
    Dynamics/Contacts/b2Contact.cpp \
    Dynamics/Contacts/b2ContactSolver.cpp \
    Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Dynamics/Contacts/b2PolygonContact.cpp \
    Dynamics/Contacts/b2TOISolver.cpp \
    Dynamics/Joints/b2DistanceJoint.cpp \
    Dynamics/Joints/b2FrictionJoint.cpp \
    Dynamics/Joints/b2GearJoint.cpp \
    Dynamics/Joints/b2Joint.cpp \
    Dynamics/Joints/b2LineJoint.cpp \
    Dynamics/Joints/b2MouseJoint.cpp \
    Dynamics/Joints/b2PrismaticJoint.cpp \
    Dynamics/Joints/b2PulleyJoint.cpp \
    Dynamics/Joints/b2RevoluteJoint.cpp \
    Dynamics/Joints/b2WeldJoint.cpp
