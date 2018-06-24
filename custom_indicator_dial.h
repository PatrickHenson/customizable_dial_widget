#pragma once

#include "dial_widget.h"

// Demonstrate the ability to render the dial using different shapes for the
// indicator.  The input point vector initializes a QPolygon that is rendered
// by overriding drawIndicator function.
class CustomIndicatorDial : public DialWidget {
public:

  CustomIndicatorDial(QString        title,
                      QVector<QPoint>custom_indicator,
                      QWidget       *parent = 0);

protected:

  void paintEvent(QPaintEvent *);

  void drawIndicator(QPainter *painter);

private:

  const QPolygon m_INDICATOR;
};
