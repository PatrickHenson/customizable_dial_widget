#pragma once

#include <QWidget>
#include "dial_widget.h"

// Create a controller connecting the DialWidget to a QDoubleSpinbox, allowing
// users to demo adjusting the value of the dial.
class DemoControl : public QWidget {
  Q_OBJECT

public:

  explicit DemoControl(DialWidget *dial,
                       QWidget    *parent = 0);
  ~DemoControl();

private:

  DialWidget *m_dial;

  void createLayout();
};
