#include "custom_indicator_dial.h"

#include <QPainter>
#include <QVector>
#include <QPoint>

namespace {
const int SIDE_LENGTH         = 200;
const int MIN_VALUE           = 0;
const int MAX_VALUE           = 100;
const int MINOR_TICK_COUNT    = 50;
const int MAJOR_TICK_COUNT    = 10;
const int MINOR_TICK_LENGTH   = 2;
const int MAJOR_TICK_LENGTH   = 8;
const QColor DIAL_COLOR       = Qt::black;
const QColor MINOR_TICK_COLOR = Qt::white;
const QColor MAJOR_TICK_COLOR = Qt::white;
const QColor LABEL_COLOR      = Qt::white;
const QColor INDICATOR_COLOR  = Qt::white;

const double DEGREES_IN_CIRCLE = 360.0;
}

CustomIndicatorDial::CustomIndicatorDial(QString        title,
                                         QVector<QPoint>custom_indicator,
                                         QWidget       *parent) :
  DialWidget(
    title,
    QString(),
    SIDE_LENGTH,
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
    INDICATOR_COLOR, parent),
  m_INDICATOR(QPolygon(custom_indicator))
{}

void CustomIndicatorDial::paintEvent(QPaintEvent *)
{
  QPainter *painter = new QPainter(this);

  painter->setRenderHints(QPainter::Antialiasing, true);

  // Set the origin to the center of the dial widget
  painter->translate(SIDE_LENGTH / 2, SIDE_LENGTH / 2);

  drawFace(painter);
  drawTickMarks(painter);
  drawTitleAndUnitLabels(painter);
  drawValueLabels(painter);
  drawIndicator(painter);

  painter->end();
}

void CustomIndicatorDial::drawIndicator(QPainter *painter)
{
  painter->save();

  // painter->setPen(QPen(INDICATOR_COLOR, 2));
  painter->setPen(Qt::NoPen);
  painter->setBrush(INDICATOR_COLOR);

  // Rotate the painter to the angle associated with the current value set on
  // the dial.
  double stepSize = DEGREES_IN_CIRCLE / (MAX_VALUE - MIN_VALUE);
  painter->rotate(currentValue() * stepSize);

  // Draw the custom indicator set by the constructor.
  painter->drawPolygon(m_INDICATOR);

  painter->restore();
}
