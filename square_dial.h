#pragma once

#include "dial_widget.h"

// Customize the DialWidget by rendering the dial on a square face with a blue
// indicator.
class SquareDial : public DialWidget {
public:

  SquareDial();

protected:

  // Override the DialWidget's paint event to ensure that the SquareDial's
  // drawFace method is called.
  void paintEvent(QPaintEvent *);

  // Draw the face of the dial.
  void drawFace(QPainter *painter);
};
