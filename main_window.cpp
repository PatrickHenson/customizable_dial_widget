#include "main_window.h"

#include <QVBoxLayout>
#include <QDoubleSpinBox>
#include "dial_widget.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  static const int DEMO_WINDOW_X = 210;
  static const int DEMO_WINDOW_Y = 250;

  setFixedSize(DEMO_WINDOW_X, DEMO_WINDOW_Y);

  QWidget *widget = new QWidget();
  setCentralWidget(widget);

  QVBoxLayout *layout = new QVBoxLayout();
  widget->setLayout(layout);

  DialWidget *dial = new DialWidget();
  layout->addWidget(dial);

  QDoubleSpinBox *dialInput = new QDoubleSpinBox();
  dialInput->setRange(dial->minValue(), dial->maxValue());
  dialInput->setSingleStep(10);
  layout->addWidget(dialInput);

  QObject::connect(dialInput, SIGNAL(valueChanged(double)), dial, SLOT(setValue(double)), Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{}
