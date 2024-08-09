# LED Light Control with Arduino and Mobile App

## Description

This project involves controlling a multicolor LED light strip using an Arduino and a mobile app. The app, which can be built as an APK, connects to an HC-05 Bluetooth module to communicate with the Arduino. The light strip can be powered externally, and its data pin is connected to the Arduino. The light patterns can be changed through the mobile app.

## Features

- **Multicolor Lighting**: The LED strip starts with a multicolor light pattern.
- **Mobile App Control**: The lighting patterns can be controlled using a mobile app via Bluetooth.
- **Adjustable Brightness**: Change the brightness of the LED strip through the app.
- **Customizable Light Patterns**: Different light patterns such as color chase, random colors, and twinkling effects can be selected.

## Hardware Required

- **Arduino Board** (e.g., Arduino Uno, Nano, etc.)
- **HC-05 Bluetooth Module**
- **WS2812B LED Strip** (or similar addressable LED strip)
- **External Power Supply** for the LED strip
- **Connecting Wires**

## Software Required

- **Arduino IDE** for uploading the code to the Arduino
- **MIT App Inventor** or similar tool to build the mobile app
- **Bluetooth Terminal App** (optional, for testing)

## Instructions

1. **Connect the LED Strip**:
   - Connect the data pin of the LED strip to the Arduino pin defined as `DATA_PIN` in the code.
   - Power the LED strip using an external power supply suitable for your LED strip's requirements.

2. **Connect the HC-05 Bluetooth Module**:
   - Connect the HC-05 module to the Arduino using appropriate pins (TX, RX, VCC, and GND).

3. **Upload the Code**:
   - Open the provided Arduino code in the Arduino IDE.
   - Select the appropriate board and port from the Tools menu.
   - Upload the code to the Arduino.

4. **Build and Install the Mobile App**:
   - Use the provided [App Inventor link](https://gallery.appinventor.mit.edu/?galleryid=dbf235ed-54b5-4455-8362-a9e9c3ffc891) to build the APK file.
   - Install the APK on your mobile device.

5. **Pair and Connect**:
   - Pair your mobile device with the HC-05 Bluetooth module.
   - Open the app and connect to the HC-05 module.

6. **Control the LED Strip**:
   - Use the mobile app to change the light patterns and brightness of the LED strip.

## Code Overview

The provided Arduino code allows for various lighting effects:
- **CT()**: Multicolor light pattern with temperature changes.
- **colorChase()**: Color chase effect.
- **randomCol()**: Random color effect.
- **twinkle()**: Twinkling effect with random colors.

The mobile app sends commands via Bluetooth to the Arduino, which controls the LED strip according to the received commands.

## License

This code is shared under the [GPL-3.0 license](https://opensource.org/licenses/GPL-3.0).

## Author

- **Bhuvan Kumar**


