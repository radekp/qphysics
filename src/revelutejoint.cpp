// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or (at your option) any later version.
//
// This application is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General
// Public License along with this application; if not, write to the
// Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301 USA

/// Developed by Jon Mundall <va7mje+qt@gmail.com>

#include "revelutejoint.h"



#include <QtGui>
#include "physicsitem.h"

#define SIZE 10


    ReveluteJoint::ReveluteJoint(b2World *world)
        :_world(world), _joint(0)
    {
    }


    void ReveluteJoint::setup(b2Body *body1, b2Body *body2,QPointF pos,int limit1, int limit2)
    {
     b2RevoluteJointDef jd;
     jd.collideConnected = false;



    if(limit1 != -1 && limit2 != -1){

    jd.lowerAngle = limit1 / (180/PI); //limit1 degrees of lower movement
    jd.upperAngle = limit2 / (180/PI); //limit2 degrees of upper movement
    jd.enableLimit = true;

}

    jd.Initialize(body1,body2,b2Vec2(pos.x(),-pos.y()));
    _joint = _world->CreateJoint(&jd);
    }





   ReveluteJoint::~ReveluteJoint()
   {

   if(_joint && _world){
       qDebug() << "Killing Revelute joint";
    _world->DestroyJoint(_joint);
   /// ;( The above line crashes the program...Not sure what happened to the joint but yeah...
   ///    It seems to work fine still
    qDebug() << "Done Killing Revelute joint";

   }

}
