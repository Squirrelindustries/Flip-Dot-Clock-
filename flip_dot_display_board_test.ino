/*
  simple flip dot display test
*/
//this is 5X7 font, see below for 5X8
static uint8_t  font_A00[96][5] = {
  { 0x00, 0x00, 0x00, 0x00, 0x00 },  // 20  32
  { 0x00, 0x00, 0x4F, 0x00, 0x00 },  // 21  33  !
  { 0x00, 0x07, 0x00, 0x07, 0x00 },  // 22  34  "
  { 0x14, 0x7F, 0x14, 0x7F, 0x14 },  // 23  35  #
  { 0x24, 0x2A, 0x7F, 0x2A, 0x12 },  // 24  36  $
  { 0x23, 0x13, 0x08, 0x64, 0x62 },  // 25  37  %
  { 0x36, 0x49, 0x55, 0x22, 0x50 },  // 26  38  &
  { 0x00, 0x05, 0x03, 0x00, 0x00 },  // 27  39  '
  { 0x00, 0x1C, 0x22, 0x41, 0x00 },  // 28  40  (
  { 0x00, 0x41, 0x22, 0x1C, 0x00 },  // 29  41  )
  { 0x14, 0x08, 0x3E, 0x08, 0x14 },  // 2A  42  *
  { 0x08, 0x08, 0x3E, 0x08, 0x08 },  // 2B  43  +
  { 0x00, 0x50, 0x30, 0x00, 0x00 },  // 2C  44  ,
  { 0x08, 0x08, 0x08, 0x08, 0x08 },  // 2D  45  -
  { 0x00, 0x60, 0x60, 0x00, 0x00 },  // 2E  46  .
  { 0x20, 0x10, 0x08, 0x04, 0x02 },  // 2F  47  /
  { 0x3E, 0x51, 0x49, 0x45, 0x3E },  // 30  48  0
  { 0x00, 0x42, 0x7F, 0x40, 0x00 },  // 31  49  1
  { 0x42, 0x61, 0x51, 0x49, 0x46 },  // 32  50  2
  { 0x21, 0x41, 0x45, 0x4B, 0x31 },  // 33  51  3
  { 0x18, 0x14, 0x12, 0x7F, 0x10 },  // 34  52  4
  { 0x27, 0x45, 0x45, 0x45, 0x39 },  // 35  53  5
  { 0x3C, 0x4A, 0x49, 0x49, 0x30 },  // 36  54  6
  { 0x03, 0x01, 0x71, 0x09, 0x07 },  // 37  55  7
  { 0x36, 0x49, 0x49, 0x49, 0x36 },  // 38  56  8
  { 0x06, 0x49, 0x49, 0x29, 0x1E },  // 39  57  9
  { 0x00, 0x36, 0x36, 0x00, 0x00 },  // 3A  58  :
  { 0x00, 0x56, 0x36, 0x00, 0x00 },  // 3B  59  ;
  { 0x08, 0x14, 0x22, 0x41, 0x00 },  // 3C  60  <
  { 0x14, 0x14, 0x14, 0x14, 0x14 },  // 3D  61  =
  { 0x00, 0x41, 0x22, 0x14, 0x08 },  // 3E  62  >
  { 0x02, 0x01, 0x51, 0x09, 0x06 },  // 3F  63  ?
  { 0x32, 0x49, 0x79, 0x41, 0x3E },  // 40  64  @
  { 0x7E, 0x11, 0x11, 0x11, 0x7E },  // 41  65  A
  { 0x7F, 0x49, 0x49, 0x49, 0x36 },  // 42  66  B
  { 0x3E, 0x41, 0x41, 0x41, 0x22 },  // 43  67  C
  { 0x7F, 0x41, 0x41, 0x22, 0x1C },  // 44  68  D
  { 0x7F, 0x49, 0x49, 0x49, 0x41 },  // 45  69  E
  { 0x7F, 0x09, 0x09, 0x09, 0x01 },  // 46  70  F
  { 0x3E, 0x41, 0x49, 0x49, 0x7A },  // 47  71  G
  { 0x7F, 0x08, 0x08, 0x08, 0x7F },  // 48  72  H
  { 0x00, 0x41, 0x7F, 0x41, 0x00 },  // 49  73  I
  { 0x20, 0x40, 0x41, 0x3F, 0x01 },  // 4A  74  J
  { 0x7F, 0x08, 0x14, 0x22, 0x41 },  // 4B  75  K
  { 0x7F, 0x40, 0x40, 0x40, 0x40 },  // 4C  76  L
  { 0x7F, 0x02, 0x0C, 0x02, 0x7F },  // 4D  77  M
  { 0x7F, 0x04, 0x08, 0x10, 0x7F },  // 4E  78  N
  { 0x3E, 0x41, 0x41, 0x41, 0x3E },  // 4F  79  O
  { 0x7F, 0x09, 0x09, 0x09, 0x06 },  // 50  80  P
  { 0x3E, 0x41, 0x51, 0x21, 0x5E },  // 51  81  Q
  { 0x7F, 0x09, 0x19, 0x29, 0x46 },  // 52  82  R
  { 0x46, 0x49, 0x49, 0x49, 0x31 },  // 53  83  S
  { 0x01, 0x01, 0x7F, 0x01, 0x01 },  // 54  84  T
  { 0x3F, 0x40, 0x40, 0x40, 0x3F },  // 55  85  U
  { 0x1F, 0x20, 0x40, 0x20, 0x1F },  // 56  86  V
  { 0x3F, 0x40, 0x38, 0x40, 0x3F },  // 57  87  W
  { 0x63, 0x14, 0x08, 0x14, 0x63 },  // 58  88  X
  { 0x07, 0x08, 0x70, 0x08, 0x07 },  // 59  89  Y
  { 0x61, 0x51, 0x49, 0x45, 0x43 },  // 5A  90  Z
  { 0x7F, 0x41, 0x41, 0x00, 0x00 },  // 5B  91  [
  { 0x15, 0x16, 0x7C, 0x16, 0x15 },  // 5C  92  '\'
  { 0x00, 0x41, 0x41, 0x7F, 0x00 },  // 5D  93  ]
  { 0x04, 0x02, 0x01, 0x02, 0x04 },  // 5E  94  ^
  { 0x40, 0x40, 0x40, 0x40, 0x40 },  // 5F  95  _
  { 0x00, 0x01, 0x02, 0x04, 0x00 },  // 60  96  `
  { 0x20, 0x54, 0x54, 0x54, 0x78 },  // 61  97  a
  { 0x7F, 0x48, 0x44, 0x44, 0x38 },  // 62  98  b
  { 0x38, 0x44, 0x44, 0x44, 0x20 },  // 63  99  c
  { 0x38, 0x44, 0x44, 0x48, 0x7F },  // 64 100  d
  { 0x38, 0x54, 0x54, 0x54, 0x18 },  // 65 101  e
  { 0x08, 0x7E, 0x09, 0x01, 0x02 },  // 66 102  f
  { 0x0C, 0x52, 0x52, 0x52, 0x3E },  // 67 103  g
  { 0x7F, 0x08, 0x04, 0x04, 0x78 },  // 68 104  h
  { 0x00, 0x44, 0x7D, 0x40, 0x00 },  // 69 105  i
  { 0x20, 0x40, 0x44, 0x3D, 0x00 },  // 6A 106  j
  { 0x7F, 0x10, 0x28, 0x44, 0x00 },  // 6B 107  k
  { 0x00, 0x41, 0x7F, 0x40, 0x00 },  // 6C 108  l
  { 0x7C, 0x04, 0x18, 0x04, 0x78 },  // 6D 109  m
  { 0x7C, 0x08, 0x04, 0x04, 0x78 },  // 6E 110  n
  { 0x38, 0x44, 0x44, 0x44, 0x38 },  // 6F 111  o
  { 0x7C, 0x14, 0x14, 0x14, 0x08 },  // 70 112  p
  { 0x08, 0x14, 0x14, 0x18, 0x7C },  // 71 113  q
  { 0x7C, 0x08, 0x04, 0x04, 0x08 },  // 72 114  r
  { 0x48, 0x54, 0x54, 0x54, 0x20 },  // 73 115  s
  { 0x04, 0x3F, 0x44, 0x40, 0x20 },  // 74 116  t
  { 0x3C, 0x40, 0x40, 0x20, 0x7C },  // 75 117  u
  { 0x1C, 0x20, 0x40, 0x20, 0x1C },  // 76 118  v
  { 0x3C, 0x40, 0x38, 0x40, 0x3C },  // 77 119  w
  { 0x44, 0x28, 0x10, 0x28, 0x44 },  // 78 120  x
  { 0x0C, 0x50, 0x50, 0x50, 0x3C },  // 79 121  y
  { 0x44, 0x64, 0x54, 0x4C, 0x44 },  // 7A 122  z
  { 0x00, 0x08, 0x36, 0x41, 0x00 },  // 7B 123  {
  { 0x00, 0x00, 0x7F, 0x00, 0x00 },  // 7C 124  |
  { 0x00, 0x41, 0x36, 0x08, 0x00 },  // 7D 125  }
  { 0x08, 0x08, 0x2A, 0x1C, 0x08 },  // 7E 126  ~
  { 0x08, 0x1C, 0x2A, 0x08, 0x08 }   // 7F 127
};

//this is 5X8 font - note might need to recode to 2 dim array like above??
const unsigned char font[] =
{
      0x00,0x00,0x00,0x00,0x00,  // space
      0x00,0x00,0x5f,0x00,0x00,  // !
      0x00,0x07,0x00,0x07,0x00,  // "
      0x14,0x7f,0x14,0x7f,0x14,  // #
      0x24,0x2a,0x6b,0x2a,0x12,  // $
      0x63,0x13,0x08,0x64,0x63,  // %
      0x36,0x49,0x56,0x20,0x50,  // &
      0x00,0x00,0x07,0x00,0x00,  // '
      0x00,0x3c,0x42,0x81,0x00,  // (
      0x00,0x81,0x42,0x3c,0x00,  // )
      0x14,0x08,0x3e,0x08,0x14,  // *
      0x08,0x08,0x3e,0x08,0x08,  // +
      0x00,0x80,0x60,0x00,0x00,  // ,
      0x08,0x08,0x08,0x08,0x08,  // -
      0x00,0x00,0x60,0x00,0x00,  // .
      0xc0,0x30,0x0c,0x03,0x00,  // /
      0x3e,0x51,0x49,0x45,0x3e,  // 0
      0x00,0x42,0x7f,0x40,0x00,  // 1
      0x62,0x51,0x49,0x49,0x46,  // 2
      0x22,0x41,0x49,0x49,0x36,  // 3
      0x18,0x14,0x12,0x7f,0x10,  // 4
      0x27,0x45,0x45,0x45,0x39,  // 5
      0x3c,0x4a,0x49,0x49,0x30,  // 6
      0x01,0x71,0x09,0x05,0x03,  // 7
      0x36,0x49,0x49,0x49,0x36,  // 8
      0x06,0x49,0x49,0x29,0x1e,  // 9
      0x00,0x00,0x6c,0x00,0x00,  // :
      0x00,0x80,0x6c,0x00,0x00,  // ;
      0x08,0x14,0x22,0x41,0x00,  // <
      0x24,0x24,0x24,0x24,0x24,  // =
      0x00,0x41,0x22,0x14,0x08,  // >
      0x02,0x01,0x51,0x09,0x06,  // ?

      0x3e,0x41,0x5d,0x55,0x1e,  // @
      0x7c,0x12,0x11,0x12,0x7c,  // A
      0x7f,0x49,0x49,0x49,0x36,  // B
      0x3e,0x41,0x41,0x41,0x22,  // C
      0x7f,0x41,0x41,0x41,0x3e,  // D
      0x7f,0x49,0x49,0x49,0x41,  // E
      0x7f,0x09,0x09,0x09,0x01,  // F
      0x3e,0x41,0x49,0x49,0x7a,  // G
      0x7f,0x08,0x08,0x08,0x7f,  // H
      0x00,0x41,0x7f,0x41,0x00,  // I
      0x20,0x40,0x40,0x40,0x3f,  // J
      0x7f,0x08,0x14,0x22,0x41,  // K
      0x7f,0x40,0x40,0x40,0x40,  // L
      0x7f,0x02,0x0c,0x02,0x7f,  // M
      0x7f,0x04,0x08,0x10,0x7f,  // N
      0x3e,0x41,0x41,0x41,0x3e,  // O
      0x7f,0x09,0x09,0x09,0x06,  // P
      0x3e,0x41,0x51,0x21,0x5e,  // Q
      0x7f,0x09,0x19,0x29,0x46,  // R
      0x26,0x49,0x49,0x49,0x32,  // S
      0x01,0x01,0x7f,0x01,0x01,  // T
      0x3f,0x40,0x40,0x40,0x3f,  // U
      0x1f,0x20,0x40,0x20,0x1f,  // V
      0x1f,0x60,0x18,0x60,0x1f,  // W
      0x63,0x14,0x08,0x14,0x63,  // X
      0x03,0x04,0x78,0x04,0x03,  // Y
      0x61,0x51,0x49,0x45,0x43,  // Z
      0x00,0xff,0x81,0x81,0x00,  // [
      0x03,0x0c,0x30,0xc0,0x00,  // backslash
      0x00,0x81,0x81,0xff,0x00,  // ]
      0x04,0x02,0x01,0x02,0x04,  // ^
      0x80,0x80,0x80,0x80,0x80,  // _

      0x06,0x09,0x09,0x06,0x00,  // ` (Degree symbol)
      0x20,0x54,0x54,0x54,0x78,  // a
      0x7f,0x48,0x48,0x48,0x30,  // b
      0x38,0x44,0x44,0x44,0x00,  // c
      0x30,0x48,0x48,0x48,0x7f,  // d
      0x38,0x54,0x54,0x54,0x08,  // e
      0x08,0x7e,0x09,0x09,0x00,  // f
      0x18,0xa4,0xa4,0xa4,0x7c,  // g
      0x7f,0x08,0x08,0x70,0x00,  // h
      0x00,0x00,0x7d,0x40,0x00,  // i
      0x40,0x80,0x84,0x7d,0x00,  // j
      0x7f,0x10,0x28,0x44,0x00,  // k
      0x00,0x00,0x7f,0x40,0x00,  // l
      0x7c,0x04,0x18,0x04,0x78,  // m
      0x7c,0x04,0x04,0x78,0x00,  // n
      0x38,0x44,0x44,0x44,0x38,  // o
      0xfc,0x24,0x24,0x24,0x18,  // p
      0x18,0x24,0x24,0x24,0xfc,  // q
      0x7c,0x08,0x04,0x04,0x00,  // r
      0x08,0x54,0x54,0x54,0x20,  // s
      0x04,0x3e,0x44,0x44,0x00,  // t
      0x3c,0x40,0x40,0x20,0x7c,  // u
      0x1c,0x20,0x40,0x20,0x1c,  // v
      0x3c,0x60,0x30,0x60,0x3c,  // w
      0x6c,0x10,0x10,0x6c,0x00,  // x
      0x9c,0xa0,0x60,0x3c,0x00,  // y
      0x64,0x54,0x54,0x4c,0x00,  // z
      0x00,0x08,0x76,0x81,0x81,  // {
      0x00,0x00,0xff,0x00,0x00,  // |
      0x81,0x81,0x76,0x08,0x00,  // }
      0x4c,0x72,0x02,0x72,0x4c,  // ~ (Omega character)
      0x55,0x2a,0x55,0x2a,0x55   // del
};
#define FET18V 25 //define the control pin
#define SER 5 //define the serial data input pin
#define SRCLK 32 //define the serial input clock pin(the shift register clock input)
#define RCLK 19 //define the latch pin(storage register clock input)

byte j=0;
byte j2=255;
int row = 0;
int col = 0;
byte osend;
byte setReset =1;
void setup() {                
  // initialize the digital pin as an output.
  pinMode(FET18V, OUTPUT); 
  digitalWrite(FET18V,LOW);
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  digitalWrite(SRCLK,LOW);
  digitalWrite(RCLK,LOW);
  Serial.begin(115200);
}
void loop()
{
  
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,5); //Set the reset bit
  write595(osend);
  //delay(1);
  //write595(0);
  
  for (col = 0;col < 28; col++ ) {
    //Serial.print("Col=");
    //Serial.println(col);
    for (row = 0;row < 7;row++) {
      //Serial.print("Row=");
      //Serial.println(row);
      
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      if (setReset) bitSet(osend,6); //Set the Set/Unset bit
      write595(osend);
     
      //Now flash the 18V FET line
      pulseFET();
     
      //write595(0);
      //delay(50); // just so we can slow it down a bit
      
      //At end advance the row
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      bitSet(osend,7); //Set the Row advance
      write595(osend);
      //delay(1);
      //write595(0);
    }
    //At end advance the column
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
    //delay(1);
    //write595(0);
  }
  Serial.print("End, sleep 2s");
  delay(2000);
  if (setReset) setReset = 0; else setReset = 1;
  /*
  digitalWrite(FET18V,LOW);
  delay(5000);
  digitalWrite(FET18V,HIGH);
  delay(5000);
  */
  
  //delay(1000);
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,5); //Set the reset bit
  write595(osend);

  
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  

  //Now lets try display some characters:
 
  for (col = 0;col < 5; col++ ) {
    //Serial.print("Col=");
    //Serial.println(col);
    for (row = 0;row<7;row++) {
      //Serial.print("Row=");
      //Serial.println(row);
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      if bitRead(font_A00[16][col],row) bitSet(osend,6); else bitClear(osend,6);  //"0"
      write595(osend);
      pulseFET();
      //At end advance the row
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      bitSet(osend,7); //Set the Row advance
      write595(osend);
    }
    //At end advance the column
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
  }
  
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  
  // next 5 cols
  for (col = 0;col < 5; col++ ) {
    //Serial.print("Col=");
    //Serial.println(col);
    for (row = 0;row<7;row++) {
      //Serial.print("Row=");
      //Serial.println(row);
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      if bitRead(font_A00[16+2][col],row) bitSet(osend,6); else bitClear(osend,6);  //"2"
      write595(osend);
      pulseFET();
      //At end advance the row
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      bitSet(osend,7); //Set the Row advance
      write595(osend);
    }
    //At end advance the column
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
  }
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);

  //Now do 2 rows of "Colons"
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (int i = 0;i<2;i++) {
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    if (row == 1 || row == 2 || row == 4 || row == 5 ) bitSet(osend,6);
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  }
  
 //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  
  //now 2 more digits with a gap inbetween
  //Now lets try display some characters:
  
  for (col = 0;col < 5; col++ ) {
    //Serial.print("Col=");
    //Serial.println(col);
    for (row = 0;row<7;row++) {
      //Serial.print("Row=");
      //Serial.println(row);
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      if bitRead(font_A00[16+4][col],row) bitSet(osend,6); else bitClear(osend,6);  //"4"
      write595(osend);
      pulseFET();
      //At end advance the row
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      bitSet(osend,7); //Set the Row advance
      write595(osend);
    }
    //At end advance the column
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
  }
  
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  
  // next 5 cols
  for (col = 0;col < 5; col++ ) {
    //Serial.print("Col=");
    //Serial.println(col);
    for (row = 0;row<7;row++) {
      //Serial.print("Row=");
      //Serial.println(row);
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      if bitRead(font_A00[16+7][col],row) bitSet(osend,6); else bitClear(osend,6);  //"7"
      write595(osend);
      pulseFET();
      //At end advance the row
      osend = 15; //set all 4 display output enables, bits 1,2,3,4
      bitSet(osend,7); //Set the Row advance
      write595(osend);
    }
    //At end advance the column
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
  }
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);

  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  
  for (int j = 0;j<10;j++) {
  //Now flash the colons a few times
  delay(500);
  //reset counters to start
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,5); //Set the reset bit
  write595(osend);

  for (col = 0; col < 13;col++ ) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the col advance
    write595(osend);
    write595(15);  
  }
  //Now do 2 rows of "Colons"
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (int i = 0;i<2;i++) {
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    //if (row == 1 || row == 2 || row == 4 || row == 5 ) bitSet(osend,6);
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  }
  delay(500);
  //reset counters to start
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,5); //Set the reset bit
  write595(osend);

  for (col = 0; col < 13;col++ ) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,4); //Set the Col advance
    write595(osend);
    write595(15);  
  }
  //Now do 2 rows of "Colons"
  //At end advance the column again to leave a space
  // we need to blank out all the dots
  for (int i = 0;i<2;i++) {
  for (row = 0;row<7;row++) {
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    if (row == 1 || row == 2 || row == 4 || row == 5 ) bitSet(osend,6);
    write595(osend);
    pulseFET();
    //At end advance the row
    osend = 15; //set all 4 display output enables, bits 1,2,3,4
    bitSet(osend,7); //Set the Row advance
    write595(osend);
  }
  osend = 15; //set all 4 display output enables, bits 1,2,3,4
  bitSet(osend,4); //Set the Col advance
  //delay(1); write595(15); delay(1);
  write595(osend);
  //write595(15);
  }
  }
  
  delay(2000);
}
void pulseFET(){
  digitalWrite(FET18V,HIGH);
  delay(1);
  digitalWrite(FET18V,LOW);
}      
void write595(byte data1 )
{
  digitalWrite(RCLK, LOW);
  shiftOut(SER, SRCLK, MSBFIRST, data1);
  digitalWrite(RCLK, HIGH);  
  delay(1); digitalWrite(RCLK, LOW);
}