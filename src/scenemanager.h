// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.
// Developed by Jon Mundall <va7mje+qt@gmail.com>

#ifndef ITEMCONSTRUCTOR_H
#define ITEMCONSTRUCTOR_H

#include <QtGui>
#include <QGraphicsView>
#include "world.h"
#include "boltitem.h"
#include "rectitem.h"
#include "circleitem.h"
#include "welditem.h"
#include "material.h"
#include "simulator.h"
#include "itemfactory.h"

class SceneManager : public QObject
{
    Q_OBJECT

public:
    SceneManager(QGraphicsScene *scene,QGraphicsView *view,QObject *parent = 0);
    void addItem(QString name, QPointF pos, Material *material);
    void addRect(QRectF rect, Material *material);
    void addCircle(QRectF rect, Material *material);
    void addBolt(QPointF pos);
    void addWeld(QPointF pos);
    void deleteItem(QPointF pos);

    QGraphicsScene *_scene;
    QGraphicsView *_view;
    Simulator *simulator;

    public slots:
    void save(QString fileName);
    void load(QString fileName);

    void currentItemChanged(QModelIndex idx);
    void duplicateSelectedItems();
    void deleteSelectedItems();

};

#endif // ITEMCONSTRUCTOR_H
