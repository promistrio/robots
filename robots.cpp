#include "robots.h"
#include <QDebug>


Robots::Robots(Field *fld): field( *fld)
{
    // addRobot(41, 0);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(timer()));
    timer->start(1000);
    this->field[0][0] = 0;
    qDebug() << field[0];
    qDebug() << "<<<<<<<<<<" << this->field[0][0];
}


void Robots::addRobot(int x, int y)
{
    Robot pointer(x, y);

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    this->m_robots.append(pointer);
    endInsertRows();

}

Robot::Robot(int x, int y)
{
    this->pos.setX(x);
    this->pos.setY(y);
    this->source = QString ("Пусто");
    this->s_color = QString ("green");
}


void Robots::timer()
{
    QList<Robot>::iterator i;
    for (i = m_robots.begin(); i != m_robots.end(); ++i)
    {
        //i->changePos();
        QModelIndex topLeft = createIndex(i-m_robots.begin(),0);
        emit dataChanged(topLeft, topLeft);
    }
}

int Robots::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return this->m_robots.count();
}

QVariant Robots::data(const QModelIndex & index, int role) const {
    //qDebug() << index.row() << " " << index.column() << " " << role;
    Robot robot = this->m_robots[index.row()];
    if (index.row() < 0 || index.row() >= m_robots.count()){

        return QVariant();

    }
    else if (role == XRole)
        return robot.x();
    else if (role == YRole)
        return robot.y();
    else if (role == ColorRole){
        return QVariant::fromValue(robot.color());
    }
    return QVariant();
}

QHash<int, QByteArray> Robots::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[XRole] = "posX";
    roles[YRole] = "posY";
    roles[ColorRole] = "robot_color";
    return roles;
}

/*QVariant Robots::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal)
            return QString("Column %1").arg(section);
        else
            return QString("Row %1").arg(section);
}*/

/*Qt::ItemFlags Robots::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}*/
/*
bool CurrentPhotoPointer::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {

        //stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

QHash<int, QByteArray> CurrentPhotoPointer::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "track_id";
    roles[LatRole] = "lat";
    roles[LonRole] = "lon";
    roles[ColorRole] = "color_track";
    return roles;
}*/

