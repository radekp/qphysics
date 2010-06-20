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

#include "circleitem.h"
#include "itemfactory.h"

ADD_TO_FACTORY( CircleItem );





    CircleItem::CircleItem(PhysicsItem *parent)
        : PhysicsItem(parent)
    {
        _type = 1; //1 = normal
    }


    void CircleItem::init(QRectF ellipse, Material *material)
    {
    _rect = ellipse;
    _material = material;

    this->setPos(_rect.x(),_rect.y());
    updateShape();

    setEditingEnabled(true); /// Todo: Move to PhysicsItem
    }

    CircleItem::~CircleItem()
    {
        destroyItem();
    }

    void CircleItem::buildItem(World *world)
    {
        updateShape();

        b2BodyDef bodyDef;

        if(_material->solid){bodyDef.type = b2_staticBody;} else {bodyDef.type = b2_dynamicBody;}

        bodyDef.position.Set(x(), -y());
        bodyDef.angle = -(rotation() * (2 * PI)) / 360.0;

        _body = world->B2DWorld->CreateBody(&bodyDef);

        b2CircleShape circle;
        //circle.m_p.Set(2.0f, 3.0f);
        circle.m_radius = qMin(_rect.width(),_rect.height())/2;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &circle;
        fixtureDef.density = _material->density;
        fixtureDef.friction = _material->friction;
        fixtureDef.restitution = _material->restution;

        _body->CreateFixture(&fixtureDef);
    }

    void CircleItem::destroyItem()
    {
    }

    void CircleItem::updateShape()
    {
        qreal size = qMin(_rect.width(),_rect.height());
        _rect = QRectF(-size/2,-size/2,size,size);
    }



    void CircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
    {
        if(this->isSelected()){
            //painter->setPen(Qt::DotLine);
            painter->drawRect(_rect);
            QPointF linep1 = _rect.topRight();
            linep1.setX(linep1.x()-.5f);
            linep1.setY(linep1.y()+.5f);

            QPointF pos1 =  _rect.topRight();
            pos1.setX(pos1.x()-.5f);

            QPointF pos2 =  _rect.topRight();
            pos2.setY(pos1.y()+.5f);


            painter->drawLine(pos1,pos2);
        }

        painter->setBrush(_material->brush);
        painter->setPen(_material->pen);

     //   qreal size = qMin(rect.width(),rect.height());
        painter->drawEllipse(_rect);
        painter->drawLine(_rect.center(),QPoint(_rect.center().x(),_rect.width()/2));
    }




    void CircleItem::load(QDataStream &out)
    {
    qreal x,y,rect_x,rect_y,rect_width,rect_height,rotation;

    Material *material = new Material();

    out >> rotation;
    out >> x;
    out >> y;
    out >> rect_x;
    out >> rect_y;
    out >> rect_width;
    out >> rect_height;

    material->load(out);

    init(QRectF(rect_x,rect_y,rect_width,rect_height),material);
    this->setPos(x,y);
    this->setRotation(rotation);
    this->setEditingEnabled(true);
    }

    void CircleItem::save(QDataStream &in)
    {

    in << this->rotation();
    in << this->pos().x();
    in << this->pos().y();
    in << _rect.x();
    in << _rect.y();
    in << _rect.width();
    in << _rect.height();

    _material->save(in);
    }
