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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "simulator.h"
#include "scenemanager.h"
#include "world.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0, Qt::WFlags f = 0);
    void mousePressEvent(QMouseEvent *event);
 //   void mouseMoveEvent(QMouseEvent *event);
    ~MainWindow();
    
    QString fileName;

public slots:
    void currentItemChanged(QModelIndex idx);
    void zoomIn();
    void zoomOut();
    void save();
    void load();


private:
    QString currentObj;
    QGraphicsScene *scene;
    SceneManager *sceneManager;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
