#ifndef ROBOTS_H
#define ROBOTS_H

#include <QObject>
#include <QAbstractListModel>
#include <QTimer>
#include "robot.h"
#include "field.h"

class Robots : public QAbstractListModel
{
    Q_OBJECT
public:
    enum PointRoles {
        XRole = Qt::UserRole + 1,
        YRole,
        ColorRole
    };

    Robots(Field * field);



    Q_INVOKABLE void addRobot(int x, int y);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    //    QVariant headerData(int section, Qt::Orientation orientation,
    //                        int role = Qt::DisplayRole) const;

    // Qt::ItemFlags flags(const QModelIndex &index) const;

    //    bool setData(const QModelIndex &index, const QVariant &value,
    //                 int role = Qt::EditRole);


protected:
    QHash<int, QByteArray> roleNames() const;
public slots:
    void timer();
private:
    Field & field;

    QList<Robot> m_robots;
};



#endif // ROBOTS_H
