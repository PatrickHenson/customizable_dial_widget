#include "dial_widget.h"
#include "math.h"
#include <QPainter>

namespace {
const double DEGREES_IN_CIRCLE = 360.0;
const int    PEN_SIZE          = 2;
static const int FONT_SIZE     = 10;
}

DialWidget::DialWidget(QWidget *parent) :
  QWidget(parent),
  m_TITLE(QString()),
  m_UNITS(QString()),
  m_SIDE_LENGTH(200.0),
  m_MIN_VALUE(0),
  m_MAX_VALUE(100),
  m_MINOR_TICK_COUNT(50),
  m_MAJOR_TICK_COUNT(10),
  m_MINOR_TICK_LENGTH(2),
  m_MAJOR_TICK_LENGTH(8),
  m_DIAL_COLOR(Qt::black),
  m_MINOR_TICK_COLOR(Qt::white),
  m_MAJOR_TICK_COLOR(Qt::white),
  m_LABEL_COLOR(Qt::white),
  m_INDICATOR_COLOR(Qt::red)
{
  setFixedSize(m_SIDE_LENGTH, m_SIDE_LENGTH);
  m_value = m_MIN_VALUE;
}

DialWidget::DialWidget(QString  title,
                       QString  units,
                       int      side_length,
                       int      min_value,
                       int      max_value,
                       int      minor_tick_count,
                       int      major_tick_count,
                       int      minor_tick_length,
                       int      major_tick_length,
                       QColor   dial_color,
                       QColor   minor_tick_color,
                       QColor   major_tick_color,
                       QColor   label_color,
                       QColor   indicator_color,
                       QWidget *parent) :
  QWidget(parent),
  m_TITLE(title),
  m_UNITS(units),
  m_SIDE_LENGTH(side_length),
  m_MIN_VALUE(min_value),
  m_MAX_VALUE(max_value),
  m_MINOR_TICK_COUNT(minor_tick_count),
  m_MAJOR_TICK_COUNT(major_tick_count),
  m_MINOR_TICK_LENGTH(minor_tick_length),
  m_MAJOR_TICK_LENGTH(major_tick_length),
  m_DIAL_COLOR(dial_color),
  m_MINOR_TICK_COLOR(minor_tick_color),
  m_MAJOR_TICK_COLOR(major_tick_color),
  m_LABEL_COLOR(label_color),
  m_INDICATOR_COLOR(indicator_color)
{
  setFixedSize(m_SIDE_LENGTH, m_SIDE_LENGTH);
  m_value = m_MIN_VALUE;
}

void DialWidget::setValue(double value)
{
  if ((value >= m_MIN_VALUE) && (value <= m_MAX_VALUE))
  {
    m_value = value;
    update();
  }
}

int DialWidget::min_value()
{
  return m_MIN_VALUE;
}

int DialWidget::max_value()
{
  return m_MAX_VALUE;
}

void DialWidget::paintEvent(QPaintEvent *)
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

void DialWidget::drawFace(QPainter *painter)
{
  QBrush brush(m_DIAL_COLOR);

  painter->setBrush(brush);
  painter->setPen(QPen(Qt::gray, PEN_SIZE));

  // Translate the ellipse to center it on the origin.
  painter->drawEllipse(-m_SIDE_LENGTH / 2,
                       -m_SIDE_LENGTH / 2,
                       m_SIDE_LENGTH,
                       m_SIDE_LENGTH);
}

void DialWidget::drawTickMarks(QPainter *painter)
{
  painter->save();

  // Draw minor tick marks on the dial.
  painter->setPen(QPen(m_MINOR_TICK_COLOR, PEN_SIZE));

  const int MINOR_TICK_START = m_SIDE_LENGTH / 2 - PEN_SIZE;
  const int MINOR_TICK_STOP  = MINOR_TICK_START - m_MINOR_TICK_LENGTH;

  for (int i = 0; i < m_MINOR_TICK_COUNT; ++i)
  {
    painter->drawLine(0, MINOR_TICK_START, 0, MINOR_TICK_STOP);
    painter->rotate(DEGREES_IN_CIRCLE / m_MINOR_TICK_COUNT);
  }

  // Draw major tick marks on the dial.
  painter->setPen(QPen(m_MAJOR_TICK_COLOR, PEN_SIZE));

  const int MAJOR_TICK_START = m_SIDE_LENGTH / 2 - PEN_SIZE;
  const int MAJOR_TICK_STOP  = MAJOR_TICK_START - m_MAJOR_TICK_LENGTH;

  for (int i = 0; i < m_MAJOR_TICK_COUNT; ++i)
  {
    painter->drawLine(0, MAJOR_TICK_START, 0, MAJOR_TICK_STOP);
    painter->rotate(DEGREES_IN_CIRCLE / m_MAJOR_TICK_COUNT);
  }

  painter->restore();
}

void DialWidget::drawTitleAndUnitLabels(QPainter *painter)
{
  QFont font = QFont("Helvetica", FONT_SIZE);
  QFontMetrics fontMetrics(font);

  painter->setFont(font);
  painter->setPen(QPen(m_LABEL_COLOR, 1));

  double x = 0;
  double y = 0;

  if (!m_TITLE.isEmpty())
  {
    x = -fontMetrics.width(m_TITLE) / 2;
    y = -25;
    painter->drawText(x, y, m_TITLE);
  }

  if (!m_UNITS.isEmpty())
  {
    x = -fontMetrics.width(m_UNITS) / 2;
    y = 25;
    painter->drawText(x, y, m_UNITS);
  }
}

void DialWidget::drawValueLabels(QPainter *painter)
{
  const int INCREMENT = (m_MAX_VALUE - m_MIN_VALUE) / m_MAJOR_TICK_COUNT;

  QFont font = QFont("Helvetica", FONT_SIZE);
  QFontMetrics fontMetrics(font);

  painter->setFont(font);
  painter->setPen(QPen(m_LABEL_COLOR, 1));

  QPointF position;

  for (int i = 0; i < m_MAJOR_TICK_COUNT; ++i)
  {
    QString label = QString::number(INCREMENT * i);

    // Calculate the x,y coordinates on interior circumference of the dial
    calculatePointOnCircumference(i, position);

    // Offset the position of the label, shifting it based upon the font size
    // and placement on the dial
    double x = position.x();
    double y = position.y() + FONT_SIZE / 2;

    if (i == 0)
    {
      x -= fontMetrics.width(label) / 2;
      y += FONT_SIZE / 2;
    }
    else if (i == m_MAJOR_TICK_COUNT / 2)
    {
      x -= fontMetrics.width(label) / 2;
      y -= FONT_SIZE / 2;
    }
    else if (i < m_MAJOR_TICK_COUNT / 2)
    {
      x -= fontMetrics.width(label);
    }

    painter->drawText(x, y, label);
  }
}

void DialWidget::drawIndicator(QPainter *painter)
{
  static const int INDICATOR_LENGTH = m_SIDE_LENGTH / 2 - 10;

  painter->save();

  painter->setPen(QPen(m_INDICATOR_COLOR, 2));
  painter->setBrush(m_INDICATOR_COLOR);

  // Draw a dot on the origin at the base of the indicator.
  painter->drawEllipse(-PEN_SIZE, -PEN_SIZE, PEN_SIZE * 2, PEN_SIZE * 2);

  // Draw the indicator rotated to point at the current value.
  double stepSize = DEGREES_IN_CIRCLE / (m_MAX_VALUE - m_MIN_VALUE);
  painter->rotate(m_value * stepSize);
  painter->drawLine(0, 0, 0, -INDICATOR_LENGTH);

  painter->restore();
}

void DialWidget::calculatePointOnCircumference(int count, QPointF& position)
{
  static const int INTERIOR_PADDING = 25;
  static const int INTERIOR_RADIUS  =  (m_SIDE_LENGTH - INTERIOR_PADDING) / 2;

  static const double ANGLE  = 2 * M_PI / m_MAJOR_TICK_COUNT;
  static const double OFFSET = M_PI / 2;

  position.setX(INTERIOR_RADIUS * cos(ANGLE * count - OFFSET));
  position.setY(INTERIOR_RADIUS * sin(ANGLE * count - OFFSET));
}
