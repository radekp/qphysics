/********************************************************************************
** Form generated from reading UI file 'propertieseditor.ui'
**
** Created: Wed Sep 22 14:26:03 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESEDITOR_H
#define UI_PROPERTIESEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertiesEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *materialSelector;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QCheckBox *static_material;

    void setupUi(QWidget *PropertiesEditor)
    {
        if (PropertiesEditor->objectName().isEmpty())
            PropertiesEditor->setObjectName(QString::fromUtf8("PropertiesEditor"));
        PropertiesEditor->resize(240, 240);
        gridLayout = new QGridLayout(PropertiesEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PropertiesEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        materialSelector = new QComboBox(PropertiesEditor);
        materialSelector->setObjectName(QString::fromUtf8("materialSelector"));

        gridLayout->addWidget(materialSelector, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        buttonBox = new QDialogButtonBox(PropertiesEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        static_material = new QCheckBox(PropertiesEditor);
        static_material->setObjectName(QString::fromUtf8("static_material"));

        gridLayout->addWidget(static_material, 1, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(materialSelector);
#endif // QT_NO_SHORTCUT

        retranslateUi(PropertiesEditor);

        QMetaObject::connectSlotsByName(PropertiesEditor);
    } // setupUi

    void retranslateUi(QWidget *PropertiesEditor)
    {
        PropertiesEditor->setWindowTitle(QApplication::translate("PropertiesEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PropertiesEditor", "Material", 0, QApplication::UnicodeUTF8));
        materialSelector->clear();
        materialSelector->insertItems(0, QStringList()
         << QApplication::translate("PropertiesEditor", "lead", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertiesEditor", "steel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertiesEditor", "ice", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertiesEditor", "wood", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertiesEditor", "rubber", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PropertiesEditor", "foam", 0, QApplication::UnicodeUTF8)
        );
        static_material->setText(QApplication::translate("PropertiesEditor", "Static", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PropertiesEditor: public Ui_PropertiesEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESEDITOR_H
