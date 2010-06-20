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

#ifndef REVELUTEJOINT_H
#define REVELUTEJOINT_H


#include "Box2D.h"

#include <QtGui>
#include "defs.h"

class ReveluteJoint
{
public:
    ReveluteJoint(b2World *world);
    ~ReveluteJoint();

    void setup(b2Body *body1, b2Body *body2,QPointF pos, int limit1 = -1, int limit2 = -1);
     b2World *_world;
     b2Joint *_joint;

    int long m_maxStrength;

    public slots:
    void rebuild();


};
#endif // REVELUTEJOINT_H
