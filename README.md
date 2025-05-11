# Smart Glasses Project

Smart glasses is a project which enables an individual to get notifications in real time at front of his/her eye without losing concentration from core operation. It can connect to android device via WiFi and it can also connect to OWON multimeter via Bluetooth.

## Features

### 1. Splash Screen
- Displays "SMART GLASSES" title
- Shows "Ready..." status
- Custom text size and positioning

### 2. Call Notifications
- Displays incoming call information
- Scrolling text animation
- Shows "CALLING..." status

### 3. Message Counter
- Displays unread message count
- Shows "UNREAD MESSAGES" status

### 4. Multimeter Integration
- Displays multimeter readings

### Core Components
- **Microcontroller**: Arduino Board
- **Display**: LCD Screen with I2C interface
  - Resolution: 128x64 pixels
  - Monochrome display
- **Multimeter Interface**: 
  - Analog input for voltage readings
  - Digital input for measurement data

### Mobile Application: app-debug.apk

- Companion Android app that connects to the smart glasses via WiFi

- Sends real-time call and message notifications

- Must be installed on an Android device

- Allows testing and live updates

- Ensure the app is granted necessary permissions and is kept running in the background

### Libraries Used
- Adafruit_GFX
- Adafruit_SSD1306
- Wire (I2C communication)

### Prerequisites
1. Arduino IDE
2. Required libraries:
   - Adafruit GFX Library
   - Adafruit SSD1306
   - Wire Library

### Setup Instructions
1. **Hardware Setup**
   - Connect the LCD display to Arduino:
     - SDA pin to Arduino A4
     - SCL pin to Arduino A5
     - VCC to 5V
     - GND to GND
   - Connect the multimeter interface
   - Ensure proper power supply connection

2. **Software Setup**
   - Install Arduino IDE
   - Install required libraries
   - Open the project in Arduino IDE
   - Select correct board and port
   - Upload the code

## Usage Instructions

1. **Power On**
   - Connect the device to power
   - Wait for splash screen to appear
   - Verify "Ready..." message

2. **Normal Operation**
   - Device will display notifications
   - Call notifications will scroll when received
   - Message count updates automatically
   - Multimeter readings display in real-time

## Author

**Zile Hassnain**
- LinkedIn: [Zile Hassnain](https://www.linkedin.com/in/zile-hassnain/)

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Acknowledgments

- Arduino community for support and resources
- Adafruit for display libraries
- Open source community for inspiration and tools 