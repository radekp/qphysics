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

#include "physicsitemexample.h"
#include "itemfactory.h"

ADD_TO_FACTORY( ExampleItem );





    ExampleItem::ExampleItem(PhysicsItem *parent)
        : PhysicsItem(parent)
    {
    }

    void ExampleItem::load(QDataStream &out)
    {
    qreal x,y,rotation;

    out >> rotation;
    out >> x;
    out >> y;
    _material->load(out);

    init();
    this->setPos(x,y);
    this->setRotation(rotation);
    this->setEditingEnabled(true);
    }

    void ExampleItem::save(QDataStream &in)
    {

    in << this->rotation();
    in << this->pos().x();
    in << this->pos().y();

    _material->save(in);
    }

    void ExampleItem::init()
    {
    }

    ExampleItem::~ExampleItem()
    {
        destroyItem();
    }

    void ExampleItem::buildItem(World *world)
    {
    }


    void ExampleItem::destroyItem()
    {
    }

    void ExampleItem::updateShape()
    {
    }



    void ExampleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
    {
    }



