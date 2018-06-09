#include "dial_widget.h"
#include "math.h"
#include <QPainter>

namespace {
const double DEGREES_IN_CIRCLE = 360.0;
}

DialWidget::DialWidget(QWidget *parent) :
  QWidget(parent),
  SIDE_LENGTH(200.0),
  MIN_VALUE(0),
  MAX_VALUE(100),
  NUM_MAJOR_TICKS((MAX_VALUE - MIN_VALUE) / 10),
  NUM_MINOR_TICKS(NUM_MAJOR_TICKS * 5),
  FACE_COLOR(Qt::black),
  MAJOR_TICK_COLOR(Qt::white),
  MINOR_TICK_COLOR(Qt::white),
  LABEL_COLOR(Qt::white),
  INDICATOR_COLOR(Qt::red)
{
  setFixedSize(SIDE_LENGTH, SIDE_LENGTH);
}

void DialWidget::paintEvent(QPaintEvent *)
{
  QPainter *painter = new QPainter(this);

  painter->setRenderHints(QPainter::Antialiasing, true);

  // Set the origin to the center of the dial widget
  painter->translate(SIDE_LENGTH / 2, SIDE_LENGTH / 2);

  drawFace(painter);
  drawTickMarks(painter);
  drawTextLabels(painter);
  drawIndicator(painter);

  painter->end();
}

void DialWidget::drawFace(QPainter *painter)
{
  QBrush brush(FACE_COLOR);

  painter->setBrush(brush);
  painter->setPen(QPen(Qt::gray, 2));

  // Translate leftwards and upwards 1/2 the side length to center the ellipse
  // on the origin.
  painter->drawEllipse(-SIDE_LENGTH / 2,
                       -SIDE_LENGTH / 2,
                       SIDE_LENGTH,
                       SIDE_LENGTH);
}

void DialWidget::drawTickMarks(QPainter *painter)
{
  // Define the size of major and minor tick marks in pixels.
  static const int MAJOR_TICK_SIZE = 8;
  static const int MINOR_TICK_SIZE = 2;

  painter->save();

  // Draw major tick marks on the dial.
  painter->setPen(QPen(MAJOR_TICK_COLOR, 2));

  for (int i = 0; i < NUM_MAJOR_TICKS; ++i)
  {
    painter->drawLine(0, SIDE_LENGTH / 2, 0, (SIDE_LENGTH / 2 - MAJOR_TICK_SIZE));
    painter->rotate(DEGREES_IN_CIRCLE / NUM_MAJOR_TICKS);
  }

  // Draw minor tick marks on the dial.
  painter->setPen(QPen(MINOR_TICK_COLOR, 2));

  for (int i = 0; i < NUM_MINOR_TICKS; ++i)
  {
    painter->drawLine(0, SIDE_LENGTH / 2, 0, (SIDE_LENGTH / 2 - MINOR_TICK_SIZE));
    painter->rotate(DEGREES_IN_CIRCLE / NUM_MINOR_TICKS);
  }

  painter->restore();
}

void DialWidget::drawTextLabels(QPainter *painter)
{
  static const int INCREMENT = (MAX_VALUE - MIN_VALUE) / NUM_MAJOR_TICKS;
  static const int FONT_SIZE = 10;

  painter->setFont(QFont("Helvetica", FONT_SIZE));
  painter->setPen(QPen(LABEL_COLOR, 1));

  QPointF position;

  for (int i = 0; i < NUM_MAJOR_TICKS; ++i)
  {
    calculatePositionOnCircle(i, position);
    painter->drawText(position.x(), position.y(), QString::number(INCREMENT * i));
  }
}

void DialWidget::drawIndicator(QPainter *painter)
{
  static const int INDICATOR_LENGTH = SIDE_LENGTH / 2 - 10;

  painter->save();
  painter->setPen(QPen(INDICATOR_COLOR, 2));
  painter->drawLine(0, 0, 0, -INDICATOR_LENGTH);
  painter->restore();
}

void DialWidget::calculatePositionOnCircle(int count, QPointF& position)
{
  static const int INTERIOR_PADDING = 15;
  static const int INTERIOR_RADIUS  =  (SIDE_LENGTH - INTERIOR_PADDING) / 2;

  static const double ANGLE  = 2 * M_PI / NUM_MAJOR_TICKS;
  static const double OFFSET = M_PI / 2;

  position.setX(INTERIOR_RADIUS * cos(ANGLE * count - OFFSET));
  position.setY(INTERIOR_RADIUS * sin(ANGLE * count - OFFSET));
}
