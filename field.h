#ifndef FIELD_H
#define FIELD_H


#include <QAbstractTableModel>
#include <QDebug>
#include <QVector>
#include "constants.h"
#include <QTime>

class Field : public QAbstractListModel
{
    Q_OBJECT
public:
    enum PointRoles {
        valueRole = Qt::UserRole + 1,
    };
    Field(int width = 0, int height = 0);
    void createVector(int w, int h);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVector<int>& operator[](int n) {return (v_field.begin()[n]);} // It's awesome! (suka, blyad)

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    int width, height;
    QVector< QVector<int> > v_field;

};

#endif // FIELD_H
