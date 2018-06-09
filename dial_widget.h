#pragma once

#include <QWidget>
#include <QStringList>
#include <QPointF>

class DialWidget : public QWidget {
public:

  explicit DialWidget(QWidget *parent = 0);

protected:

  void paintEvent(QPaintEvent *);
  void drawFace(QPainter *painter);
  void drawTickMarks(QPainter *painter);
  void drawTextLabels(QPainter *painter);
  void drawIndicator(QPainter *painter);

private:

  const int SIDE_LENGTH;     // Dial is rendered using equilateral side lengths
  const int MIN_VALUE;       // Minimum value displayed on the dial
  const int MAX_VALUE;       // Maximum value displayed on the dial
  const int NUM_MAJOR_TICKS; // Number of long tick marks rendered
  const int NUM_MINOR_TICKS; // Number of short tick marks rendered

  const QColor FACE_COLOR;
  const QColor MAJOR_TICK_COLOR;
  const QColor MINOR_TICK_COLOR;
  const QColor LABEL_COLOR;
  const QColor INDICATOR_COLOR;

  // Calculate n evenly distributed points along the inside circumference
  // of the dial.  n = NUM_MAJOR_TICKS
  void calculatePointOnCircumference(int      count,
                                     QPointF& position);
};
