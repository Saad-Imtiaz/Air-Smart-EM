void calculated ()
{

  // Power Factor 3
  float CFPT3 = (float) 3* FPFT;
  Serial.println(CFPT3,3);
  float CP12 = (float) (FPF1 + FPF2); 
  Serial.println(CP12,3);
  CPF3 = (float) CFPT3 - CP12 ;
  
  // Real Power
  CP1 = (float) FV1 * FCT1 * FPF1;
  CP2 = (float) FV2 * FCT2 * FPF2;
  CP3 = (float) FV3 * FCT3 * CPF3;


  CP1 = (float) CP1 / 1000;
  CP2 = (float) CP2 / 1000;
  CP3 = (float) CP3 / 1000;

  CPT = (float) CP1 + CP2 + CP3 ;

  Serial.print("Real Power 1: ");
  Serial.println(CP1, 3);

  Serial.print("Real Power 2: ");
  Serial.println(CP2, 3);

  Serial.print("Real Power 3: ");
  Serial.println(CP3, 3);

  Serial.print("Real Power Total: ");
  Serial.println(CPT, 3);



  // Apparent Power

  float sqC1 = (float) FCT1 * FCT1;
  float rmsC1 = (float) sqrt(sqC1);
  float sqC2 = (float) FCT2 * FCT2;
  float rmsC2 = (float) sqrt(sqC2);
  float sqC3 = (float) FCT3 * FCT3;
  float rmsC3 = (float) sqrt(sqC3);

  float sqV1 = (float) FV1 * FV1;
  float rmsV1 = (float) sqrt(sqV1);
  float sqV2 = (float) FV2 * FV2;
  float rmsV2 = (float) sqrt(sqV2);
  float sqV3 = (float) FV3 * FV3;
  float rmsV3 = (float) sqrt(sqV3);

  CAP1 = (float) (rmsC1 * rmsV1) / 1000.00;
  CAP2 = (float) (rmsC2 * rmsV2) / 1000.00;
  CAP3 = (float) (rmsC3 * rmsV3) / 1000.00;

  Serial.print("Apparent Power 1: ");
  Serial.println(CAP1, 3);

  Serial.print("Apparent Power 2: ");
  Serial.println(CAP2, 3);

  Serial.print("Apparent Power 3: ");
  Serial.println(CAP3, 3);

  CAPT = (float) CAP1 + CAP2 + CAP3;

  Serial.print("Apparent Power Total: ");
  Serial.println(CAPT, 3);




  // Reactive Power

  CRP1 = (float) (sq(CAP1) - sq(CP1)) ;
  CRP2 = (float) (sq(CAP2) - sq(CP2)) ;
  CRP3 = (float) (sq(CAP3) - sq(CP3)) ;
  CRP1 = (float) sqrt(CRP1) ;
  CRP2 = (float) sqrt(CRP2) ;
  CRP3 = (float) sqrt(CRP3) ;

  CRPT = (float) CRP1 + CRP2 + CRP3;

  Serial.print("Reactive Power 1: ");
  Serial.println(CRP1, 5);

  Serial.print("Reactive Power 2: ");
  Serial.println(CRP2, 5);

  Serial.print("Reactive Power 3: ");
  Serial.println(CRP3, 5);

  Serial.print("Reactive Power Total: ");
  Serial.println(CRPT, 5);





}
