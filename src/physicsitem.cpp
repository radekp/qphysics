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

#include "physicsitem.h"
#include <QtGui>


    PhysicsItem::PhysicsItem(QGraphicsItem *parent)
        : QGraphicsItem(parent)
    {
        //setEditingEnabled(true);
    }

    void PhysicsItem::simulationStarting(World *world)
    {
        this->setEditingEnabled(false);

        _pos = this->pos();
        _angle = this->rotation();

        buildItem(world);
    }



    void PhysicsItem::simulationStoping()
    {
        destroyItem();

        this->show();
        this->setPos(_pos);
        this->setRotation(_angle);

        this->setEditingEnabled(true);

    }

    QString PhysicsItem::className()
    {
        return QString();
    }

    void PhysicsItem::load(QDataStream &out)
    {
    }
    void PhysicsItem::save(QDataStream &in)
    {
    }

    void PhysicsItem::updateShape()
    {
    }

    void PhysicsItem::addJoint(PhysicsItem *joint)
    {
        joints.append(joint);
        this->setEditingEnabled(false);
    }

    void PhysicsItem::setEditingEnabled(bool enabled)
    {
        if(enabled){
            setFlag(QGraphicsItem::ItemIsSelectable,true);
        if(_type != 2){ //type 2 = joint
         if(joints.size() == 0){
        setFlag(QGraphicsItem::ItemIsMovable,true);
    }
    }
 } else {
       setFlag(QGraphicsItem::ItemIsSelectable,false);
       setFlag(QGraphicsItem::ItemIsMovable,false);
   }



}
/*
    QVariant PhysicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
    {
        if (change == ItemSelectedChange && scene()) {
           return true/false
        }
        return QGraphicsItem::itemChange(change, value);
    }
*/



    void PhysicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
    {

        if(this->flags() & QGraphicsItem::ItemIsMovable){
      //  qreal d = QLineF(event->pos(), QPointF(_rect.size().width(),-_rect.size().height())).length();
        qreal d = QLineF(event->pos(),_rect.topRight()).length();
        if(d < 0.5f){ //is the mouse press event pos withen .5f of the top right corner (are resize handle)
            resizing = true; return;
        }

        rotationPoint = this->mapToScene(this->boundingRect().center());
        return;

        }
        QGraphicsItem::mousePressEvent(event);
        }


    void PhysicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {


        if(resizing && this->flags() & QGraphicsItem::ItemIsMovable){

       /// Round the size width and height to steps of 0.5
       QSize ns = QSize(event->pos().x()*2,-(event->pos().y()*2));
       QSizeF newSize = QSizeF(ns);
       newSize = QSizeF(newSize.width()/2,newSize.height()/2);

       if(newSize.width() >= 0.5f && newSize.height() >= 0.5f && newSize.width() < 100 && newSize.height() < 100 && newSize.width() * newSize.height() < 500){
        _rect.setSize(newSize);
        this->updateShape();
        this->scene()->update();
        resizing = true;
    }
        return;
    }




    if(this->isSelected() && event->modifiers() == Qt::ControlModifier && this->flags() & QGraphicsItem::ItemIsMovable)
    {
        int angle = -(QLineF(mapToScene(event->pos()),mapToScene(this->boundingRect().center())).angle());


        angle = (angle/9)*9; //round the angle to the nearest 9
        qDebug() << angle;

        this->setRotation(angle);
        QPointF center = this->mapToScene(boundingRect().center());
        center.setX(rotationPoint.x() - center.x());
        center.setY(rotationPoint.y() - center.y());

        this->moveBy(center.x(),center.y()); //Align the center

    } else {
            rotationPoint = this->mapToScene(this->boundingRect().center());
            QGraphicsItem::mouseMoveEvent(event);
        }

}

    void PhysicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
    {
        resizing = false;
     //   rebuild();
        QGraphicsItem::mouseReleaseEvent(event);
   }

    void PhysicsItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
    {

        if(_type == 1){
        QPointF pos = event->pos();

        PropertiesEditor *propEditor = new PropertiesEditor(_material);
        propEditor->setGeometry(pos.x(),pos.y(),320,240);
        propEditor->exec();
        this->update(); //When material changes the color of the item changes and the item needs repainting
    }
    }

    void PhysicsItem::advance(int step)
    {
     if (!step){return;}
        b2Vec2 position = _body->GetPosition();
        float32 angle = _body->GetAngle();
        setPos(position.x, -position.y);
        setRotation(-(angle * 360.0) / (2 * PI));
  }

   void PhysicsItem::buildItem(World *world)
   {
   }

   void PhysicsItem::destroyItem()
   {
   }

   void PhysicsItem::breakJoints()
   {
           //Delete any attached joints
        for(int i = 0; i < joints.size();i++)
        {
            if(joints.at(i)){delete joints.at(i); i--; } /// (i--;) i has to be subtracted when we kill a joint because the indexing in QList changes
        }
    }

    PhysicsItem::~PhysicsItem()
    {
    breakJoints();
    }

    QRectF PhysicsItem::boundingRect() const
    {
        return _rect;
    }
