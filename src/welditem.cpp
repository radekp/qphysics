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

#include "welditem.h"
#include "itemfactory.h"


#define SIZE 0.2f
#define SHEER_FORCE 100

ADD_TO_FACTORY( WeldItem );


    WeldItem::WeldItem(PhysicsItem *parent)
        : PhysicsItem(parent)
    {
    }

   void WeldItem::load(QDataStream &out)
    {
    float x,y;

    out >> x;
    out >> y;

    this->init(QPointF(x,y));
    }
    void WeldItem::save(QDataStream &in)
    {
        in << this->pos().x();
        in << this->pos().y();
    }


    void WeldItem::init(QPointF pos)   /// Todo: Make sure bolt dosn't connect to itself
    {
        body1 = 0;
        body2 = 0;
        _body = 0;         // Kill the body, We don't need it for this item...

        _type = 2; //2 = joint
        reactionForce = 0;
        reactionTorque = 0;


    QList<QGraphicsItem*> items = scene()->items(pos);
    qDebug() << items.size();

    if(items.size() == 2){



    body1 = dynamic_cast<PhysicsItem*>( items.at(0) );
    body2 = dynamic_cast<PhysicsItem*>( items.at(1) );

    if(body1 != this && body2 != this){

   // if(body1 && body2){      // necessary?
        this->setZValue(1000); //A high Z value so it will always be on top
        this->setPos(pos);     // Set the initial position

        body1->addJoint(this);
        body2->addJoint(this);
        return;
//}
}
}
    qDebug() << "Failed BoltItem::init";
 //   delete this;
  //  this->~QGraphicsItem();
  //  scene()->removeItem(this);
    delete this;
}



    void WeldItem::buildItem(World *world)
    {
    this->show();
    reactionForce = 0;
    reactionTorque = 0;
    weld = new ReveluteJoint(world->B2DWorld);
    weld->setup(body1->_body,body2->_body,this->pos(),0,0);
    }

    void WeldItem::destroyItem(){if(weld && this->isVisible()){delete weld;}}


    WeldItem::~WeldItem()
    {
        if(body1 && body2){
        body1->joints.removeOne(this);
        body2->joints.removeOne(this);
    }
    }


    void WeldItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{



        painter->setBrush( Qt::black );


     QRadialGradient gradient(this->boundingRect().center(),SIZE);
     gradient.setColorAt(0, Qt::black);
     gradient.setColorAt(0.7, Qt::white);

     QBrush brush(gradient);

        painter->setBrush(brush);


         // simple selection indicator
        if ( this->isSelected() )
        {
                painter->drawRect(this->boundingRect());
        }



        painter->setPen(Qt::NoPen);

        painter->drawEllipse(boundingRect());
        painter->drawPoint(this->pos());



}

    QRectF WeldItem::boundingRect() const
{
        return QRectF((-SIZE/2)-(SIZE/10),(-SIZE/2)-(SIZE/10),SIZE,SIZE);
}





    void WeldItem::advance(int step)
    {
     if (!step || !this->isVisible()){return;}

     // Update QGraphicsItem's position and rotation from joint body 1.
        b2Vec2 position = weld->_joint->GetAnchorA();
        setRotation(-(weld->_joint->GetBodyA()->GetAngle() * 360.0) / (2 * PI));
        setPos(position.x, -position.y);



            //Calculate stress on the joint and break it if it's to much, Sad world...
            b2Vec2 rForce = weld->_joint->GetReactionForce(1);
            int long rTorque = weld->_joint->GetReactionTorque(1)/1000;

            if(rForce.x < 0){reactionForce += -rForce.x/10;} else {reactionForce += rForce.x/10;}
            if(rForce.y < 0){reactionForce += -rForce.y/10;} else {reactionForce += rForce.y/10;}

            if(rTorque < 0){reactionTorque += -rTorque;} else {reactionTorque += rTorque;}

            reactionForce -= reactionForce/SHEER_FORCE;
            reactionTorque -= reactionTorque/SHEER_FORCE;

          //  qDebug() << "Reaction Force: " << reactionForce/500;
          //  qDebug() << "Reaction Torque: " << reactionTorque/500;

            if(reactionForce/SHEER_FORCE > 600){
                qDebug() << "Breaking Weld to a reaction force of " << reactionForce/SHEER_FORCE;
               // delete this;
                destroyItem();
                this->hide();
                return;
            }

               if(reactionTorque/SHEER_FORCE > 600){
                 qDebug() << "Breaking Weld to a reaction torque of " << reactionTorque/SHEER_FORCE;
               //  delete this;
                 destroyItem();
                 this->hide();
               }

    }


