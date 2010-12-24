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

#include "scenemanager.h"

// test16.phy has weird behavior


SceneManager::SceneManager(QGraphicsScene *scene,QGraphicsView *view,QObject *parent)
        : QObject(parent), _scene(scene),_view(view)
{


    Material *material = Material::steel();;
    material->solid = true;


    addRect(QRectF(-200,-400,800,0.5f),material);
    simulator = new Simulator(scene);
}

void SceneManager::addItem(QString name,QPointF pos, Material *material)
{
    if(name == "Block"){addRect(QRectF(pos.x(),pos.y(),6,6),material);}
    if(name == "Circle"){addCircle(QRectF(pos.x(),pos.y(),6,6),material);}
    if(name == "Bolt"){addBolt(pos);}
    if(name == "Weld"){addWeld(pos);}
    if(name == "Beam"){addRect(QRectF(pos.x(),pos.y(),10,0.5f),material);}
    if(name == "Delete Items"){deleteItem(pos);}
}



void SceneManager::currentItemChanged(QModelIndex idx)
{
    QString obj = idx.data().toString();
    QList<QGraphicsItem*> items = _scene->items();


    if(obj == "Edit Items"){
    _view->setDragMode(QGraphicsView::RubberBandDrag);
    _view->setCursor(Qt::ArrowCursor);

    for(int i = 0; i < items.size();i++){
    PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.at(i) );

    if(!simulator->running){
    item->setEditingEnabled(true);
    }
    }

    } else {
    _view->setDragMode(QGraphicsView::NoDrag);
    _view->setCursor(Qt::CrossCursor);
    for(int i = 0; i < items.size();i++){
    PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.at(i) );
    item->setEditingEnabled(false);
    }

}
}

void SceneManager::addRect(QRectF rect, Material *material)
{
RectItem *item = new RectItem();
item->init(rect,material);
_scene->addItem(item);
}

void SceneManager::addCircle(QRectF rect, Material *material)
{
    CircleItem *item = new CircleItem();
    item->init(rect,material);
    _scene->addItem(item);
}

void SceneManager::deleteItem(QPointF pos)
{
    QList<QGraphicsItem*> items = _scene->items(pos);

    qDebug() << "SceneManager::deleteItem(" << pos << ")";
    if(items.size() > 0){

      //  _scene->removeItem(items.first()); //Dosn't delete the item;
       // _scene->update();
      //  items.first()->~QGraphicsItem();
      // items.first()->

       PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.first() );
       qDebug() << "Removing: " << item->className();
       delete item;
      // item->kill();
     //  _scene->removeItem(item);
      // delete item;
      // item->~PhysicsItem();
    }
}


    void SceneManager::addBolt(QPointF pos)
    {
    BoltItem *bolt = new BoltItem();
    _scene->addItem(bolt);
    qDebug() << "Successfully created bolt item";
    bolt->init(pos);
}


    void SceneManager::addWeld(QPointF pos)
    {
    WeldItem *weld = new WeldItem();
    _scene->addItem(weld);
    qDebug() << "Successfully created bolt item";
    weld->init(pos);
}


    void SceneManager::deleteSelectedItems()
    {
        while(_scene->selectedItems().size() > 0){
            delete _scene->selectedItems().first();
        }

    }

    void SceneManager::duplicateSelectedItems()
    {
        QList<QGraphicsItem *> selected;
        selected = _scene->selectedItems();

        QBuffer buffer;
        buffer.open(QBuffer::ReadWrite);
        QDataStream data(&buffer);

        data << selected.size();

        foreach (QGraphicsItem *item, selected) {
            PhysicsItem *physicsItem = qgraphicsitem_cast<PhysicsItem *>(item);
            data << physicsItem->className();
            physicsItem->save(data);
        }

        buffer.reset();
        _scene->clearSelection();

        int items;
        data >> items;

        for(int i = 0; i < items; i++)
        {
            QString className;
            data >> className;
            PhysicsItem *item = ItemFactory::createItem(className);
            _scene->addItem(item);
            item->load(data);
            item->setX(item->x()+1);
            item->setY(item->y()-1);
            item->setSelected(true);
        }


    }




    void SceneManager::save(QString fileName)
    {

    QList<QGraphicsItem*> items = _scene->items();


    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QDataStream in(&file);

    in << items.size();

    for(int i = 0; i < items.size(); i++)
    {
    PhysicsItem *item = dynamic_cast<PhysicsItem*>( items.at(i) );
    in << item->className();
    item->save(in);
    }

    file.close();

    }

    void SceneManager::load(QString fileName)
    {
    QFile file(fileName);
    if(!(fileName.size() > 0)){return;}
    file.open(QIODevice::ReadOnly);
    QDataStream out(&file);    // read the data serialized from the file

  //  delete _scene;
 //   _scene = new QGraphicsScene(this);
 //   _view->setScene(_scene);


    QList<QGraphicsItem*> sceneItems = _scene->items();

    foreach (QGraphicsItem *item, sceneItems) {
        PhysicsItem *physicsItem = qgraphicsitem_cast<PhysicsItem *>(item);
        if(physicsItem->_type != 2){ //joint, We don't delete these there deleted when the objects connected to are deleted
            delete physicsItem;
        }
    }



    int items;
    out >> items;

    qDebug() << "Loading file with " << items << " items";

    for(int i = 0; i < items; i++)
    {
        QString className;
        out >> className;
        PhysicsItem *item = ItemFactory::createItem(className);
        _scene->addItem(item);
        qDebug() << "Loading " << className;
        item->load(out);
        qDebug() << "Finished loading " << className;


    }


    file.close();


}
