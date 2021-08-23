// Initialize SD card -- Setup Function
void SD_Begin()
{ 
  SD.begin(SD_CS);
  if (!SD.begin(SD_CS)) {
  Serial.print("Card Mount Failed");
    return;
  
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
  Serial.print("No SD card attached");
    return;
  }
Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
  Serial.print("ERROR - SD card initialization failed!");
    return;    // init failed
    BSDS = false;
  }

  // If the data.txt file doesn't exist
  // Create a file on the SD card and write the data labels
  File file = SD.open("/data.txt");
  if (!file) {
  Serial.print("File doens't exist");
  Serial.print("Creating file...");
    writeFile(SD, "/data.txt", "Reading ID, Date, Hour, Temperature \r\n");
  }
  else {
  Serial.print("File already exists");
  }

  file.close();
}


// Write the sensor readings on the SD card
void logSDCard() {
  dataMessage = String(timertc) + "," + String(FFTE)   + "," + String(FFREQ)  + "," + String (FV1)  + "," + String (FV2)
             + "," + String (FV3)   + "," + String (FCT1)  + "," + String (FCT2)  + "," + String (FCT3) 
             + "," + String (CPT)   + "," + String (CP1)   + "," + String (CP2)   + "," + String (CP3)  + "," + String (CRPT)  + "," + String (CRP1)
             + "," + String (CRP2)  + "," + String (CRP3)  + "," + String (CAPT)  + "," + String (CAP1) + "," + String (CAP2)
             + "," + String (CAP3)  + "," + String (FPFT)  + "," + String (FPF1)  + "," + String (FPF2) + "," + String (CPF3)  +"," + String(ServerS) + "\r\n";
             
Serial.print("Save data: ");
  Serial.println(dataMessage);
  TelnetStream.print("Save data: ");
  TelnetStream.println(dataMessage);
  appendFile(SD, "/data.txt", dataMessage.c_str());
  timeStamp = "";
}

// Write to the SD card (DON'T MODIFY THIS FUNCTION)
void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);
  TelnetStream.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Failed to open file for writing");
    BSDS = false;
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
    BSDS = true;
  } else {
    Serial.println("Write failed");
    BSDS = false;
  }
  file.close();
}

// Append data to the SD card (DON'T MODIFY THIS FUNCTION)
void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if(!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)) {
    Serial.println("Message appended");
    BSDS = true;
  }
  else {
    Serial.println("Append failed");
    BSDS = false;
  }
  file.close();
}
