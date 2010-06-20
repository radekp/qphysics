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

#include "world.h"

World::World()
{
    /// Todo: Set upper and lower Bound values to come from the GraphicsScene
            worldRect = QRectF(-10000,-10000,20000,20000);


            // Define world, gravity
        b2AABB worldAABB;

        worldAABB.lowerBound.Set(worldRect.left(), worldRect.top());
        worldAABB.upperBound.Set(worldRect.right(), worldRect.bottom());


        
        B2DWorld = new b2World(/* gravity = */ b2Vec2(0.0f, -10.0f),
                               /* doSleep = */ true);

}
