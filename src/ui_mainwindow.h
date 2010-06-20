/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 17 10:02:34 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionStart_Stop;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionClone;
    QAction *actionDelete;
    QAction *actionPause_Play;
    QAction *actionStep;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeWidget *objectTree;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background:white;\n"
"}\n"
""));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionStart_Stop = new QAction(MainWindow);
        actionStart_Stop->setObjectName(QString::fromUtf8("actionStart_Stop"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionClone = new QAction(MainWindow);
        actionClone->setObjectName(QString::fromUtf8("actionClone"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionPause_Play = new QAction(MainWindow);
        actionPause_Play->setObjectName(QString::fromUtf8("actionPause_Play"));
        actionStep = new QAction(MainWindow);
        actionStep->setObjectName(QString::fromUtf8("actionStep"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        objectTree = new QTreeWidget(centralWidget);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        new QTreeWidgetItem(objectTree);
        objectTree->setObjectName(QString::fromUtf8("objectTree"));
        objectTree->setMaximumSize(QSize(110, 16777215));
        objectTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        objectTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        objectTree->header()->setVisible(false);
        objectTree->header()->setStretchLastSection(true);

        gridLayout->addWidget(objectTree, 0, 0, 2, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMouseTracking(true);
        graphicsView->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(graphicsView, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMouseTracking(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        mainToolBar->addAction(actionStart_Stop);
        mainToolBar->addAction(actionPause_Play);
        mainToolBar->addAction(actionStep);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoom_In);
        mainToolBar->addAction(actionZoom_Out);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClone);
        mainToolBar->addAction(actionDelete);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionStart_Stop->setText(QApplication::translate("MainWindow", "Start/Stop", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionClone->setText(QApplication::translate("MainWindow", "Clone", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionPause_Play->setText(QApplication::translate("MainWindow", "Pause/Play", 0, QApplication::UnicodeUTF8));
        actionPause_Play->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionStep->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        actionStep->setShortcut(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = objectTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Objects", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = objectTree->isSortingEnabled();
        objectTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = objectTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Block", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = objectTree->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Circle", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = objectTree->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Beam", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = objectTree->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Bolt", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = objectTree->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Weld", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = objectTree->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Edit Items", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = objectTree->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Delete Items", 0, QApplication::UnicodeUTF8));
        objectTree->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
