void send_MQTT()
{ client.loop();
  currentTime = millis();
  if (currentTime - lastTime > 10000) {
    Serial.println("------- MQTT DATA TRASMISSION STARTED ------");
    TelnetStream.println("------- MQTT DATA TRASMISSION STARTED ------");

    IPAddress localIp = WiFi.localIP();
    uint8_t fIP1 = localIp[0];
    uint8_t fIP2 = localIp[1];
    uint8_t fIP3 = localIp[2];
    uint8_t fIP4 = localIp[3];
    //FTRP,FRP1,FRP2,FRP3,FTAP,FAP1,FAP2,FAP3
 lcd.createChar(3,mqttsend);
 lcd.setCursor(18,0);
 lcd.write(3);
 delay(1000);
   
    snprintf(messages1, 200, "FTRP%.2fFTRP_FRP1%.2fFRP1_FRP2%.2fFRP2_FRP3%.2fFRP3_FTAP%.2fFTAP_FAP1%.2fFAP1_FAP2%.2fFAP2_FAP3%.2fFAP3_FV1%.2fFV1_FV2%.2fFV2_FV3%.2fFV3_FTP%.2fFTP_", CRPT, CRP1, CRP2, CRP3, CAPT, CAP1, CAP2, CAP3, FV1, FV2, FV3, CPT);
    Serial.print("OM 1: ");
    Serial.println(messages1);
    TelnetStream.print("OM 1: ");
    TelnetStream.println(messages1);
    client.publish(OM1, messages1);

    snprintf(messages2, 200, "FPFT%.2fFPFT_FFTE%.2fFFTE_FFREQ%2.2fFFREQ_ FP1%2.2fFP1_FP2%2.2fFP2_FP3%2.2fFP3_FCT1%2.2fFCT1_FCT2%2.2fFCT2_FCT3%2.2fFCT3_FPF1%2.2fFPF1_FPF2%2.2fFPF2_FPF3%2.2fFPF3_IP%d.%d.%d.%dIP_MIDEM003:1.21VMID_", FPFT, FFTE , FFREQ, CP1 , CP2 , CP3 , FCT1 , FCT2, FCT3 , FPF1 , FPF2 , CPF3 , fIP1, fIP2, fIP3, fIP4);
    Serial.print("OM 2: ");
    Serial.println(messages2);
    TelnetStream.print("OM 2: ");
    TelnetStream.println(messages2);
    client.publish(OM2, messages2);

    AllVal =  String(timertc)       + "," + String(FFTE)   + "," + String(FFREQ)  + "," + String (FV1)  + "," + String (FV2)
             + "," + String (FV3)   + "," + String (FCT1)  + "," + String (FCT2)  + "," + String (FCT3) 
             + "," + String (CPT)   + "," + String (CP1)   + "," + String (CP2)   + "," + String (CP3)  + "," + String (CRPT)  + "," + String (CRP1)
             + "," + String (CRP2)  + "," + String (CRP3)  + "," + String (CAPT)  + "," + String (CAP1) + "," + String (CAP2)
             + "," + String (CAP3)  + "," + String (FPFT)  + "," + String (FPF1)  + "," + String (FPF2) + "," + String (CPF3) + "\r\n";


//  AllVal =  String(timertc) + "," + String(FFTE) + "," + String(FFREQ) + "," + String (FV1)  + "," + String (FV2)
//             + "," + String (FV3) + "," + String (FCT1) + "," + String (FCT2) + "," + String (FCT3) 
//             + "," + String (FTP) + "," + String (FP1) + "," + String (FP2)  + "," + String (FP3)  + "," + String (FTRP)  + "," + String (FRP1)
//             + "," + String (FRP2)  + "," + String (FRP3)  + "," + String (FTAP)  + "," + String (FAP1) + "," + String (FAP2)
//             + "," + String (FAP3) + "," + String (FPFT) + "," + String (FPF1) + "," + String (FPF2) + "," + String (FPF3) + "\r\n";
//             
//


    Serial.println(AllVal);
    TelnetStream.println();
    lastTime = millis();
  }
}
