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

#ifndef MATERIAL_H
#define MATERIAL_H

#include <QtGui>

class Material
{
public:
    Material(QString name = QString("undefined"),float density = 0.9f, float friction = 0.9f, float restution = 0, QBrush brush = QBrush(Qt::white),QPen pen = QPen(Qt::black), bool solid = false);
    static Material* fromString(QString name);
    static Material* steel();
    static Material* rubber();
    static Material* lead();
    static Material* foam();
    static Material* wood();
    static Material* ice();

    void load(QDataStream &out);
    void save(QDataStream &in);

    QString name;

    float density;
    float friction;
    float restution;
    bool solid;

    QPen pen;
    QBrush brush;


};

#endif // MATERIAL_H
