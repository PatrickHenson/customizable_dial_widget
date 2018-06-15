#include "main_window.h"

#include <QHBoxLayout>

#include <demo_control.h>
#include "dial_widget.h"
#include "square_dial.h"

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

  QHBoxLayout *layout = new QHBoxLayout();
  widget->setLayout(layout);

  layout->addWidget(new DemoControl(new DialWidget));
  layout->addWidget(new DemoControl(new SquareDial));

  DialWidget *pressureDial = new DialWidget("Pressure",
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
  layout->addWidget(new DemoControl(pressureDial));
}
