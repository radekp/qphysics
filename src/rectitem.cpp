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

#include "rectitem.h"
#include "itemfactory.h"

#define m_pointSize 0.5f

ADD_TO_FACTORY( RectItem );





    RectItem::RectItem(PhysicsItem *parent)
        : PhysicsItem(parent)
    {
        _type = 1; //1 = normal
    }

    void RectItem::load(QDataStream &out)
    {
    qreal x,y,rect_x,rect_y,rect_width,rect_height;

    qreal rotation;

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
    //this->setRotation(rotation);
    this->setEditingEnabled(true);
    }

    void RectItem::save(QDataStream &in)
    {

    //in << this->rotation();
    in << this->pos().x();
    in << this->pos().y();
    in << _rect.x();
    in << _rect.y();
    in << _rect.width();
    in << _rect.height();

    _material->save(in);
    }

    void RectItem::init(QRectF rect, Material *material)
    {
        _material = material;
        _rect = rect;

        this->setPos(_rect.x(),_rect.y());

        setEditingEnabled(true); /// Todo: Move to PhysicsItem
        updateShape();

}

    RectItem::~RectItem()
    {
        destroyItem();
    }




    void RectItem::updateShape()
    {
        polygon.clear();
        polygon.append(QPointF(0,-_rect.height()));
        polygon.append(QPointF(0,0));
        polygon.append(QPointF(_rect.width(),0));
        polygon.append(QPointF(_rect.width(),-_rect.height()));

        _rect = polygon.boundingRect();
     }



    void RectItem::buildItem(World *world)
    {
        updateShape();

        b2BodyDef bodyDef;

        if(_material->solid){bodyDef.type = b2_staticBody;} else {bodyDef.type = b2_dynamicBody;}

        bodyDef.position.Set(x(), -y());
      //  bodyDef.angle = -(rotation() * (2 * PI)) / 360.0;

        _body = world->B2DWorld->CreateBody(&bodyDef);
        b2PolygonShape shapeDef;

        int n = polygon.size();
        b2Vec2 vertices[n];
        for (int i = 0; i < n; ++i) {
            const QPointF &p = polygon.at(i);
            vertices[i].Set(p.x(), -p.y());
        }

        shapeDef.Set(vertices,n);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shapeDef;
        fixtureDef.density = _material->density;
        fixtureDef.friction = _material->friction;
        fixtureDef.restitution = _material->restution;

        _body->CreateFixture(&fixtureDef);
}

    void RectItem::destroyItem()
    {
    }




void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
       // Here comes the magic:
  // painter->setClipRect( option->exposedRect );


    painter->setBrush(_material->brush);
    painter->setPen(_material->pen);

    /// Todo: Move this to one of the mouse press/release events in the PhysicsItem class to increase performance.
    if(this->isSelected()){

        painter->setPen(Qt::DotLine);
        painter->drawPolygon(polygon);
        painter->setPen(Qt::SolidLine);

        QPointF linep1 = polygon.at(3);
        linep1.setX(linep1.x()-.5f);
        linep1.setY(linep1.y()+.5f);

        QPointF pos1 = polygon.at(3);
        pos1.setX(pos1.x()-.5f);

        QPointF pos2 = polygon.at(3);
        pos2.setY(pos1.y()+.5f);


        painter->drawLine(pos1,pos2);
       // painter->drawLine(linep1,polygon.at(3));


/*

        // Draw the control points
        painter->setPen(QColor(50, 100, 120, 200));
        painter->setBrush(QColor(200, 200, 210, 120));
        for (int i=0; i<polygon.size(); ++i) {
            QPointF pos = polygon.at(i);
            painter->drawEllipse(QRectF(pos.x() - m_pointSize,
                                       pos.y() - m_pointSize,
                                       m_pointSize*2, m_pointSize*2));
        }
        painter->setPen(QPen(Qt::lightGray, 0, Qt::SolidLine));
        painter->setBrush(Qt::NoBrush);
        painter->drawPolyline(polygon);

   //     painter->drawPolyline(polygon);
        */
} else {

  //  painter->drawRect(_rect);
    painter->drawPolygon(polygon);
}
}



