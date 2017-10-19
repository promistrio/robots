#include "field.h"

Field::Field(int width, int height)
{
    this->height = height;
    this->width = width;
    createVector(width, height);
    //calculatePath(1,1,width - 1,height - 1);

}

int Field::rowCount(const QModelIndex & /*parent*/) const
{
    return this->height * this->width;
}

void Field::createVector(int w, int h)
{
    this->v_field = QVector< QVector<int> >( w, QVector<int>( h, BLANK ) );

    /*for(int i = 0; i < w; ++i ) {

        temp[i].resize(h);
    }*/

    //qDebug() << this->v_field;


    //return temp;
}

int Field::columnCount(const QModelIndex & /*parent*/) const
{
    return this->width;
}

QVariant Field::data(const QModelIndex &index, int role) const
{
    //qDebug() << index.row() << " " << index.column() << " " << role;
   //Robot robot = this->m_robots[index.row()];

    if (index.row() < 0 || index.row() >= this->width * this->height)
    {
        return QVariant();
    }


    else if (role == valueRole)
    {
        int x = index.row() % this->width;
        int y = index.row() / this->width;
        return QVariant::fromValue(this->v_field[x][y]);
    }
    return QVariant();
}

QHash<int, QByteArray> Field::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[valueRole] = "value";
    return roles;
}
