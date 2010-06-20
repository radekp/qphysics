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

#ifndef RECTITEM_H
#define RECTITEM_H


#include "Box2D.h"

#include <QGraphicsView>
#include "physicsitem.h"
#include "defs.h"
#include "world.h"
#include "material.h"

#include <QtGui>

class RectItem : public PhysicsItem
{
public:
    RectItem(PhysicsItem *parent = 0);
    ~RectItem();
    QString className();
    void init(QRectF rect, Material *material);
    void buildItem(World *world);
    void destroyItem();
    void load(QDataStream &out);
    void save(QDataStream &in);
    void updateShape();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
     QPolygonF polygon;

};


#endif // RECTITEM_H
