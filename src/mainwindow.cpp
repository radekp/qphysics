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

#include "mainwindow.h"
#include "material.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->scale(40.0,40.0);
    
 //   this->setWindowState(Qt::WindowFullScreen);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setBackgroundBrush(Qt::white);

    
 //   scene.setSceneRect(-110, -150, 220, 175);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing, false);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

 //   ui->graphicsView->setOptimizationFlag(QGraphicsView::DontSavePainterState);
 //   ui->graphicsView->setOptimizationFlag(QGraphicsView::DontClipPainter);
 //   ui->graphicsView->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);

 //   ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);


    ui->graphicsView->setScene(scene);
  //  ui->graphicsView->setViewport(new QGLWidget());








    sceneManager = new SceneManager(scene,ui->graphicsView);


    connect(ui->actionPause_Play,SIGNAL(triggered()),sceneManager->simulator,SLOT(PausePlay()));
    connect(ui->actionStart_Stop,SIGNAL(triggered()),sceneManager->simulator,SLOT(StopStart()));

    connect(ui->actionStep,SIGNAL(triggered()),sceneManager->simulator,SLOT(stepSim()));

    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(load()));

    connect(ui->actionZoom_In,SIGNAL(triggered()),this,SLOT(zoomIn()));
    connect(ui->actionZoom_Out,SIGNAL(triggered()),this,SLOT(zoomOut()));

    connect(ui->objectTree,SIGNAL(clicked(QModelIndex)),this,SLOT(currentItemChanged(QModelIndex)));
    connect(ui->actionClone,SIGNAL(triggered()),sceneManager,SLOT(duplicateSelectedItems()));
    connect(ui->actionDelete,SIGNAL(triggered()),sceneManager,SLOT(deleteSelectedItems()));
}

void MainWindow::zoomIn()
{
ui->graphicsView->scale(1.2,1.2);
}

void MainWindow::zoomOut()
{
ui->graphicsView->scale(0.8,0.8);
}

void MainWindow::currentItemChanged(QModelIndex idx)
{
    sceneManager->currentItemChanged(idx);
}






void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(!sceneManager->simulator->running){

    QPointF posF = ui->graphicsView->mapToScene(ui->graphicsView->mapFrom(this,event->pos()));
    QString obj = ui->objectTree->currentItem()->text(0);

    qDebug() << event;
    qDebug() << "pos: " << posF;
    qDebug() << "obj: " << obj;
    Material *material = Material::steel();
    sceneManager->addItem(obj,posF, material);
}
}

/*
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPointF posF = ui->graphicsView->mapToScene(ui->graphicsView->mapFrom(this,event->pos()));
    if(event->modifiers() == Qt::ControlModifier){

        QList <QGraphicsItem * > items = scene->selectedItems();
        if(items.size() > 0){
   //         items.first()->setRotation(QLineF(items.first()->boundingRect().center(),posF).angle()-360);
            items.first()->setTransformOriginPoint(items.first()->boundingRect().center());
            qreal angle = QLineF(items.first()->boundingRect().center(),posF).angle();
            items.first()->setRotation(angle);
            qDebug() << angle;

            //items.first()->setRotation((items.first()->y() - posF.y()));
        }
    }
}
*/


void MainWindow::save()
{
    if(fileName.size() < 1){
        fileName = QFileDialog::getSaveFileName(this,QString("save Physics Project"), QDir::homePath(), QString("Physics Project files (*.phy)"));
        if(!fileName.contains(".phy")){fileName.append(".phy");}
    }
        sceneManager->save(fileName);
}

void MainWindow::load()
{
        fileName = QFileDialog::getOpenFileName(this,QString("Open Physics Project"), QDir::homePath(), QString("Physics Project files (*.phy)"));

        sceneManager->load(fileName);
}



MainWindow::~MainWindow()
{
    delete ui;
}
