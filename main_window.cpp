#include "main_window.h"

#include <QVBoxLayout>
#include "dial_widget.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  static const int DEMO_WINDOW_SIZE = 210;

  setFixedSize(DEMO_WINDOW_SIZE, DEMO_WINDOW_SIZE);

  QWidget *widget = new QWidget();
  setCentralWidget(widget);

  QVBoxLayout *layout = new QVBoxLayout();
  widget->setLayout(layout);

  DialWidget *dial = new DialWidget();
  layout->addWidget(dial);
}

MainWindow::~MainWindow()
{}
