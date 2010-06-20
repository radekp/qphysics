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

#include "itemfactory.h"

#include <QDebug>

ItemFactory* ItemFactory::_pInstance	= NULL;

// =====================================================
void ItemFactory::addCreator( const QString& className, Creator* pCreator )
{
        instance()->_creators[ className ] = pCreator;
}

// =====================================================
PhysicsItem* ItemFactory::createItem( const QString& className )
{
        Creator* pCreator = instance()->_creators[ className ];
        if ( pCreator )
        {
                return pCreator->createObject();
        }
        qWarning("Item factory has no creator for %s", qPrintable( className ) );

        return NULL;
}

// =====================================================
ItemFactory* ItemFactory::instance()
{
        if ( ! _pInstance )
        {
                _pInstance = new ItemFactory();
        }

        return _pInstance;
}

