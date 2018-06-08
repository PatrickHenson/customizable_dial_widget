#pragma once

#include <QWidget>

class DialWidget : public QWidget
{
public:
  DialWidget();

protected:
  void paintEvent(QPaintEvent *);

private:
  const int SIDE_LENGTH;  // Dial is rendered using equilateral side lengths
  const int MIN_VALUE;    // Minimum value displayed on the dial
  const int MAX_VALUE;    // Maximum value displayed on the dial
  const int NUM_MAJOR_TICKS;
  const int NUM_MINOR_TICKS;

  const QColor  FACE_COLOR;
  const QColor  MAJOR_TICK_COLOR;
  const QColor  MINOR_TICK_COLOR;
  const QColor  INDICATOR_COLOR;

  void drawFace(QPainter *painter);
  void drawTickMarks(QPainter *painter);
  void drawTextLabels(QPainter *painter);
  void drawIndicator(QPainter *painter);
};
