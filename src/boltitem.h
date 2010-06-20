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

#ifndef BOLTITEM_H
#define BOLTITEM_H



#include <QGraphicsView>
#include "physicsitem.h"
#include "world.h"
#include "revelutejoint.h"

#include "Box2D.h"


class BoltItem : public PhysicsItem
{
public:
    BoltItem(PhysicsItem *parent = 0);
    void load(QDataStream &out);
    void save(QDataStream &in);
    void init(QPointF pos);
    void buildItem(World *world);
    void destroyItem();
    QString className();
    ~BoltItem();
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
     QRectF boundingRect() const;

    PhysicsItem *body1;
    PhysicsItem *body2;

    ReveluteJoint *bolt;


    int long reactionForce;

    protected:
    void advance(int step);
};


#endif // BOLTITEM_H
