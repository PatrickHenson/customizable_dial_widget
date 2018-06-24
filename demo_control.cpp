#include "demo_control.h"
#include <QVBoxLayout>
#include <QDoubleSpinBox>

namespace {
const int DEMO_WIDGET_X = 210;
const int DEMO_WIDGET_Y = 250;
const int STEP_SIZE     = 1;
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

  layout->setSizeConstraint(QLayout::SetFixedSize);
  setLayout(layout);

  // Add dial to layout.
  layout->addWidget(m_dial);

  // Add input to layout.
  QDoubleSpinBox *dial_input = new QDoubleSpinBox();
  dial_input->setRange(m_dial->minValue(), m_dial->maxValue());
  dial_input->setSingleStep(STEP_SIZE);
  layout->addWidget(dial_input);

  // Connect valueChanged signal from the input to the setValue slot on the
  // dial.
  QObject::connect(dial_input, SIGNAL(valueChanged(double)), m_dial,
                   SLOT(setValue(double)), Qt::UniqueConnection);
}
