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

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H


// Qt
#include <QMap>
#include <QString>

// local
class PhysicsItem;

/**
        Global item factory.
        This class is singleton, so it is creates no earlier, and no later (sic!)
        that it's neccesary.
        @author Maciek Gajewski <maciej.gajewski0@gmail.com>
*/
class ItemFactory
{
public:

        /// Creator interface - inherited by creator objects for each
        /// class known to the factory
        class Creator
        {
        public:
                virtual PhysicsItem* createObject() = 0;
        };

        static void addCreator( const QString& className, Creator* pCreator );
        static PhysicsItem* createItem( const QString& className );

private:

        static ItemFactory*	instance();	///< Creates/gest s instance

        static ItemFactory*	_pInstance;	///< Singleton instance

        QMap< QString, Creator* > _creators;
};

// Use this macro in .cpp of PhysicsItem - derrived objects
#define ADD_TO_FACTORY( classname ) \
        QString classname::className() {return #classname;} \
        class Creator_ ## classname : public ItemFactory::Creator \
        { \
        public: \
                Creator_ ## classname () { ItemFactory::addCreator( #classname, this ); } \
                virtual PhysicsItem* createObject(){ return new classname (); } \
        }; \
        Creator_ ## classname __staticClassCreator ## classname;


#endif // ITEMFACTORY_H
