//Commands to send
char MTE[8]   =  {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B};
char MTAP1[8] =  {0x01, 0x03, 0x00, 0x86, 0x00, 0x02, 0x25, 0xE2};
char MTAPA[8] =  {0x01, 0x03, 0x00, 0x88, 0x00, 0x01, 0x04, 0x20};
char MTAPB[8] =  {0x01, 0x03, 0x00, 0x89, 0x00, 0x01, 0x55, 0xE0};
char MTAPC[8] =  {0x01, 0x03, 0x00, 0x8A, 0x00, 0x01, 0xA5, 0xE0};
char MTVA[8]  =  {0x01, 0x03, 0x00, 0x80, 0x00, 0x01, 0x85, 0xE2};
char MTVB[8]  =  {0x01, 0x03, 0x00, 0x81, 0x00, 0x01, 0xD4, 0x22};
char MTVC[8]  =  {0x01, 0x03, 0x00, 0x82, 0x00, 0x01, 0x24, 0x22};
char MTCA[8]  =  {0x01, 0x03, 0x00, 0x83, 0x00, 0x01, 0x75, 0xE2};
char MTCB[8]  =  {0x01, 0x03, 0x00, 0x84, 0x00, 0x01, 0xC4, 0x23};
char MTCC[8]  =  {0x01, 0x03, 0x00, 0x85, 0x00, 0x01, 0x95, 0xE3};
char MTPF[8]  =  {0x01, 0x03, 0x00, 0x95, 0x00, 0x01, 0x94, 0x26};
char MTPFA[8] =  {0x01, 0x03, 0x00, 0x96, 0x00, 0x01, 0x64, 0x26};
char MTPFB[8] =  {0x01, 0x03, 0x00, 0x97, 0x00, 0x01, 0x35, 0xE6};
char MTPFC[8] =  {0x01, 0x03, 0x00, 0x98, 0x00, 0x01, 0x35, 0xE6};
char MTF[8]   =  {0x01, 0x03, 0x00, 0x11, 0x00, 0x01, 0xD4, 0x0F};
char MCFE[8]  =  {0x01, 0x03, 0x00, 0x0A, 0x00, 0x02, 0xE4, 0x09};
char MCRE[8]  =  {0x01, 0x03, 0x00, 0x08, 0x00, 0x02, 0x45, 0xC9};
char MTRAP3PT[8] = {0x01, 0x03, 0x00, 0x8B, 0x00, 0x02, 0xB4, 0x21};
char MTARPA[8] =   {0x01, 0x03, 0x00, 0x8D, 0x00, 0x01, 0x14, 0x21};
char MTARPB[8] =   {0x01, 0x03, 0x00, 0x8E, 0x00, 0x01, 0xE4, 0x21};
char MTARPC[8] =   {0x01, 0x03, 0x00, 0x8F, 0x00, 0x01, 0xB5, 0xE1};
char MTTAP3PT[8] = {0x01, 0x03, 0x00, 0x8B, 0x00, 0x02, 0xB4, 0x21};
char MTAAPA[8] =   {0x01, 0x03, 0x00, 0x8D, 0x00, 0x01, 0x14, 0x21};
char MTAAPB[8] =   {0x01, 0x03, 0x00, 0x8E, 0x00, 0x01, 0xE4, 0x21};
char MTAAPC[8] =   {0x01, 0x03, 0x00, 0x8F, 0x00, 0x01, 0xB5, 0xE1};

//Arrays to save recieved data
unsigned char MTEI[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char MTAP1I[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char MTAPAI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTAPBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTAPCI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTVAI[7] = {0 , 0 , 0 , 0, 0, 0, 0};
unsigned char MTVBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTVCI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTCAI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTCBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTCCI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTPFI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTPFAI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTPFBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTPFCI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTFI[7] = {0, 0, 0, 0, 0, 0, 0};

unsigned char MCFEI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MCREI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTRAP3PTI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTARPAI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTARPBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTARPCI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTTAP3PTI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTAAPAI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTAAPBI[7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char MTAAPCI[7] = {0, 0, 0, 0, 0, 0, 0};

//----------------------- GLOBAL VALUES -----------------------------------
// Bool data type
bool BSent = false;
bool BSDS  = false;
bool BRST = false;
// int data type 
int i = 0, TE_a = 0 ,TCF_a=0,TCR_a=0, TP_a = 0,crccheck, count = 0;
int counter = 0;

// float data type 
float FTE = 0;    // Total Energy Reading Float (Converted)
float FFTE = 0;   // Float Total Energy After Converted into kWh Unit (Sending)
float FFREQ = 0;  // Frequncy Float Value (Sending)
float FP1 = 0;    // Power 1 Float Value  (Sending)
float FP2 = 0;    // Power 2 Float Value  (Sending)
float FP3 = 0;    // Power 3 Float Value  (Sending)
float FTP = 0;    // Total Power  Float Value  (Sending)
float FCT1 = 0;   // Current 1 Float Value (Sending)
float FCT2 = 0;   // Current 2 Float Value (Sending)
float FCT3 = 0;   // Current 3 Float Value (Sending)
float FPF1 = 0;   // Power Factor 1
float FPF2 = 0;   // Power Factor 2
float FPF3 = 0;   // Power Factor 3
float FPFT = 0;   // Total Power Factor
float TTPT = 0;  

float FCFE = 0;   
float FCRE = 0;
float FRP3 = 0;   //Reactive Power 3
float FRP2 = 0;
float FRP1 = 0;
float FTRP = 0;
float FAP3 = 0;
float FAP2 = 0;
float FAP1 = 0;

float FTAP ;
float FV1 = 0;
float FV2 = 0;
float FV3 = 0;

float CPT;
float CP1;
float CP2;
float CP3;
float CAPT;
float CAP1;
float CAP2;
float CAP3;
float CPF3;

float CRP1;
float CRP2;
float CRP3;
float CRPT;
// long data type
long RSTTime = 0;
// char data type


// String data type
String RTE;     // Total Energy Reading Packet
String RP1;     // Power 1 Reading Packet
String RP2;     // Power 2 Reading Packet
String RP3;     // Power 3 Reading Packet
String RTP;     // Total Power Reading Packet
String RCT1;    // Current 1 Reading Packet
String RCT2;    // Current 2 Reading Packet
String RCT3;    // Current 3 Reading Packet
String RFREQ;   // Frequency Reading Packet
String RPF1;    // Power Factor 1
String RPF2;    // Power Factor 2
String RPF3;    // Power Factor 3
String RPFT;    // Power Factor Total
String PushValues = "";
String ServerS = "";
String dataMessage; // SD Card Send Message
String timeStamp = "";
String STER;
String STAP;

String AllVal;
String timertc;

byte senddata[] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte writedata[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};

byte mqttsend[] = {
  B00000,
  B00100,
  B01110,
  B00100,
  B00100,
  B01110,
  B01110,
  B00000
};

//ip address
IPAddress localIp;
//String ip2Str(IPAddress ip){
//  String s="";
//  for (int i=0; i<4; i++) {
//    s += i  ? "." + String(ip[i]) : String(ip[i]);
//  }
//  return s;
//}
