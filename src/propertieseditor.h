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

#ifndef PROPERTIESEDITOR_H
#define PROPERTIESEDITOR_H

#include <QtGui/QDialog>
#include "material.h"

namespace Ui {
    class PropertiesEditor;
}

class PropertiesEditor : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(PropertiesEditor)
public:
    explicit PropertiesEditor(Material *material = 0,QDialog *parent = 0);
    virtual ~PropertiesEditor();

    void setMaterial(Material *mat);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Material *material;
    Ui::PropertiesEditor *m_ui;


private slots:
    void updatePropertiesAndClose();
};

#endif // PROPERTIESEDITOR_H
