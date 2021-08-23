/**
 * @brief Meter ID : EM003
 * @author Saad Imtiaz
 * @paragraph 
 * Description:
 * Air Smart EM V 1.20
   Fucntions :
   Reading Values from the DTS238-7 ZN/S (Energy Meter).
   SD Card Logging.
   TM 1637 - Status Display.
   Time Stamp - Getting time from the server (Ali).
   FOTA (Firmware over the Air) ADDED
   Power, Power Factor and other variables added.
   OTA added
   Telenet Stream added for Network serial debug
   Single topic created for sending data
   WatchDog Added 
 * 
 */

#include <Arduino.h>
#include <String.h>
#include <TM1637.h>
#include <RTClib.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Watch Dog timer
#include <esp_task_wdt.h>
//40 Seconds WDT
#define WDT_TIMEOUT 40000

// SD card Libraries
#include "FS.h"
#include "SD.h"
#include <SPI.h>

// WiFi Libraries
#include <WiFi.h>
#include <PubSubClient.h> //MQTT Client
#include "esp_wpa2.h"     //WPA2 library for connections to Enterprise networks

//OTA library (included in folder)
#include "OTA.h"

//FOTA library
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <WiFiClientSecure.h>
#include "cert.h"

// WiFi Setting - User ID & Password
#define EAP_IDENTITY "elt@austd.com" //if connecting from another corporation, use identity@organisation.domain in Eduroam
#define EAP_PASSWORD "elt"           //Eduroam Password
const char *ssid = "eduroam";        // Eduroam SSID
const char *brokerUser = "ali";
const char *brokerPass = "verygood";

// Define CS pin for the SD card module
#define SD_CS 5

// Display Module connection pins (Digital Pins) -- TM-1637
#define CLK 33
#define DIO 32

//TM1637Display display(CLK, DIO);
TM1637 tm(CLK, DIO);

// METER ID >>
// "EM003:1.18V";

//MQTT Out Topic Setting

#define inTopic "time"
#define OM1 "meter3a"
#define OM2 "meter3b"
// Variables for MQTT Send
long currentTime, lastTime;
float CT1 = 0;
float CT2 = 0;
float CT3 = 0;
float P1 = 0;
float P2 = 0;
char messages1[200];
char messages2[200];

WiFiClient espClient;
PubSubClient client(espClient);

/*********************************************************************
 **************************** SETUP **********************************
 *********************************************************************/

//FOTA Variables (Don't Touch)
#define LED_BUILTIN 2
String FirmwareVer = "1.21";

#define URL_fw_Version "https://raw.githubusercontent.com/AirSmartEnergy/EM003/main/bin_version.txt"
#define URL_fw_Bin "https://raw.githubusercontent.com/AirSmartEnergy/EM003/main/EM003.bin"
void connect_wifi();
void firmwareUpdate();
int FirmwareVersionCheck();

unsigned long previousMillis = 0; // will store last time LED was updated
unsigned long previousMillis_2 = 0;
const long interval = 60000;
const long mini_interval = 1000;
struct Button
{
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button_boot = {
    0,
    0,
    false};

void IRAM_ATTR isr()
{
  button_boot.numberKeyPresses += 1;
  button_boot.pressed = true;
}

void setup()
{

  //FOTA Setting
  attachInterrupt(button_boot.PIN, isr, RISING);
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  Serial.print("Active firmware version:");
  Serial.println(FirmwareVer);
  lcd.init(); // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Air University");
  lcd.setCursor(0, 1);
  lcd.print("Smart Energy Monitor");
  lcd.setCursor(6, 2);
  lcd.print("Version");
  lcd.setCursor(3, 3);
  lcd.print("EM003 - 1.20V");

  delay(10);
  Serial.println();
  delay(10);
  Serial.println();
  Setup_WiFi();
  SD_Begin();
  Serial2.begin(9600, SERIAL_8N1, 17, 16, false); // Modbus connection
  tm.init();
  uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
  uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};

  //OTA Setup
  setupOTA("AUSmartEnergy", ssid, EAP_PASSWORD);

#ifndef ESP8266
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB
#endif

  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
  }

  //watchdog timer setup
  Serial.println("Configuring WDT...");
  esp_task_wdt_init(WDT_TIMEOUT, true); //enable panic so ESP32 restarts
  esp_task_wdt_add(NULL);               //add current thread to WDT watch
  lcd.clear();
}

/*********************************************************************
 **************************** LOOP ***********************************
 *********************************************************************/

void loop()
{
  ArduinoOTA.handle();
  //WatchDog Timer
  esp_task_wdt_reset();

  RTC();
  StatusDSP(); // Status Display
  TER();       // Total Power Comsumption
  CT1R();      // Current 1 *
  StatusDSP(); // Status Display
  CT2R();      // Current 2 *
  CT3R();      // Current 3 *
  FRQR();      // Frequency
  StatusDSP(); // Status Display
  PFTR();      // Total Power Factor
  VC();
  PF1R(); // Power Factor 1
  VA();
  PF3R(); // Power Factor 3
  VB();
  StatusDSP(); // Status Display
  PF2R();      // Power Factor 2
  StatusDSP();
  calculated();
  P1R(); // Power 1 *
  P2R(); // Power 2 *
  P3R(); // Power 3 *
  TPR(); // Total Power

  RTC();
  logSDCard(); // SD Card Logging

  // Connecting to the Server
  if (!client.connected())
  {
    connect_server();
  }
  // Sending the Values
  send_MQTT();
  ESPRST();

  StatusDSP();
  //FOTA Loop
  if (button_boot.pressed)
  { //to connect wifi via Android esp touch app
    Serial.println("Firmware update Starting..");
    firmwareUpdate();
    button_boot.pressed = false;
  }
  repeatedCall();
  //WatchDog Timer
  esp_task_wdt_reset();
}

void getall()
{
  P1R();   // Power 1 *
  TER();   // Total Power Comsumption
  P2R();   // Power 2 *
  P3R();   // Power 3 *
  FRQR();  // Frequency
  TPR();   // Total Power
  CT1R();  // Current 1 *
  CT2R();  // Current 2 *
  CT3R();  // Current 3 *
  PFTR();  // Total Power Factor
  VC();    // Voltage 3
  PF1R();  // Power Factor 1
  VA();    // Voltage 1
  PF3R();  // Power Factor 3
  VB();    // Voltage 2
  PF2R();  // Power Factor 2
  AAP1R(); // Apparent Power 1
  AAP2R(); // Apparent Power 2
  AAP3R(); // Apparant Power 3
  RP1R();  // Reactive Power 1
  RP2R();  // Reactive Power 2
  RP3R();  // Reactive Power 3
  TAPR();  // Total Apparent Power
  TRPR();  // Total Reactive Power
}
