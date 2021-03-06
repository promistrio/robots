#include "robot.h"


int Robot::x()
{
    return this->pos.x();
}

int Robot::y()
{
    return this->pos.y();
}

QString Robot::color()
{
    return this->s_color;
}

void Robot::changePos()
{
    this->pos.setX(this->pos.x() - 1);
}


bool Robot::calculatePath(QVector<QVector<int> > *  v_field, int bx, int by)
{
    /*QTime start = QTime::currentTime();

    int ax = pos.x();
    int ay = pos.y();

    int W = 80;
    int H = 40;
    int px[W * H], py[W * H];      // координаты ячеек, входящих в путь
    int len;                       // длина пути

    // Перед вызовом lee() массив grid заполнен значениями WALL и BLANK
    int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};   // справа, снизу, слева и сверху
    int d, x, y, k;
    bool stop;

    if (v_field[ax][ay] == WALL || v_field[bx][by] == WALL) return false;  // ячейка (ax, ay) или (bx, by) - стена

    // распространение волны
    d = 0;
    v_field[ax][ay] = 0;            // стартовая ячейка помечена 0
    do {
        stop = true;               // предполагаем, что все свободные клетки уже помечены
        for ( y = 0; y < H; ++y )
            for ( x = 0; x < W; ++x )
                if ( v_field[x][y] == d )                         // ячейка (x, y) помечена числом d
                {
                    for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
                    {
                        int iy=y + dy[k], ix = x + dx[k];
                        if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
                             v_field[ix][iy] == BLANK )
                        {
                            stop = false;              // найдены непомеченные клетки
                            v_field[ix][iy] = d + 1;      // распространяем волну
                        }
                    }
                }
        d++;
    } while ( !stop && v_field[bx][by] == BLANK );

    if (v_field[bx][by] == BLANK) qDebug() <<  "Печаль-беда";  // путь не найден

    // восстановление пути
    len = v_field[bx][by];            // длина кратчайшего пути из (ax, ay) в (bx, by)
    x = bx;
    y = by;
    d = len;
    while ( d > 0 )
    {
        px[d] = x;
        py[d] = y;                   // записываем ячейку (x, y) в путь
        d--;
        for (k = 0; k < 4; ++k)
        {
            int iy=y + dy[k], ix = x + dx[k];
            if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
                 v_field[ix][iy] == d)
            {
                x = x + dx[k];
                y = y + dy[k];           // переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    px[0] = ax;
    py[0] = ay;                    // теперь px[0..len] и py[0..len] - координаты ячеек пути


    /*QModelIndex left = createIndex(0, 0);
        QModelIndex right = createIndex(this->height * this->width, 0);
        emit dataChanged(left, right);*/

    //qDebug() << "прошло " << start.elapsed() << " милисекунд";
    return true;
}
