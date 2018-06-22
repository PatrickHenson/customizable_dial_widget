#include "demo_control.h"
#include <QVBoxLayout>
#include <QDoubleSpinBox>

namespace {
const int DEMO_WIDGET_X = 210;
const int DEMO_WIDGET_Y = 250;
const int STEP_SIZE     = 5;
}

DemoControl::DemoControl(DialWidget *dial, QWidget *parent) : QWidget(parent),
  m_dial(dial)
{
  setFixedSize(DEMO_WIDGET_X, DEMO_WIDGET_Y);

  createLayout();
}

DemoControl::~DemoControl()
{
  delete m_dial;
}

void DemoControl::createLayout()
{
  QVBoxLayout *layout = new QVBoxLayout();

  setLayout(layout);

  layout->addWidget(m_dial);

  QDoubleSpinBox *dial_input = new QDoubleSpinBox();
  dial_input->setRange(m_dial->min_value(), m_dial->max_value());
  dial_input->setSingleStep(STEP_SIZE);
  layout->addWidget(dial_input);

  QObject::connect(dial_input, SIGNAL(valueChanged(double)), m_dial,
                   SLOT(setValue(double)), Qt::UniqueConnection);
}
