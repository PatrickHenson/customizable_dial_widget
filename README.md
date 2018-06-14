# customizable_dial_widget

The goal of this project is to provide a C++ / Qt dial widget that can easily be incorporated into any project.  

Launching the provided demo brings up a simple desktop application with several example dials.

The DialWidget class contains the core functionality and uses the following parameters to generate a simple, round, dial.

Parameters:

```
int sideLength         // The dial is centered inside a QWidget with equilateral side lengths.
int minValue           // Minimum value displayed on the dial.
int maxValue           // Maximum value displayed on the dial.
int minorTickCount     // Number of short tick marks rendered.
int majorTickCount     // Number of long tick marks rendered.
int minorTickLength    // Length of the short tick marks in pixels.
int majorTickLength    // Length of the long tick marks in pixels.
QColor dialColor       // The color of the dial's face.
QColor minorTickColor  // Color of minor tick marks.
QColor majorTickColor  // Color of major tick marks.
QColor labelColor      // Color of the font used for the labels.
QColor indicatorColor  // Color of the indicator needle.
```

In addition, I have provided several classes demonstrating how the DialWidget can be further customized.  

```
SquareDial  // Generate the dial centered in a square bezel.
```

![base dial](/demo_images/dials.png "Base DialWidget")

## Prerequisites
- GIT
- Qt Creator

## Build & Run

To build the project:

* Open the project (.pro) file in Qt Creator

* Run qmake

* Build and Run by pressing 'F5', using the 'play' button, or navigating to Build->Run in the menu.

## Tests

This project currently does not contain automated software tests.

## Authors

**Patrick Henson** - Initial author and contributor.

## License

This project is available as open source under the terms of the [Apache 2.0 Licesnse](https://opensource.org/licenses/Apache-2.0)
