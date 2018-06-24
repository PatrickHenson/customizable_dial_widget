#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

// The MainWindow creates a simple desktop application that is used to
// demonstrate the functionality of the DialWidget and it's customizability.
class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:

  // Control the placement of widgets within the application.
  void createLayout();
};
