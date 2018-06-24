#include "main_window.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "demo_control.h"
#include "dial_widget.h"
#include "square_dial.h"

#include "polygon_indicators.h"
#include "custom_indicator_dial.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  // Setup the demo application.
  createLayout();

  // Set the window to fit the demo contents.
  adjustSize();
}

MainWindow::~MainWindow()
{}

void MainWindow::createLayout()
{
  QWidget *widget = new QWidget();

  setCentralWidget(widget);

  QVBoxLayout *layout = new QVBoxLayout();
  widget->setLayout(layout);

  // Demonstrate different dial shapes
  QHBoxLayout *shape_row = new QHBoxLayout();
  layout->addLayout(shape_row);

  shape_row->addWidget(new DemoControl(new DialWidget(200)));

  shape_row->addWidget(new DemoControl(new DialWidget(100)));

  shape_row->addWidget(new DemoControl(new SquareDial(200)));

  shape_row->addWidget(new DemoControl(new SquareDial(100)));

  // Demonstrate ability to use different indicators on the dial.
  QHBoxLayout *indicator_row = new QHBoxLayout();
  layout->addLayout(indicator_row);

  indicator_row->addWidget(new DemoControl(new CustomIndicatorDial("Dauphine Hand",
                                                                   DAUPHINE_HAND)));
  indicator_row->addWidget(new DemoControl(new CustomIndicatorDial("Sword Hand",
                                                                   SWORD_HAND)));
  indicator_row->addWidget(new DemoControl(new CustomIndicatorDial("Syringe Hand",
                                                                   SYRINGE_HAND)));
  indicator_row->addWidget(new DemoControl(new CustomIndicatorDial("Lance Hand",
                                                                   LANCE_HAND)));

  // Demonstrate several 'useful' dials
  QHBoxLayout *useful_dials = new QHBoxLayout();
  layout->addLayout(useful_dials);

  DialWidget *pressure_dial = new DialWidget("Pressure",
                                             "PSI",
                                             200,
                                             0,
                                             300,
                                             50,
                                             10,
                                             2,
                                             8,
                                             Qt::blue,
                                             Qt::white,
                                             Qt::white,
                                             Qt::white,
                                             Qt::black);
  useful_dials->addWidget(new DemoControl(pressure_dial));
}
