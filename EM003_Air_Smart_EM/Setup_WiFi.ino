void parseBytes(const char* str, char sep, byte* bytes, int maxBytes, int base) {
  for (int i = 0; i < maxBytes; i++) {
    bytes[i] = strtoul(str, NULL, base);  // Convert byte
    str = strchr(str, sep);               // Find next separator
    if (str == NULL || *str == '\0') {
      break;                            // No more separators, exit
    }
    str++;                                // Point to next character after separator
  }
}
void Setup_WiFi() {
  Serial.print("Connecting to network: ");
  Serial.print(ssid);
  TelnetStream.print("Connecting to network: ");
  TelnetStream.println(ssid);
  WiFi.disconnect(true);  //Disconnect form WiFi to set new WiFi connection
  WiFi.mode(WIFI_STA); //init WiFi mode
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY)); //provide username --> identity and username is same
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD)); //provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT(); //Set config settings to default
  esp_wifi_sta_wpa2_ent_enable(&config); //Set config settings to enable function
  WiFi.begin(ssid); //Connect to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    TelnetStream.print(".");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi : NOT OK");
    lcd.setCursor(0, 1);
    lcd.print("SD Card : NOT OK");
    counter++;
    if (counter >= 60) { //After 30 seconds timeout - reset board
      ESP.restart();
    }
  }
  lcd.clear();
  Serial.println("");
  lcd.setCursor(0, 0);
  lcd.print("WiFi : OK");
  lcd.setCursor(0, 1);
  lcd.print("SD Card : OK");

  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP()); //Print LAN IP
  TelnetStream.println("");
  TelnetStream.println("WiFi connected");
  TelnetStream.println("IP address set: ");
  TelnetStream.println(WiFi.localIP()); //Print LAN IP
  localIp = WiFi.localIP();
  uint8_t fIP = localIp[3];
  Serial.print("IP Buffer: ");
  Serial.println(fIP);
  TelnetStream.println("IP Buffer: ");
  TelnetStream.println(fIP);
  tm.display(fIP);
  delay(1000);

}
