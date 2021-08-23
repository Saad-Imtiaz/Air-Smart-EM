void StatusDSP()
{
  IPAddress localIp = WiFi.localIP();
  uint8_t fIP1 = localIp[0];
  uint8_t fIP2 = localIp[1];
  uint8_t fIP3 = localIp[2];
  uint8_t fIP4 = localIp[3];

  String telip = String (fIP1) + String (".") + String (fIP2) + String (".")  + String (fIP3) + String (".")  + String(fIP4);
  
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.print(telip);
  lcd.setCursor(3, 3);
  lcd.print("EM003 - 1.21V");

  lcd.setCursor(5,1);
  lcd.print(String(FFTE) + String(" kWh"));

  
  lcd.setCursor(1,2);
  lcd.print(String(FCT1) + String("A|") + String(FCT2) + String("A|") + String(FCT3) + String("A") );

  if ( BSent == true)
  { BRST = false;

    lcd.setCursor(19, 0);
    lcd.print("1");
   
    lcd.createChar(0, senddata);
    lcd.setCursor(0, 0);
    lcd.write(0);// Data is Sent to the MQTT Sever SUCCESSFULLY
    
    ServerS = "Server : UP ";
  }

  else {
 
    lcd.setCursor(19, 0);
    lcd.print("2");
  
    lcd.setCursor(0, 0);
    lcd.print("X");
    ServerS = "Server : DOWN";
  }
  
  delay (1000);

  if (BSDS == true) // True oig
  {
    lcd.setCursor(19, 0);
    lcd.print("3");

    lcd.createChar(1, writedata);
    lcd.setCursor(1, 0);
    lcd.write(1);// SD Card data logged
  }
  else {

    lcd.setCursor(19, 0);
    lcd.print("4");

    lcd.setCursor(1, 0);
    lcd.print("X");
  }




}
