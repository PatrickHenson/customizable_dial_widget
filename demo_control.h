#pragma once

#include <QWidget>
#include "dial_widget.h"

// Create a controller connecting the DialWidget to a QDoubleSpinbox, allowing
// the user to adjust the value displayed on the dial in the demo application.
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
