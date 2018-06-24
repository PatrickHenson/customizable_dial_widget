#pragma once

#include <QVector>
#include <QPoint>

// This header file contains the point vectors used to create several
// differently shaped dial hands.  These are just a few hardcoded examples that
// fit the size of the DialWidget used in the demonstration.  The points can
// easily be modified to be dependent upon the radius of the dial.
// Example use: painter->drawPolygon(Polygon(SELECTED_HAND));

const QVector<QPoint> DAUPHINE_HAND{
  QPoint( 0,   0),
  QPoint(-5, -20),
  QPoint( 0, -90),
  QPoint( 5, -20),
  QPoint( 0,   0)
};

const QVector<QPoint> SWORD_HAND{
  QPoint( 0,   0),
  QPoint(-1,   0),
  QPoint(-5, -75),
  QPoint( 0, -90),
  QPoint( 5, -75),
  QPoint( 1,   0),
  QPoint( 0,   0)
};

const QVector<QPoint> SYRINGE_HAND{
  QPoint( 0,   0),
  QPoint(-2,   0),
  QPoint(-2, -10),
  QPoint(-5, -10),
  QPoint(-5, -60),
  QPoint(-3, -65),
  QPoint( 0, -90),
  QPoint( 3, -65),
  QPoint( 5, -60),
  QPoint( 5, -10),
  QPoint( 2, -10),
  QPoint( 2,   0),
  QPoint( 0,   0)
};

const QVector<QPoint> LANCE_HAND{
  QPoint( 0,   0),
  QPoint(-1,   0),
  QPoint(-1, -10),
  QPoint(-5, -12),
  QPoint( 0, -90),
  QPoint( 5, -12),
  QPoint( 1, -10),
  QPoint( 1,   0),
  QPoint( 0,   0)
};
