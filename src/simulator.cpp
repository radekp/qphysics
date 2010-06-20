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

#include "simulator.h"


#include <QTimer>
#include <QDebug>

#include "simulator.h"


static const int32 B2_VELOCITY_ITERATIONS = 10;//6
static const int32 B2_POSITION_ITERATIONS = 10;//2

static const float32 B2_TIMESTEP = 1.0f / 60.0f;



    Simulator::Simulator(QGraphicsScene *scene, QObject *parent)
        : QObject(parent), scene(scene)
    {

        timer = new QTimer(this);
        timer->setInterval(4);
        running = false;

        connect(this->timer,SIGNAL(timeout()),this,SLOT(step()));
    }


    void Simulator::step(){
            world->B2DWorld->Step(B2_TIMESTEP, B2_VELOCITY_ITERATIONS,B2_POSITION_ITERATIONS);
            scene->advance();
    }


    void Simulator::PausePlay()
    {
        if(running){
        if(timer->isActive()){
            timer->stop();
        } else {timer->start();}
    }
    }

    void Simulator::stepSim()
    {
        if(running && !timer->isActive()){step();}
    }

void Simulator::StopStart()
{

    QList<QGraphicsItem*> items = scene->items();

    if(running){
      running = false;

    for(int i = 0; i < items.size();i++){
    PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.at(i) );
    item->simulationStoping();
    }
    timer->stop();
    delete world;

    } else {
       world = new World();
        for(int i = 0; i < items.size();i++){
    PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.at(i) );
    item->simulationStarting(world);
    }
        timer->start();
        running = true;
}
}


Simulator::~Simulator()
{
      delete world;
}

