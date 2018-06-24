#pragma once

#include "dial_widget.h"

// Customize the DialWidget by rendering the dial on a square face with a blue
// indicator.
class SquareDial : public DialWidget {
public:

  explicit SquareDial(int      side_length,
                      QWidget *parent = 0);

protected:

  // Override the DialWidget's paint event to ensure that the SquareDial's
  // drawFace method is called.
  void paintEvent(QPaintEvent *);

  // Draw the face of the dial.
  void drawFace(QPainter *painter);

  const int m_SIDE_LENGTH;
};
