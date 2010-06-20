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

#include "material.h"

Material::Material(QString name,float density, float friction, float restution, QBrush brush,QPen pen, bool solid)
: name(name), density(density), friction(friction), restution(restution), brush(brush), pen(pen),solid(solid)
{
}

Material* Material::fromString(QString name)
{
    if(name == "steel")
    {
        return steel();
    }
    if(name == "rubber")
    {
        return rubber();
    }
    if(name == "wood")
    {
        return wood();
    }
    if(name == "lead")
    {
        return lead();
    }
    if(name == "foam")
    {
        return foam();
    }
    if(name == "ice")
    {
        return ice();
    }
    return 0;

}

Material* Material::steel()
{
    return new Material("steel",250,0.5f,0.1f,QBrush(Qt::gray));
}

Material* Material::ice()
{
    return new Material("ice",250,0.001f,0.0f,QBrush("#c2e7ff"),QPen("#c2e7ff"));
}

Material* Material::rubber()
{
    return new Material("rubber",50,1,0.6f,QBrush(Qt::black));
}

Material* Material::lead()
{
    return new Material("lead",1000,0.9f,0.1f,QBrush(Qt::darkGray));
}

Material* Material::foam()
{
    return new Material("foam",1,0.4f,0.4f,QBrush(Qt::lightGray));
}

Material* Material::wood()
{
    return new Material("wood",75,0.9f,0.1f,QBrush(Qt::darkYellow));
}



void Material::load(QDataStream &out)
{
    out >> name;
    out >> density;
    out >> friction;
    out >> restution;
    out >> brush;
    out >> pen;
    out >> solid;
}

void Material::save(QDataStream &in)
{
    in << name;
    in << density;
    in << friction;
    in << restution;
    in << brush;
    in << pen;
    in << solid;
}




