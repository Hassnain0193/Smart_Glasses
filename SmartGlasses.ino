//Timer Library
#include <elapsedMillis.h>

//WIFI Library
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

//EEPROM library
#include <EEPROM.h>

//I2C protocol library
#include <Wire.h>
//OLED display library
#include <Adafruit_SSD1306.h>

// OLED display TWI address
#define OLED_ADDR   0x3C
//Initializaing OLED library
Adafruit_SSD1306 lcd(-1);

//Checking OLED size
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//Data Type variable for api response
String dataType = "text/plain";
String requestData;
JsonObject root;

//Variables for text scrolling
int x, minX;
String type = "";
String data = "";

//Variables for multimeter
int count = 1;
String y;
float mData;

ESP8266WebServer server;

void setup() {
  //Serial for bluetooth
  Serial.begin(9600);

  //Initializing
  EEPROM.begin(1024);

  //Wifi configration method
  configWifi();

  // initialize and clear display
  lcd.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  lcd.clearDisplay();
  lcd.display();
  lcd.setTextWrap(false);
  x = lcd.width();
  splash();
}

void loop ()
{
  if (WiFi.softAPgetStationNum() > 0)
  {
    //Handeling API hits
    server.handleClient();

    if (type == "CALL")
    {
      if (data == "call connected" || data == "call disconnected")
      {
        type = "";
        data = "";
      }
      else
        printCalling();
    }
    else if (type == "MSG")
    {
      if (data == "0")
        splash();
      else
        printMsgCount();
    }
    else
      splash();

    delay(100);
    yield();
  }
  else
  {
    ReadMeter();
  }
}
