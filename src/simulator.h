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

#ifndef SIMULATOR_H
#define SIMULATOR_H



#include "physicsitem.h"
#include "defs.h"
#include "world.h"

#include "Box2D.h"

#include <QtGui>
#include <QGraphicsScene>




class Simulator : public QObject
{
    Q_OBJECT
public:
    Simulator(QGraphicsScene *scene,QObject *parent = 0);
    ~Simulator();

    bool running;

    QPolygonF addGround();

    //QGraphicsBox2DCircleItem  *actor;
    QTimer *timer;

public slots:

    void step();
    void stepSim();
    void PausePlay();
    void StopStart();


private:
    QGraphicsScene *scene;
    World  *world;



};

#endif // SIMULATOR_H
