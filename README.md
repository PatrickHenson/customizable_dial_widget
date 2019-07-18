# customizable_dial_widget

The goal of this project is to provide a C++ / Qt dial widget that can easily be incorporated into any project.  

Launching the provided demo brings up a simple desktop application with several example dials.

The DialWidget class contains the core functionality and uses the following parameters to generate a simple, round, dial.

Parameters:

```
int side_length         // The dial is centered inside a QWidget with equilateral side lengths.
int min_value           // Minimum value displayed on the dial.
int max_value           // Maximum value displayed on the dial.
int minor_tick_count     // Number of short tick marks rendered.
int major_tick_count     // Number of long tick marks rendered.
int minor_tick_length    // Length of the short tick marks in pixels.
int major_tick_length    // Length of the long tick marks in pixels.
QColor dial_color       // The color of the dial's face.
QColor minor_tick_color  // Color of minor tick marks.
QColor major_tick_color  // Color of major tick marks.
QColor label_color      // Color of the font used for the labels.
QColor indicator_color  // Color of the indicator needle.
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

This project is available as open source under the terms of the [Apache 2.0 License](https://opensource.org/licenses/Apache-2.0)
