

void VA ()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Voltage 1 Reading .................");
  TelnetStream.println(F("------------------ Voltage 1 Reading ................."));

  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTVA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTVA[i], HEX);

  }
  Serial.println();
  delay(20);
  delay(200);

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTVAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTVAI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTVAI, 7);

  Serial.print("CA :");
  Serial.println(crccheck);
  TelnetStream.println("CA :");
  TelnetStream.print(crccheck);

  String SV1 = String(MTVAI[3], HEX) + String(MTVAI[4], HEX)  ;
  Serial.print("V1R > Voltage 1 Reading (HEX) : ");
  Serial.print(SV1);
  TelnetStream.print("V1R > Voltage 1 Reading (HEX) : ");
  TelnetStream.println(SV1);

  FV1 = hexToDec(SV1); // Converting HEX String to DEC - in float Variable
  FV1 = (float)FV1 / 10;

  Serial.print("V1R > Voltage 1 : ");
  Serial.print(FV1);
  Serial.println(" V");
  TelnetStream.print("V1R > Voltage 1 : ");
  TelnetStream.print(FV1);
  TelnetStream.println(" V");
  delay(1000);
}

void VC ()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Voltage 3 Reading .................");
  TelnetStream.println(F("------------------ Voltage 3 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTVC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTVC[i], HEX);
  }
  //delay(1);
  delay(200);
  Serial.println();
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTVCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTVCI[i], HEX);
      }
    }
  }
  Serial.println();

  crccheck = KIRSP_cal_CRC16(MTVCI, 7);

  Serial.print("CA :");
  Serial.println(crccheck);
  TelnetStream.println("CA :");
  TelnetStream.print(crccheck);

  String SV3 = String(MTVCI[3], HEX) + String(MTVCI[4], HEX);
  Serial.print("V3R > Voltage 3 Reading (HEX) : ");
  Serial.print(SV3);
  TelnetStream.print("V3R > Voltage 3 Reading (HEX) : ");
  TelnetStream.println(SV3);

  FV3 = hexToDec(SV3); // Converting HEX String to DEC - in float Variable
  FV3 = (float)FV3 / 10;

  Serial.print("V3R > Voltage 3 : ");
  Serial.print(FV3);
  Serial.println(" V");
  TelnetStream.print("V3R > Voltage 3 : ");
  TelnetStream.print(FV3);
  TelnetStream.println(" V");
  delay(1000);
}

void VB ()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Voltage 2 Reading .................");
  TelnetStream.println(F("------------------ Voltage 2 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTVB[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTVB[i], HEX);
  }
  delay(20);
  delay(200);
  Serial.println();

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTVBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTVBI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTVBI, 7);

  Serial.print("CA :");
  Serial.println(crccheck);
  TelnetStream.println("CA :");
  TelnetStream.print(crccheck);

  String SV2 = String(MTVBI[3], HEX) + String(MTVBI[4], HEX);
  Serial.print("V2R > Voltage 2 Reading (HEX) : ");
  Serial.print(SV2);
  TelnetStream.print("V2R > Voltage 2 Reading (HEX) : ");
  TelnetStream.println(SV2);

  FV2 = hexToDec(SV2); // Converting HEX String to DEC - in float Variable
  FV2 = (float)FV2 / 10 ;

  Serial.print("V2R > Voltage 2 : ");
  Serial.print(FV2);
  Serial.println(" V");
  TelnetStream.print("V2R > Voltage 2 : ");
  TelnetStream.print(FV2);
  TelnetStream.println(" V");
  delay(1000);
}



void TAPR ()
{
  Serial.flush();
  delay(20);
  Serial.println("--------------- Total Apparent Power Reading .................");
  TelnetStream.println(F("--------------- Total Apparent Power Reading ................."));


  delay(20);

  for (i = 0; i < 8; i++)
  {

    Serial2.write(MTTAP3PT[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTTAP3PT[i], HEX);
  }

  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTTAP3PTI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTTAP3PTI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTTAP3PTI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);

  STAP = String(MTTAP3PTI[3], HEX) + String( MTTAP3PTI[4], HEX) + String( MTTAP3PTI[5], HEX) + String(MTTAP3PTI[6], HEX); //String( MTTAP3PTI[3], HEX) + String( MTTAP3PTI[4], HEX) + String( MTTAP3PTI[5], HEX) +

  Serial.print("STAP >> ");
  Serial.println(STAP);

  FTAP = hexToDec(STAP);

  //FTAP = STAP.toFloat();
  FTAP = (float) FTAP / 1000.000;
  Serial.print("TPR > Total Apparent Power : ");
  Serial.print(FTAP, 8);

  Serial.println(" kW");
  TelnetStream.print("TPR > Total Apparent Power : ");
  TelnetStream.print(FTAP);
  TelnetStream.println(" kW");
  delay(1000);
}

void AAP1R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Apparent Power 1 Reading .................");
  TelnetStream.println(F("-------------------- Apparent Apparent Power 1 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAAPA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAAPA[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTAAPAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAAPAI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTAAPAI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String AAP1 = String(MTAAPAI[3], HEX) + String(MTAAPAI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P1R > Apparent Power 1 Reading (HEX) : ");
  Serial.println(AAP1);
  TelnetStream.print("P1R > Apparent Power 1 Reading (HEX) : ");
  TelnetStream.println(AAP1);

  FAP1 = hexToDec(AAP1); // Converting HEX String to DEC - in float Variable
  FAP1 = (float)FAP1 / 1000 ;
  Serial.print("P1R > Apparent Power 1 : ");
  Serial.print(FAP1, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Apparent Power 1 : ");
  TelnetStream.print(FP1);
  TelnetStream.println(" kW");

  delay(1000);


}
void AAP2R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Apparent Power 2 Reading .................");
  TelnetStream.println(F("-------------------- Apparent Apparent Power 2 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAAPB[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAAPB[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTAAPBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAAPBI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTAAPBI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String AAP2 = String(MTAAPBI[3], HEX) + String(MTAAPBI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P1R > Apparent Power 2 Reading (HEX) : ");
  Serial.println(AAP2);
  TelnetStream.print("P1R > Apparent Power 2 Reading (HEX) : ");
  TelnetStream.println(AAP2);

  FAP2 = hexToDec(AAP2); // Converting HEX String to DEC - in float Variable
  FAP2 = (float)FAP2 / 1000 ;
  Serial.print("P1R > Apparent Power 2 : ");
  Serial.print(FAP2, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Apparent Power 2 : ");
  TelnetStream.print(FAP2);
  TelnetStream.println(" kW");
  delay(1000);

}
void AAP3R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Apparent Power 3 Reading .................");
  TelnetStream.println(F("-------------------- Apparent Apparent Power 3 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAAPC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAAPC[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTAAPCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAAPCI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTAAPCI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String AAP3 = String(MTAAPCI[3], HEX) + String(MTAAPCI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P1R > Apparent Power 3 Reading (HEX) : ");
  Serial.println(AAP3);
  TelnetStream.print("P1R > Apparent Power 3 Reading (HEX) : ");
  TelnetStream.println(AAP3);
  FAP3 = hexToDec(AAP3); // Converting HEX String to DEC - in float Variable

  FAP3 = (float)FAP3 / 1000 ;
  Serial.print("P1R > Apparent Power 3 : ");
  Serial.print(FAP3 , 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Apparent Power 3 : ");
  TelnetStream.print(FAP3);
  TelnetStream.println(" kW");
  delay(1000);
}
void TRPR ()
{
  Serial.flush();
  delay(20);
  Serial.println("--------------- Total Reactive Power Reading .................");
  TelnetStream.println(F("--------------- Total Reactive Power Reading ................."));


  delay(20);

  for (i = 0; i < 8; i++)
  {

    Serial2.write(MTRAP3PT[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTRAP3PT[i], HEX);
  }

  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 9; i++)
    {
      if  (Serial2.available())
      {
        MTRAP3PTI[i] = Serial2.read();

        Serial.print(" ");
        Serial.print(MTRAP3PTI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTRAP3PTI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);

  String STRP = String(MTRAP3PTI[3], HEX) + String(MTRAP3PTI[4], HEX) + String(MTRAP3PTI[5], HEX) + String(MTRAP3PTI[6], HEX);
  Serial.print("STRP >> ");
  Serial.println(STRP);

  FTRP = hexToDec(STRP);

  //FTRP = STRP.toFloat();
  FTRP = (float) FTRP / 1000;
  Serial.print("TRPR > Total Reactive Power : ");
  Serial.print(FTRP);
  Serial.println(" kW");

  TelnetStream.print("TPR > Total Reactive Power : ");
  TelnetStream.print(FTRP);
  TelnetStream.println(" kW");
  delay(1000);
}
void RP1R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Reactive Power 1 Reading .................");
  TelnetStream.println(F("-------------------- Reactive Power 1 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTARPA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTARPA[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTARPAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTARPAI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTARPAI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String SRP1 = String(MTARPAI[4], HEX ) + String(MTARPAI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P1R > Reactive Power 1 Reading (HEX) : ");
  Serial.println(SRP1);
  TelnetStream.print("P1R > Reactive Power 1 Reading (HEX) : ");
  TelnetStream.println(SRP1);

  FRP1 = hexToDec(SRP1); // Converting HEX String to DEC - in float Variable
  FRP1 = (float)FRP1 / 1000 ;
  Serial.print("P1R > Reactive Power 1 : ");
  Serial.print(FP1, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Reactive Power 1 : ");
  TelnetStream.print(FRP1);
  TelnetStream.println(" kW");
  delay(1000);
}
void RP2R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Reactive Power 2 Reading .................");
  TelnetStream.println(F("-------------------- Reactive Power 2 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTARPB[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTARPB[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTARPBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTARPBI[i], HEX);

      }
    }
  }
  Serial.println();

  crccheck = KIRSP_cal_CRC16(MTARPBI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String SRP2 = String(MTARPBI[3], HEX) + String(MTARPBI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P1R > Reactive Power 2 Reading (HEX) : ");
  Serial.println(SRP2);
  TelnetStream.print("P1R > Reactive Power 2 Reading (HEX) : ");
  TelnetStream.println(SRP2);

  FRP2 = hexToDec(SRP2); // Converting HEX String to DEC - in float Variable
  FRP2 = (float)FRP2 / 1000;

  Serial.print("P1R > Reactive Power 2 : ");
  Serial.print(FRP2, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Reactive Power 2 : ");
  TelnetStream.print(FRP2);
  TelnetStream.println(" kW");
  delay(1000);
}

void RP3R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Reactive Power 3 Reading .................");
  TelnetStream.println(F("-------------------- Reactive Power 3 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTARPC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTARPC[i], HEX);
  }
  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTARPCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTARPCI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTARPCI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  String SRP3 =  String(MTARPCI[3], HEX) + String(MTARPCI[4], HEX); // + String(MTARPAI[7],HEX);
  Serial.print("P3R > Reactive Power 3 Reading (HEX) : ");
  Serial.println(SRP3);
  TelnetStream.print("P1R > Reactive Power 3 Reading (HEX) : ");
  TelnetStream.println(SRP3);

  FRP3 = hexToDec(SRP3); // Converting HEX String to DEC - in float Variable
  FRP3 = (float)FRP3 / 1000 ;
  Serial.print("P1R > Reactive Power 3 : ");
  Serial.print(FRP3, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Reactive Power 3 : ");
  TelnetStream.print(FRP3);
  TelnetStream.println(" kW");
  delay(1000);
  Serial.flush();
}

void TCRER ()
{ Serial.println("--------------------- Total Current Reverse Energy Reading .................");
  TelnetStream.println(F("--------------------- Total Current Reverse Energy Reading ................."));
  String RCRE;
  delay(20);
  // Sending the Code for the Total Current Reverse Energy Reading
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MCRE[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MCRE[i], HEX);
  }
  delay(20);
  Serial.println();
  // Reading the Return Code for the Total Energy Reading
  delay(200);
  if  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      MCREI[i] = Serial2.read();
      Serial.print(" ");
      Serial.print(MCREI[i], HEX);
      delay(20);
    }

    crccheck = KIRSP_cal_CRC16(MCREI, 7);
  }

  Serial.println();
  Serial.print("CRC : ");
  Serial.println(crccheck);

  Serial.println(" TCRER > Total Current Reverse Energy Reading (Complete Packet) : ");
  // TelnetStream.print(" TER > Total Reverse Energy Reading (Complete Packet) : ");
  RCRE = String(MCREI[3], HEX) + String(MCREI[4], HEX) + String(MCREI[5], HEX) + String(MCREI[6], HEX);
  Serial.println(RCRE);

  Serial.print("TCRE > Total Current Reverse Energy Reading (DEC) : ");
  Serial.print("HEX : ");
  Serial.println(RCRE);

  TelnetStream.print("TCRE > Total Current Reverse Energy Reading (DEC) : ");
  TelnetStream.println(TCR_a);
  TelnetStream.print("HEX : ");
  TelnetStream.println(TCR_a, HEX);
  FCRE = hexToDec (RCRE);
  //FCRE = TCR_a;
  FCRE = (float) FCRE / 100; // Dividing by 100 to make it kWh

  Serial.print(">> Total Current Reverse Energy Reading : ");
  Serial.print(FCRE);
  Serial.println(" E");

  TelnetStream.print(">> Total Current Reverse Reading : ");
  TelnetStream.print(FCRE);
  TelnetStream.println(" E");
  TelnetStream.flush();
  delay(1000);
}
void TCFER()
{
  String RCFE;
  delay(20);
  // Sending the Code for the Total Energy Reading
  for (i = 0; i < 9; i++)
  {
    Serial2.write(MCFE[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MCFE[i]);
  }
  delay(20);
  Serial.println("--------------------- Total Current Forward Energy Reading .................");
  TelnetStream.println(F("--------------------- Total Current Forward Energy Reading ................."));
  // Reading the Return Code for the Total Energy Reading
  delay(60);
  if  (Serial2.available())
  {
    for (i = 0; i < 9; i++)
    {
      MCFEI[i] = Serial2.read();
      Serial.print(" ");
      Serial.print(MCFEI[i]);
      TelnetStream.println(MCFEI[i]);
      delay(20);
    }

    crccheck = KIRSP_cal_CRC16(MCFEI, 8);
  }

  TCF_a  = MCFEI[3];
  TCF_a  = TCF_a  << 24;
  TCF_a  = TCF_a  + MCFEI[4];
  TCF_a  = TCF_a  << 16;
  TCF_a  = TCF_a  + MCFEI[5];
  TCF_a  = TCF_a  << 8;
  TCF_a  = TCF_a  + MCFEI[6];
  Serial.print(" TCFER > Total Current Forward Energy Reading (Complete Packet) : ");
  TelnetStream.print(" TER > Total Forward Energy Reading (Complete Packet) : ");
  RCFE = String(MCFEI[0], HEX) + String(MCFEI[1], HEX) + String(MCFEI[2], HEX) + String(MCFEI[3], HEX) + String(MCFEI[4], HEX) + String(MCFEI[5], HEX) + String(MCFEI[6], HEX) + String(MCFEI[7], HEX) + String(MCFEI[8], HEX);
  Serial.println(RCFE);
  TelnetStream.println(RCFE);


  {
    Serial.print("TER > Total Current Forward Energy Reading (DEC) : ");
    Serial.println(TCF_a);
    Serial.print("HEX : ");
    Serial.println(TCF_a, HEX);
    TelnetStream.print("TER > Total Current Forward Energy Reading (DEC) : ");
    TelnetStream.println(TCF_a);
    TelnetStream.print("HEX : ");
    TelnetStream.println(TCF_a, HEX);
  }

  FCFE = TCF_a;
  //FCFE = (float)FCFE / 100; // Dividing by 100 to make it kWh

  Serial.print(">> Total Current Forward Energy Reading : ");
  Serial.print(FCFE);
  Serial.print(" E");
  TelnetStream.print(">> Total Current Forward Reading : ");
  TelnetStream.print(FCFE);
  TelnetStream.println(" E");
  TelnetStream.flush();
  delay(1000);
}


/********************************************************************
 ************************ Total Energy Reading  *********************
 ********************************************************************/
void TER()
{
  delay(20);
  // Sending the Code for the Total Energy Reading
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTE[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTE[i], HEX);
  }
  delay(20);
  Serial.println();
  Serial.println("--------------------- Total Energy Reading .................");
  TelnetStream.println(F("--------------------- Total Energy Reading ................."));
  // Reading the Return Code for the Total Energy Reading
  delay(80);
  if  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      MTEI[i] = Serial2.read();
      Serial.print(" ");
      Serial.print(MTEI[i], HEX);
      TelnetStream.print(" ");
      TelnetStream.print(MTEI[i], HEX);
      delay(20);
    }
  }
  Serial.println();

  RTE = String(MTEI[3], HEX) + String(MTEI[4], HEX) + String(MTEI[5], HEX) + String(MTEI[6], HEX);

  crccheck = KIRSP_cal_CRC16(MTEI, 8);


  Serial.print(" TER > Total Energy Reading (Complete Packet) : ");
  Serial.print("CRC : ");
  Serial.println(crccheck);

  Serial.print("TER > Total Energy Reading (HEX) : ");
  Serial.println(RTE);

  TelnetStream.print("TER > Total Energy Reading (HEX) : ");
  TelnetStream.println(RTE);

  FTE = hexToDec(RTE);
  FFTE = (float)FTE / 100; // Dividing by 100 to make it kWh

  Serial.print(">> Total Energy Reading : ");
  Serial.print(FFTE);
  Serial.println("kWh");

  TelnetStream.print(">> Total Energy Reading : ");
  TelnetStream.print(FFTE);
  TelnetStream.println("kWh");
  TelnetStream.flush();
  delay(1000);

}


// END TOTAL ENERGY READING

/********************************************************************
 *************************** Power 1 Reading  ***********************
 ********************************************************************/

void P1R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Power 1 Reading .................");
  TelnetStream.println(F("-------------------- Power 1 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAPA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAPA[i], HEX);
  }
  Serial.println();
  delay(20);
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTAPAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAPAI[i], HEX);
      }
    }
  }
  Serial.println();

  crccheck = KIRSP_cal_CRC16(MTPFI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  RP1 = String(MTAPAI[3], HEX) + String(MTAPAI[4], HEX); // + String(MTAPAI[7],HEX);
  Serial.print("P1R > Power 1 Reading (HEX) : ");
  Serial.println(RP1);
  TelnetStream.print("P1R > Power 1 Reading (HEX) : ");
  TelnetStream.println(RP1);

  FP1 = hexToDec(RP1); // Converting HEX String to DEC - in float Variable
  FP1 = (float)FP1 / 1000 ;
  Serial.print("P1R > Power 1 : ");
  Serial.print(FP1, 4);
  Serial.println(" kW");
  TelnetStream.print("P1R > Power 1 : ");
  TelnetStream.print(FP1);
  TelnetStream.println(" kW");

  delay(1000);
} // End Power 1 Reading


/********************************************************************
 *************************** Power 2 Reading  ***********************
 ********************************************************************/
void P2R()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Power 2 Reading .................");
  TelnetStream.println(F("-------------------- Power 2 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAPB[i]);
    Serial.print(" ");
    Serial.print(MTAPB[i], HEX);
    delay(20);
  }
  Serial.println();

  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTAPBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAPBI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTPFI, 7);
  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  RP2 = String(MTAPBI[5], HEX) + String(MTAPBI[6], HEX); // + String(MTAPBI[7], HEX) ;
  Serial.print("P2R > Power 2 Reading (HEX) : ");
  Serial.println(RP2);
  TelnetStream.print("P2R > Power 2 Reading (HEX) : ");
  TelnetStream.println(RP2);

  FP2 = hexToDec(RP2); // Converting HEX String to DEC - in float Variable
  FP2 = (float)FP2 / 1000 ;
  Serial.print("P2R > Power 2 : ");
  Serial.print(FP2, 4);
  Serial.println(" kW");
  TelnetStream.print("P2R > Power 2 : ");
  TelnetStream.print(FP2);
  TelnetStream.println(" kW");

  delay(1000);
}// End Power 2 Reading

/********************************************************************
 *************************** Power 3 Reading  ***********************
 ********************************************************************/

void P3R ()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Power 3 Reading .................");
  TelnetStream.println(F("-------------------- Power 3 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTAPC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAPC[i], HEX);
  }
  Serial.println();

  delay(100);

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        delay(20);
        MTAPCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAPCI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTPFI, 7);

  Serial.print("CRC : ");
  Serial.println(crccheck);
  TelnetStream.print("CRC : ");
  TelnetStream.println(crccheck);

  RP3 =  String(MTAPCI[3], HEX) + String(MTAPCI[4], HEX);//
  Serial.print("P3R > Power 3 Reading (HEX) : ");
  Serial.println(RP3);
  TelnetStream.print("P3R > Power 3 Reading (HEX) : ");
  TelnetStream.println(RP3);

  FP3 = hexToDec(RP3); // Converting HEX String to DEC - in float Variable
  FP3 = (float)FP3 / 1000;
  Serial.print("P3R > Power 3 : ");
  Serial.print(FP3, 4);
  Serial.println(" kW");
  TelnetStream.print("P3R > Power 3 : ");
  TelnetStream.print(FP3);
  TelnetStream.println(" kW");

  delay(1000);
}// End Power 3 Reading



void TPR ()
{
  String RTP1;     // Total Power Reading Packet
  Serial.flush();
  delay(20);
  Serial.println("--------------- Total Power Reading .................");
  TelnetStream.println(F("--------------- Total Power Reading ................."));


  delay(20);

  for (i = 0; i < 8; i++)
  {

    Serial2.write(MTAP1[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTAP1[i], HEX);
  }
  Serial.println();
  delay(20);

  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 9; i++)
    {
      if  (Serial2.available())
      {
        MTAP1I[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTAP1I[i], HEX);
      }
    }

  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTAP1I, 9);
  Serial.println(crccheck);

  // RTP1 = String(MTAP1I[3], HEX) + String(MTAP1I[4], HEX) + String(MTAP1I[5], HEX) + String(MTAP1I[6], HEX);
  //RTP = String(MTAP1I[4], DEC) + String(MTAP1I[5], DEC) + String(MTAP1I[7], DEC) + String(MTAP1I[7], DEC);
  RTP = String(MTAP1I[3], HEX) + String(MTAP1I[4], HEX) + String(MTAP1I[5], HEX) + String(MTAP1I[6], HEX);
  Serial.print("RTP >> ");
  Serial.println(RTP);

  // FTP = RTP.toFloat();
  FTP = hexToDec(RTP);
  FTP = (float) FTP / 1000.000;
  Serial.print("TPR > Total Power : ");
  Serial.print(FTP, 4);
  Serial.println(" kW");


  TelnetStream.print("TPR > Total Power : ");
  TelnetStream.print(FTP);
  TelnetStream.println(" kW");

  delay(1000);
}// End Total Power Reading

/********************************************************************
 *************************** Current 1 Reading  *********************
 ********************************************************************/

void CT1R()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Current 1 Reading .................");
  TelnetStream.println(F("------------------ Current 1 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTCA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTCA[i], HEX);
  }
  Serial.println();
  delay(20);
  delay(200);

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTCAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTCAI[i], HEX);
      }
    }
  }
  Serial.println();

  crccheck = KIRSP_cal_CRC16(MTVAI, 7);

  Serial.print("CA :");
  Serial.println(crccheck);
  TelnetStream.println("CA :");
  TelnetStream.print(crccheck);

  RCT1 = String(MTCAI[3], HEX) + String(MTCAI[4], HEX) ;
  Serial.print("CT1R > Current 1 Reading (HEX) : ");
  Serial.println(RCT1);
  TelnetStream.print("CT1R > Current 1 Reading (HEX) : ");
  TelnetStream.println(RCT1);

  FCT1 = hexToDec(RCT1); // Converting HEX String to DEC - in float Variable
  FCT1 = (float)FCT1 / 100;
  FCT1 = (float)FCT1 ;
  Serial.print("CT1R > Current 1 : ");
  Serial.print(FCT1);
  Serial.println(" A");
  TelnetStream.print("CT1R > Current 1 : ");
  TelnetStream.print(FCT1);
  TelnetStream.println(" A");
  delay(1000);
}

/********************************************************************
 *************************** Current 2 Reading  *********************
 ********************************************************************/

void CT2R()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Current 2 Reading .................");
  TelnetStream.println(F("------------------ Current 2 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTCB[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTCB[i], HEX);
  }
  Serial.println();
  delay(200);

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTCBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTCBI[i], HEX);
      }
    }
  }
  Serial.println();

  RCT2 = String(MTCBI[3], HEX) + String(MTCBI[4], HEX);
  Serial.print("CT2R > Current 2 Reading (HEX) : ");
  Serial.println(RCT2);
  TelnetStream.print("CT2R > Current 2 Reading (HEX) : ");
  TelnetStream.println(RCT2);

  FCT2 = hexToDec(RCT2); // Converting HEX String to DEC - in float Variable
  FCT2 = (float)FCT2 / 100;
  FCT2 = (float)FCT2 ;
  Serial.print("CT2R > Current 2 : ");
  Serial.print(FCT2);
  Serial.println(" A");
  TelnetStream.print("CT2R > Current 2 : ");
  TelnetStream.print(FCT2);
  TelnetStream.println(" A");
  delay(1000);
}

/********************************************************************
 *************************** Current 3 Reading  *********************
 ********************************************************************/

void CT3R()
{
  Serial.flush();
  delay(20);
  Serial.println("------------------ Current 3 Reading .................");
  TelnetStream.println(F("------------------ Current 3 Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTCC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTCC[i], HEX);
  }
  delay(20);
  delay(200);
  Serial.println();
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTCCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTCCI[i], HEX);
      }
    }
  }
  Serial.println();

  RCT3 = String(MTCCI[3], HEX) + String(MTCCI[4], HEX) ;
  Serial.print("CT3R > Current 3 Reading (HEX) : ");
  Serial.println(RCT3);
  TelnetStream.print("CT3R > Current 3 Reading (HEX) : ");
  TelnetStream.println(RCT3);

  FCT3 = hexToDec(RCT3); // Converting HEX String to DEC - in float Variable
  FCT3 = (float)FCT3 / 100 ;
  FCT3 = (float)FCT3;
  Serial.print("CT3R > Current 3 : ");
  Serial.print(FCT3);
  Serial.println(" A");
  TelnetStream.print("CT3R > Current 3 : ");
  TelnetStream.print(FCT3);
  TelnetStream.println(" A");
  delay(1000);
} // End Current 3 Reading






/********************************************************************
 ************************ Frequency  Reading  ***********************
 ********************************************************************/
void FRQR()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- Frequency Reading .................");
  TelnetStream.println(F("-------------------- Frequency Reading ................."));
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTF[i]);
    delay(20);
  }
  delay(20);
  delay(200);

  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTFI[i] = Serial2.read();
      }
    }
  }

  crccheck = KIRSP_cal_CRC16(MTFI, 7);
  Serial.print(crccheck);
  TelnetStream.println(crccheck);

  RFREQ = String(MTFI[3], HEX) + String(MTFI[4], HEX) ;
  Serial.print("FRQR > Frequncy  (HEX): ");
  Serial.println(RFREQ);
  TelnetStream.print("FRQR > Frequncy  (HEX): ");
  TelnetStream.println(RFREQ);

  FFREQ = hexToDec(RFREQ); // Converting HEX String to DEC - in float Variable
  FFREQ = (float)FFREQ / 100;
  Serial.print("FRQR > Frequncy : ");
  Serial.print(FFREQ);
  Serial.println("Hz");
  TelnetStream.print("FRQR > Frequncy : ");
  TelnetStream.print(FFREQ);
  TelnetStream.println("Hz");
  delay(1000);
}


void PFTR()
{
  Serial.flush();

  delay(20);
  Serial.println("-------------------- PFT Reading .................");

  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTPF[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTPF[i] , HEX);
  }

  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTPFI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTPFI[i] , HEX);
      }
    }
  }
  Serial.println();

  crccheck = KIRSP_cal_CRC16(MTPFI, 7);
  Serial.print("Power Factor Total");
  Serial.print("CRC");
  Serial.println(crccheck);

  RPFT = String(MTPFI[3], HEX) + String(MTPFI[4], HEX);
  Serial.print("RPFT : ");
  Serial.println(RPFT);
  FPFT = hexToDec(RPFT);
  FPFT = (float) FPFT / 1000.00;
  Serial.print("Total Power Factor : ");
  Serial.println(FPFT,3);
  TelnetStream.print("TPF > Total Power Factor: ");
  TelnetStream.println(FPFT,3);
  delay(1000);

}
void PF1R()
{
  Serial.flush();
  Serial.println("-------------------- PF1 Reading .................");
  delay(20);

  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTPFA[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTPFA[i], HEX);
  }

  delay(20);
  Serial.println();
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTPFAI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTPFAI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTPFAI, 7);
  Serial.println("Power Factor A");
  Serial.print("CRC : ");
  Serial.println(crccheck);


  RPF1 = String(MTPFAI[3], HEX) + String(MTPFAI[4], HEX) ;
  Serial.print("RPF2 : ");
  Serial.println(RPF1);

  FPF1 = hexToDec(RPF1);
  FPF1 = (float) FPF1 / 1000.000;
  Serial.print("Power Factor 1 : ");
  Serial.println(FPF1,3);
  TelnetStream.print("PF1 >  Power Factor 1: ");
  TelnetStream.println(FPF1,3);
  delay(1000);
}
void PF2R()
{
  Serial.flush();
  delay(20);
  Serial.println("-------------------- PF2 Reading .................");
  for (i = 0; i < 8; i++)
  {

    Serial2.write(MTPFB[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTPFB[i], HEX);
  }
  Serial.println();
  delay(20);
  delay(200);
  while  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTPFBI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTPFBI[i], HEX);
      }
    }
  }
  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTPFBI, 7);
  Serial.println("Power Factor B");
  Serial.print("CRC : ");
  Serial.println(crccheck);

  RPF2 = String(MTPFBI[3], HEX) + String(MTPFBI[4], HEX) ;
  Serial.print("RPF2 : ");
  Serial.println(RPF2);
  FPF2 = hexToDec(RPF2);
  FPF2 = (float) FPF2 / 1000.00;
  Serial.print("Power Factor 2 : ");
  Serial.println(FPF2,3);
  TelnetStream.print("PF2 >  Power Factor 2: ");
  TelnetStream.println(FPF2,3);
  delay(1000);
}

void PF3R()
{
  delay(20);
  Serial.println("-------------------- PF3 Reading .................");
  for (i = 0; i < 8; i++)
  {
    Serial2.write(MTPFC[i]);
    delay(20);
    Serial.print(" ");
    Serial.print(MTPFC[i], HEX);
  }

  Serial.println();
  delay (200);

  if  (Serial2.available())
  {
    for (i = 0; i < 7; i++)
    {
      if  (Serial2.available())
      {
        MTPFCI[i] = Serial2.read();
        Serial.print(" ");
        Serial.print(MTPFCI[i], HEX);
      }
    }
  }

  Serial.println();
  crccheck = KIRSP_cal_CRC16(MTPFCI, 7);
  Serial.println("Power Factor C");
  Serial.print("CRC :");
  Serial.println(crccheck);

  RPF3 = String(MTPFCI[3], HEX) + String(MTPFCI[4], HEX) ;
  Serial.print("RPF3 : ");
  Serial.println(RPF3);
  FPF3 = hexToDec(RPF3);
  FPF3 = (float) FPF3 / 1000.000;
  Serial.print("Power Factor 3 : ");
  Serial.println(CPF3);
  TelnetStream.print("PF3 >  Power Factor 3: ");
  TelnetStream.println(FPF3);
  delay(1000);

}



// KIRSP Global Variables for CRC-16 Checking
unsigned char KIRSP_CRC16_Hi_Byte  = 0xFF;  // Do not modify
unsigned char KIRSP_CRC16_Low_Byte = 0xFF;  // Do not modify


unsigned int KIRSP_cal_CRC16(unsigned char *CRC16_Data_Array, unsigned short CRC16_Data_Array_Len)
{
  unsigned int x = 0xFFFF;
  unsigned int y;
  int i;
  x ^= *CRC16_Data_Array;
  for (i = 0; i < 8; ++i)
  {
    if (x & 1)
      x = (x >> 1) ^ 0xA001; // <----The key
    else
      x = (x >> 1);
  }
  KIRSP_CRC16_Hi_Byte = highByte(x);
  KIRSP_CRC16_Low_Byte = lowByte(x);
  y = x;
  CRC16_Data_Array_Len--;
  *CRC16_Data_Array++;
  while (CRC16_Data_Array_Len--)
  {
    y ^= *CRC16_Data_Array;
    for (i = 0; i < 8; ++i)
    {
      if (y & 1)
        y = (y >> 1) ^ 0xA001; // <---The Key
      else
        y = (y >> 1);
    }
    KIRSP_CRC16_Hi_Byte = highByte(y);
    KIRSP_CRC16_Low_Byte = lowByte(y);
    *CRC16_Data_Array++;
  }
  KIRSP_CRC16_Hi_Byte = lowByte(y);   // write to global variable
  KIRSP_CRC16_Low_Byte = highByte(y); // write to global variable
  return y;
} // end of KIRSP_cal_CRC16 function
