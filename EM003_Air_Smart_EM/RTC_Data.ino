void RTC() {

    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");
    timertc = String(now.year(), DEC) + "-" + String (now.month(), DEC) + "-" + String(now.day(), DEC) + "|" +String (now.hour(), DEC) + ":" + String (now.minute(), DEC) + ":" + String (now.second(), DEC); 

    Serial.println();
}
