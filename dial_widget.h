#pragma once

#include <QWidget>
#include <QStringList>
#include <QPointF>

// The DialWidget programatically generates an analog dial using
// values defined by the constructor.

class DialWidget : public QWidget {
  Q_OBJECT

public:

  // Default constructor.  Reference the .cpp for predefined values.
  explicit DialWidget(QWidget *parent = 0);

  // Constructor that allows for custom configuration of the DialWidget.
  DialWidget(QString  title,
             QString  units,
             int      side_length,
             int      min_value,
             int      max_value,
             int      minor_tick_count,
             int      major_tick_count,
             int      minor_tick_length,
             int      major_tick_length,
             QColor   dial_color,
             QColor   minor_tick_color,
             QColor   major_tick_color,
             QColor   label_color,
             QColor   indicator_color,
             QWidget *parent = 0);

  // Return the minimum value displayed on the dial.
  int min_value();

  // Return the maximum value displayed on the dial.
  int max_value();

public slots:

  // Set the dial's current value.
  void setValue(double value);

protected:

  // Override the QWidget paint event to
  void paintEvent(QPaintEvent *);

  // Draw the face of the dial.
  void drawFace(QPainter *painter);

  // Draw the major and minor tick marks around the inner circumference of the
  // dial.
  void drawTickMarks(QPainter *painter);

  // Draw the title and units on the face of the dial.
  void drawTitleAndUnitLabels(QPainter *painter);

  // Draw the labels on the dial, adjusted for font size and character count.
  // Labels start at 0 and are placed at each major tick mark.
  // Override to use custom strings or placement.
  void drawValueLabels(QPainter *painter);

  // Draw the indicator needle that points to the current value.
  void drawIndicator(QPainter *painter);

private:

  // The following constant member variables are set during construction to
  // define how the dial is generated during the paint event.
  const QString m_TITLE;           // String title displayed on the dial face.
  const QString m_UNITS;           // Units for the values displayed on the
                                   // dail.
  const int m_SIDE_LENGTH;         // The dial is centered inside a QWidget with
                                   // equilateral side lengths.
  const int m_MIN_VALUE;           // Minimum value displayed on the dial.
  const int m_MAX_VALUE;           // Maximum value displayed on the dial.
  const int m_MINOR_TICK_COUNT;    // Number of short tick marks rendered.
  const int m_MAJOR_TICK_COUNT;    // Number of long tick marks rendered.
  const int m_MINOR_TICK_LENGTH;   // Length of the short tick marks in pixels.
  const int m_MAJOR_TICK_LENGTH;   // Length of the long tick marks in pixels.
  const QColor m_DIAL_COLOR;       // The color of the dial's face.
  const QColor m_MINOR_TICK_COLOR; // Color of minor tick marks.
  const QColor m_MAJOR_TICK_COLOR; // Color of major tick marks.
  const QColor m_LABEL_COLOR;      // Color of the font used for the labels.
  const QColor m_INDICATOR_COLOR;  // Color of the indicator needle.

  double m_value;                  // The current value displayed on the dial by
                                   // the indicator needle.

  // Calculate the position of a single point, evenly distributed along the
  // inside circumference of the dial.
  // count range is [ 0 : n ], n = m_NUM_MAJOR_TICKS
  void calculatePointOnCircumference(int      count,
                                     QPointF& position);
};
