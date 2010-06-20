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

/*
#ifndef GROUNDITEM_H
#define GROUNDITEM_H


#include "Box2D.h"

#include <QGraphicsView>
#include "physicsitem.h"
#include "defs.h"
#include "world.h"
#include "material.h"

#include <QtGui>


class GroundItem : public PhysicsItem
{
public:
    GroundItem(World *world, QRectF rect, double maxSlope, Material material, PhysicsItem *parent = 0);
    ~GroundItem();

    void setup();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    virtual QRectF boundingRect() const;

    double height( double x );							///< Calculates ground height at specified x
    void setHeightmap( const QPolygonF& heightMap );	                        ///< Sets heightmap
    static GroundItem* randomGround( const QRectF& rect, double maxSlope );     /// Creates random ground for specified simulation

    virtual bool contains( const QPointF& pos ) const;

     QRectF _rect;
     QPolygonF _polygon;
     double _maxSlope;


    protected:
        virtual QList<b2ShapeDef*> createShape();

    private:
        static b2PolygonDef* createTriangleB2Shape( const QPointF& a, const QPointF& b, const QPointF& c );
        static double product( const QPointF& a, const QPointF& b );

        QPolygonF	        _heightmap;
        mutable QPolygonF	_painterPolygon;
        mutable QRectF          _boundingRect;



};
#endif // GROUNDITEM_H
*/
