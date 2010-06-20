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
#include "grounditem.h"



    GroundItem::GroundItem(World *world, QRectF rect, double maxSlope, Material material, PhysicsItem *parent)
        : PhysicsItem(parent), _rect(rect), _maxSlope(maxSlope)
    {
        _world = world;
        _material = material;


        this->setPos(_rect.x(),_rect.y());
        this->setup();
}

    GroundItem::~GroundItem()
    {

    }

void GroundItem::setup()
{
        // Create body with start-up position and rotation.
        b2BodyDef bodyDef;
        bodyDef.position.Set(x(), -y());
        bodyDef.angle = -(rotation() * (2 * PI)) / 360.0;
        _body = _world->B2DWorld->CreateBody(&bodyDef);







        // Assign shape to polygon body.
        b2ShapeDef shapeDef;

        shapeDef.density = _material.density;
        shapeDef.friction = _material.friction;
        shapeDef.restitution = _material.restution;


        QList< b2ShapeDef* > shapes = createShape(); // create body shape(s)

        // add shapes to body
        foreach( b2ShapeDef* pShape, shapes )
        {

            bodyDef.AddShape( pShape );
        }

        b2FixtureDef fixtureDef;





        int n = shapeDef.vertexCount = poly.size();
        for (int i = 0; i < n; ++i) {
            const QPointF &p = poly.at(i);
            shapeDef.vertices[i].Set(p.x(), -p.y());
        }
         _body->CreateShape(&shapeDef);


if(!_material.solid)
         {
        // Setup default mass.
          _body->SetMassFromShapes();
}
this->advance(1);

}















// ================================= init =============================
void GroundItem::setup()
{
            // cache
        double worldHeight = _rect.height();
        double worldWidth = _rect.width();

        // params / constants
        double MAX_HEIGHT = worldHeight * 0.9; // fit between 10% and 90%
        double MIN_HEIGHT = worldHeight * 0.1;

        const double SAFEAREA_WIDTH = 30.0;	// 30m

        const double MAX_SLICE_WIDTH = 10.0;
        const double MIN_SLICE_WIDTH = 1.0;

        double MAX_SLOPE = _maxSlope; // difficulty level. max slope is MAX_SLOPE * (1+SLOPE_VARIATION)
        const double SLOPE_GAIN = 0.02;	// controlelr gain: slope/meter difference
        double SLOPE_VARIATION = _maxSlope * 0.3;

        // first - get random target heights at constant intervals
        const int SECTIONS = 10;
        double targets[ SECTIONS ];

        for ( int i = 0; i < SECTIONS; i++ )
        {
                targets[ i ] = MIN_HEIGHT + ( MAX_HEIGHT - MIN_HEIGHT ) * double(qrand()) / RAND_MAX;
        }

        // now - randomize slices
        QPolygonF points;

        // intial height
        double height = MIN_HEIGHT + ( MAX_HEIGHT - MIN_HEIGHT ) * double(qrand()) / RAND_MAX;

        // first points - left safe area
        points.append( QPointF( 0, height ) );
        points.append( QPointF( SAFEAREA_WIDTH, height ) );

        // now - randomize points
        double x = SAFEAREA_WIDTH;
        while ( x < ( worldWidth - SAFEAREA_WIDTH - MAX_SLICE_WIDTH ) )
        {
                double sliceWidth = MIN_SLICE_WIDTH + ( MAX_SLICE_WIDTH - MIN_SLICE_WIDTH ) * double(qrand()) / RAND_MAX;

                // find out which section is it
                double sectionReal = ( x - SAFEAREA_WIDTH ) / ( ( worldWidth - 2*SAFEAREA_WIDTH ) / SECTIONS );
                int closestSection = qRound( sectionReal );
                int nextSection = ceil( sectionReal );

                // find target

                // calculate slope
                double calculatedSlope = SLOPE_GAIN * ( targets[closestSection] - height );

                // apply sign based on next section pos
                if ( ( ( targets[nextSection] - height ) * calculatedSlope ) < 0.0 )
                {
                        calculatedSlope *= -1.0;
                }

                // apply limit
                if ( calculatedSlope > MAX_SLOPE ) calculatedSlope = MAX_SLOPE;
                if ( calculatedSlope < -MAX_SLOPE ) calculatedSlope = -MAX_SLOPE;

                // add randomization
                double slope = calculatedSlope - SLOPE_VARIATION + 2*SLOPE_VARIATION*( double(qrand()) / RAND_MAX );

                // calculate new height
                height = height + slope * sliceWidth;
                x += sliceWidth;

                points.append( QPointF( x, height ) );

        }

        // close: right safe area
        points.append( QPointF( worldWidth, height ) );

        // create body
   //     GroundItem* pGround = new GroundItem();
        points.translate( - worldWidth / 2, - worldHeight / 2 );
        this->setHeightmap( points );
}

// =========================== paint ============================
void GroundItem::paint( QPainter *painter, const QStyleOptionGraphicsItem* , QWidget*)
{
        // simple selection indicator
        QBrush b = brush();
        if ( selected() )
        {
                b = Qt::gray;
        }

        painter->setPen( pen() );
        painter->setBrush( b );

        // create cached polygin, if none
        if ( _painterPolygon.empty() )
        {
                _painterPolygon = _heightmap;
                // add corners
                _painterPolygon.append( _world->worldRect.topRight() );
                _painterPolygon.prepend( _world->worldRect.topLeft() );
        }


        painter->drawPolygon( _painterPolygon );
}

// =============================== destructor =======================
GroundItem::~GroundItem()
{
        // nope
}

// ================================== height ========================
/// Calculates y for specified x.
double GroundItem::height( double x )
{
        // find line containing this coordinate
        for( int i = 0; i < _heightmap.size() - 1; i++ )
        {
                if ( _heightmap[i].x() <= x && _heightmap[i+1].x() >= x )
                {
                        double x1 = _heightmap[i].x();
                        double y1 = _heightmap[i].y();
                        double x2 = _heightmap[i+1].x();
                        double y2 = _heightmap[i+1].y();

                        return y1 + ( y2 - y1 ) * ( x - x1) / ( x2 - x1 );
                }
        }
        return 0;
}

// ================================= set heightmap =====================
/// Sets height map
void GroundItem::setHeightmap( const QPolygonF& heightMap )
{
        _heightmap = heightMap;
}



// ============================ boundoing rect =====================
QRectF GroundItem::boundingRect() const
{
        // create cached polygin, if none
        if ( _painterPolygon.empty() )
        {
                _painterPolygon = _heightmap;
                // add corners
                _painterPolygon.append( simulation()->worldRect().topRight() );
                _painterPolygon.prepend( simulation()->worldRect().topLeft() );
        }

        return _painterPolygon.boundingRect();
}

// =========================== create shape ============================
QList<b2ShapeDef*> GroundItem::createShape()
{
        const double MIN_PRODUCT = 0.001;

        QList<b2ShapeDef*> list;

        double bottom = simulation()->worldRect().top(); // note: QRect uses higher-smaller y coords


        // create two triangles for each point (trapezoid) in height map
        int num = _heightmap.size();
        QPointF prevPoint = _heightmap.first();
        for ( int i = 1; i < num; i++ )
        {
                QPointF point = _heightmap[ i ];

                // calculate two points at bottom
                QPointF prevBottomPoint( prevPoint.x(), bottom ); // point at bottom, just below prevPoint
                QPointF bottomPoint( point.x(), bottom ); // point at bottom, just below point

                list.append( createTriangleB2Shape( bottomPoint, prevPoint, prevBottomPoint ) );
                list.append( createTriangleB2Shape( bottomPoint, point, prevPoint ) );

                prevPoint = point;
        }

        return list;
}

// ========================== create triangle ================
b2PolyDef* GroundItem::createTriangleB2Shape( const QPointF& a, const QPointF& b, const QPointF& c )
{
        b2PolyDef* pTriangle = new b2PolyDef();

        pTriangle->vertexCount = 3;
        pTriangle->vertices[0].Set( a.x(), a.y() );
        pTriangle->vertices[1].Set( b.x(), b.y() );
        pTriangle->vertices[2].Set( c.x(), c.y() );

        return pTriangle;
}


// ========================== product ================
/// Calculates Z coordinate of two 3D cross product of two 2D vectors
/// with artifical Z.
/// In other words: (0 0 z) = (a1 a2 0) x (b1 b2 0)
/// This value is equal to |a||b|sin(o), where 0 i angle btween vectors
double GroundItem::product( const QPointF& a, const QPointF& b )
{
        return a.x()*b.y() - a.y()*b.x();
}

// ======================== contains ==========================
bool GroundItem::contains( const QPointF& pos ) const
{
        return _painterPolygon.containsPoint( pos, Qt::OddEvenFill );
}
*/
