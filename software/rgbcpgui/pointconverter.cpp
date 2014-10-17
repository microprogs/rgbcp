#include "pointconverter.h"
#include <QtCore>

PointConverter::PointConverter()
{
    initMap();
}

PointConverter::~PointConverter()
{
}

int PointConverter::matrixRowCount() const
{
    return 10;
}

int PointConverter::matrixColCount() const
{
    return 3;
}

int PointConverter::screenLedRadius() const
{
    return 30;
}

QRect PointConverter::delayRect() const
{
    return QRect(5, 5, 70, 50);
}

int PointConverter::screenWidth() const
{
    return 990;
}

int PointConverter::screenHeight() const
{
    return 405;
}

void PointConverter::initMap()
{
    const double base_x = 30.0;
    const double base_y = 5.0;

    const double scale_x = 1.0;
    const double scale_y = 1.0;

    initPoints(mapMatrixToScreen_, QPointF(base_x, base_y), QPointF(scale_x, scale_y));
}

void PointConverter::initPoints(QVector<QVector<QPoint> > &matrix, const QPointF &pos, const QPointF &scale)
{
    matrix.clear();
    for (int i = 0; i < matrixRowCount(); ++i)
        matrix.append(QVector<QPoint>(matrixColCount()));

    matrix[0][0] = QPoint(96, 57);   // (row0_9, col0_2)=(0, 0)
    matrix[0][1] = QPoint(375, 57);  // (row0_9, col0_2)=(0, 1)
    matrix[0][2] = QPoint(749, 73);  // (row0_9, col0_2)=(0, 2)

    matrix[1][0] = QPoint(168, 57);  // (row0_9, col0_2)=(1, 0)
    matrix[1][1] = QPoint(588, 57);  // (row0_9, col0_2)=(1, 1)
    matrix[1][2] = QPoint(825, 57);  // (row0_9, col0_2)=(1, 2)

    matrix[2][0] = QPoint(45, 153);  // (row0_9, col0_2)=(2, 0)
    matrix[2][1] = QPoint(375, 138); // (row0_9, col0_2)=(2, 1)
    matrix[2][2] = QPoint(902, 57);  // (row0_9, col0_2)=(2, 2)

    matrix[3][0] = QPoint(218, 153); // (row0_9, col0_2)=(3, 0)
    matrix[3][1] = QPoint(588, 138); // (row0_9, col0_2)=(3, 1)
    matrix[3][2] = QPoint(733, 158); // (row0_9, col0_2)=(3, 2)

    matrix[4][0] = QPoint(25, 244);  // (row0_9, col0_2)=(4, 0)
    matrix[4][1] = QPoint(436, 198); // (row0_9, col0_2)=(4, 1)
    matrix[4][2] = QPoint(902, 158); // (row0_9, col0_2)=(4, 2)

    matrix[5][0] = QPoint(96, 244);  // (row0_9, col0_2)=(5, 0)
    matrix[5][1] = QPoint(527, 198); // (row0_9, col0_2)=(5, 1)
    matrix[5][2] = QPoint(810, 205); // (row0_9, col0_2)=(5, 2)

    matrix[6][0] = QPoint(168, 244); // (row0_9, col0_2)=(6, 0)
    matrix[6][1] = QPoint(375, 260); // (row0_9, col0_2)=(6, 1)
    matrix[6][2] = QPoint(760, 270); // (row0_9, col0_2)=(6, 2)

    matrix[7][0] = QPoint(239, 244); // (row0_9, col0_2)=(7, 0)
    matrix[7][1] = QPoint(588, 260); // (row0_9, col0_2)=(7, 1)
    matrix[7][2] = QPoint(902, 250); // (row0_9, col0_2)=(7, 2)

    matrix[8][0] = QPoint(25, 341);  // (row0_9, col0_2)=(8, 0)
    matrix[8][1] = QPoint(375, 341); // (row0_9, col0_2)=(8, 1)
    matrix[8][2] = QPoint(719, 341); // (row0_9, col0_2)=(8, 2)

    matrix[9][0] = QPoint(239, 341); // (row0_9, col0_2)=(9, 0)
    matrix[9][1] = QPoint(588, 341); // (row0_9, col0_2)=(9, 1)
    matrix[9][2] = QPoint(902, 341); // (row0_9, col0_2)=(9, 2)

    for (int i = 0; i < matrixRowCount(); ++i)
    {
        for (int j = 0; j < matrixColCount(); ++j)
        {
            matrix[i][j].setX(qRound(matrix[i][j].x() * scale.x() + pos.x()));
            matrix[i][j].setY(qRound(matrix[i][j].y() * scale.y() + pos.y()));
        }
    }
}

bool PointConverter::matrixPointToScreenPoint(int row, int col, QPoint &screenPoint) const
{
    screenPoint = QPoint(0, 0);

    if (row >= 0 && row < matrixRowCount() && col >= 0 && col < matrixColCount())
    {
        screenPoint = mapMatrixToScreen_[row][col];
        return true;
    }

    return false;
}

bool PointConverter::isPointDelay(QPoint point) const
{
    return delayRect().contains(point);
}

bool PointConverter::isPointLed(QPoint point, int &matrix_row, int &matrix_col) const
{
    matrix_row = 0;
    matrix_col = 0;

    bool res = false;

    const QVector<QPoint> ledPoints = screenLedPointsList();

    for (int i = 0; i < ledPoints.size(); ++i)
    {
        const QPoint p = ledPoints[i];
        const int dist = qRound(calcDistanceBetweenPoints(point, p));
        if (dist <= screenLedRadius())
        {
            int row = 0, col = 0;
            if (screenPointToMatrixPoint(p, row, col))
            {
                matrix_row = row;
                matrix_col = col;
                res = true;
                break;
            }
        }
    }

    return res;
}

double PointConverter::calcDistanceBetweenPoints(const QPoint &p1, const QPoint &p2) const
{
    const double x1x2 = p1.x() - p2.x();
    const double y1y2 = p1.y() - p2.y();

    return qSqrt(x1x2*x1x2 + y1y2*y1y2);
}

bool PointConverter::screenPointToMatrixPoint(const QPoint &screenPoint, int &matrix_row, int &matrix_col) const
{
    matrix_row = 0;
    matrix_col = 0;

    for (int i = 0; i < matrixRowCount(); ++i)
    {
        for (int j = 0; j < matrixColCount(); ++j)
        {
            if (mapMatrixToScreen_[i][j] == screenPoint)
            {
                matrix_row = i;
                matrix_col = j;
                return true;
            }
        }
    }

    return false;
}

QVector<QPoint> PointConverter::screenLedPointsList() const
{
    QVector<QPoint> points;

    for (int i = 0; i < matrixRowCount(); ++i)
    {
        for (int j = 0; j < matrixColCount(); ++j)
        {
            points.append(mapMatrixToScreen_[i][j]);
        }
    }

    return points;
}
