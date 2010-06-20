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

#include <QDebug>
#include "propertieseditor.h"
#include "ui_propertieseditor.h"

PropertiesEditor::PropertiesEditor(Material *material,QDialog *parent) :
    QDialog(parent), material(material),
    m_ui(new Ui::PropertiesEditor)
{
    qDebug() << material->name;
    m_ui->setupUi(this);
    setMaterial(material);
    connect(m_ui->buttonBox,SIGNAL(accepted()),this,SLOT(updatePropertiesAndClose()));
    connect(m_ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
}

PropertiesEditor::~PropertiesEditor()
{
    delete m_ui;
}

void PropertiesEditor::updatePropertiesAndClose() /// TODO: This is a primitave method of copying mat to Material, It should be fixed asap
{
Material *mat = Material::fromString(m_ui->materialSelector->currentText());



material->brush = mat->brush;
material->pen = mat->pen;
material->density = mat->density;
material->friction = mat->friction;
material->restution = mat->restution;
material->name = mat->name;
material->solid = m_ui->static_material->isChecked();

this->close();
}

void PropertiesEditor::setMaterial(Material *mat)
{
    for(int i = 0; i < m_ui->materialSelector->model()->rowCount(); i++)
    {
    if(m_ui->materialSelector->itemText(i) == mat->name){ m_ui->materialSelector->setCurrentIndex(i);}
    }
    m_ui->static_material->setChecked(mat->solid);
}



void PropertiesEditor::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
