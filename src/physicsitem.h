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

#ifndef PHYSICSITEM_H
#define PHYSICSITEM_H

#include <QGraphicsItem>
#include <QtGui>

#include "Box2D.h"

#include "world.h"
#include "material.h"
#include "defs.h"
#include "propertieseditor.h"



//#define ADD_ITEM( classname ) PhysicsItem::setClassName( #classname ); ADD_TO_FACTORY( classname );



class PhysicsItem : public QGraphicsItem
{
public:
    PhysicsItem(QGraphicsItem *parent = 0);
    ~PhysicsItem();

    virtual void buildItem(World *world);
    virtual void destroyItem();
    virtual QString className();
    virtual void updateShape();
    virtual void load(QDataStream &out);
    virtual void save(QDataStream &in);


    void simulationStarting(World *world);
    void simulationStoping();
    void setEditingEnabled(bool enabled);
    void addJoint(PhysicsItem *joint);
    void breakJoints();
  //  QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent (QGraphicsSceneContextMenuEvent *event);
    QRectF boundingRect() const;


    b2Body *_body;
    Material *_material;
    double _angle;
    int _type; //0 = static, 1 = normal, 2 = joint
    QPointF _pos;
    QRectF _rect;
    QPointF rotationPoint;

    QList<PhysicsItem*> joints;


    protected:
    void advance(int step);
    PropertiesEditor *propEditor;
    
    bool resizing;




};


#endif // PHYSICSITEM_H
