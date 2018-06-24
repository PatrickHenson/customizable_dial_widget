#include "square_dial.h"

#include <QColor>
#include <QPainter>

namespace {
const int MIN_VALUE           = 0;
const int MAX_VALUE           = 10;
const int MINOR_TICK_COUNT    = 50;
const int MAJOR_TICK_COUNT    = 10;
const int MINOR_TICK_LENGTH   = 2;
const int MAJOR_TICK_LENGTH   = 8;
const QColor DIAL_COLOR       = Qt::black;
const QColor MINOR_TICK_COLOR = Qt::white;
const QColor MAJOR_TICK_COLOR = Qt::white;
const QColor LABEL_COLOR      = Qt::white;
const QColor INDICATOR_COLOR  = Qt::blue;

const int PEN_SIZE      = 2;
const int CORNER_RADIUS = 10;
}

SquareDial::SquareDial(int side_length, QWidget *parent) :
  DialWidget(
    QString(),
    QString(),
    side_length,
    MIN_VALUE,
    MAX_VALUE,
    MINOR_TICK_COUNT,
    MAJOR_TICK_COUNT,
    MINOR_TICK_LENGTH,
    MAJOR_TICK_LENGTH,
    DIAL_COLOR,
    MINOR_TICK_COLOR,
    MAJOR_TICK_COLOR,
    LABEL_COLOR,
    INDICATOR_COLOR,
    parent),
  m_SIDE_LENGTH(side_length)
{}

void SquareDial::paintEvent(QPaintEvent *)
{
  QPainter *painter = new QPainter(this);

  painter->setRenderHints(QPainter::Antialiasing, true);

  // Set the origin to the center of the dial widget
  painter->translate(m_SIDE_LENGTH / 2, m_SIDE_LENGTH / 2);

  drawFace(painter);
  drawTickMarks(painter);
  drawTitleAndUnitLabels(painter);
  drawValueLabels(painter);
  drawIndicator(painter);

  painter->end();
}

void SquareDial::drawFace(QPainter *painter)
{
  QBrush brush(DIAL_COLOR);

  painter->setBrush(brush);
  painter->setPen(QPen(Qt::gray, PEN_SIZE));

  // Translate the ellipse to center it on the origin.
  painter->drawRoundedRect(-m_SIDE_LENGTH / 2,
                           -m_SIDE_LENGTH / 2,
                           m_SIDE_LENGTH,
                           m_SIDE_LENGTH,
                           CORNER_RADIUS,
                           CORNER_RADIUS);
}
