// testshapes demo for RGBmatrixPanel library.
// Demonstrates the drawing abilities of the RGBmatrixPanel library.
// For 64x64 RGB LED matrix.

// WILL NOT FIT on ARDUINO UNO -- requires a Mega, M0 or M4 board

#include "RGBmatrixPanel.h"

#include "bit_bmp.h"
#include "fonts.h"
#include <string.h>
#include <stdlib.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

//#define CLK  8   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
#define E   A4

RGBmatrixPanel matrix(A, B, C, D, E, CLK, LAT, OE, false, 64);
//Configure the serial port to use the standard printf function

void setup()
{
  Serial.begin(115200);
  matrix.begin();

  //Control signal Block
  matrix.drawRect(22, 1, 6, 14, matrix.Color333(0, 0, 3.5));

  matrix.drawLine(18, 3, 21, 3, matrix.Color333(2.5, 2.5, 2.5));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(2.5, 2.5, 2.5));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(2.5, 2.5, 2.5));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(2.5, 2.5, 2.5));//rd
  
  //Bus
 matrix.drawLine(18, 1, 18, 60, matrix.Color333(2.5, 2.5, 2.5));
 
  //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(2.5, 2.5, 2.5));


  //Control signal Path control regsrc
  matrix.drawLine(23, 15, 23, 20, matrix.Color333(0,4.5,3.5));

  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,4.5,3.5));

  //Control signal Path immsrc
  matrix.drawLine(28, 11, 34, 11, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,4.5,3.5));

  //Control signal Path alu source
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(0,4.5,3.5));

  //Control signal Path alu control
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(0,4.5,3.5));

  //Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(0,4.5,3.5));

  // Control signal mem to reg
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(0,4.5,3.5));
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(0,4.5,3.5));
  
  //pc block
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(0, 7, 0));

  //ins memory
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(0, 7, 0));//ins memory

  //pc block to alu

  
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(2.5, 2.5, 2.5)); // Pc block to IM
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(2.5, 2.5, 2.5));

  //alu 1
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 7, 0));

  // Alu plus adding 4

  matrix.drawLine(8, 23, 9, 23, matrix.Color333(2.5, 2.5, 2.5)); 
  //4
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(2.76, 3.88, 1.82)); 

  //alu

  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  
  //inst memory tto bus
  matrix.drawLine(12, 11, 18, 11, matrix.Color333(2.5, 2.5, 2.5));
  

  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));


  //mux 1
  matrix.drawLine(22, 19, 24, 21, matrix.Color333(7, 0,7));
  matrix.drawLine(22, 19, 22, 25, matrix.Color333(7, 0,7));
  matrix.drawLine(22, 25, 24, 23, matrix.Color333(7, 0,7));
  matrix.drawLine(24, 23, 24, 21, matrix.Color333(7, 0,7));
  //mux
  
  //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(2.5, 2.5, 2.5));
  //bus to mux 3:0
  matrix.drawLine(18, 20, 21, 20, matrix.Color333(2.5, 2.5, 2.5));

  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(2.5, 2.5, 2.5));

  //bus to mux 15:12
  matrix.drawLine(20 ,24, 21, 24, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20 ,24, 20, 27, matrix.Color333(2.5, 2.5, 2.5));

  //mux to reg file
  matrix.drawLine(25 ,22, 26, 22, matrix.Color333(2.5, 2.5, 2.5));


  //extend
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(0, 7, 0));
 


  //mux 2
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7, 0,7));

  // line reg to mux
  matrix.drawLine(34, 29, 38, 29, matrix.Color333(2.5, 2.5, 2.5));

  // line extender to mux
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(2.5, 2.5, 2.5));

  //alu2
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 7, 0));
  
  //Data Memory

  matrix.drawRect(49, 23, 6, 17, matrix.Color333(0, 7, 0));//reg file
  
  //mux 3
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,7));

  //mux2 to alu
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(2.5, 2.5, 2.5));
  
  //alu to data memory
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(2.5, 2.5, 2.5));
  
  //rd2 to data memory
  matrix.drawLine(37, 29, 37, 37, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(37, 37, 48, 37, matrix.Color333(2.5, 2.5, 2.5));

  //rd1 to alu
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(2.5, 2.5, 2.5));

  //data mem to mux
  matrix.drawLine(54, 32, 57, 32, matrix.Color333(2.5, 2.5, 2.5));

  //alu result to mux
  matrix.drawLine(47, 29, 47, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(47, 42, 55, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 42, 55, 34, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 34, 56, 34, matrix.Color333(2.5, 2.5, 2.5));

  //result to wd3
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20, 29, 20, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20, 52, 61, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61,52, 61, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61, 33, 60, 33, matrix.Color333(2.5, 2.5, 2.5));


}



void loop()
{

  LDR();
  ADD();
  SUB();
  // Do nothing -- image doesn't change
 //Demo_0();
 //Demo_1();
 //Demo_2();
 //matrix.drawLine(25, 50, 25, 60, matrix.Color333(7, 0, 0));
 //delay(500);
//matrix.drawLine(25, 50, 25, 60, matrix.Color333(0, 0, 0));
 //matrix.drawLine(26 ,50, 26, 60, matrix.Color333(7, 0, 0));
 //delay(500);
  //matrix.drawLine(26 ,50, 26, 60, matrix.Color333(0, 0, 0));
}

//Clear screen
void screen_clear()
{
  matrix.fillRect(0, 0, matrix.width(), matrix.height(), matrix.Color333(0, 0, 0));
}

void LDR()
{
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  //pc block Red 
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(7, 0, 0));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);
  //Pc block Normal
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(0, 7, 0));
  delay(2000);

  // Pc block to IM
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  // Pc block to IM 
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(7, 0, 0));//ins memory
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(2.5, 2.5, 2.5)); // Pc block to IM
  delay(2000);

  //inst memory tto bus
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(7, 0, 0));
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(0, 7, 0));//ins memory
  delay(2000);

  //Bus
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(7, 0, 0));
  //inst memory tto bus
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  
  //Bus Normal
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(2.5, 2.5, 2.5));
  
  //bus to Control, Rg and extend
  //Control
  //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(7, 0, 0));

  matrix.drawLine(18, 3, 21, 3, matrix.Color333(7, 0, 0));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(7, 0, 0));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(7, 0, 0));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(7, 0, 0));//rd

  //Rg
  //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(7, 0, 0));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(7, 0, 0));
  delay(2000);
  
  //bus to Control, Rg and extend Normal
  matrix.drawLine(18, 3, 21, 3, matrix.Color333(2.5, 2.5, 2.5));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(2.5, 2.5, 2.5));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(2.5, 2.5, 2.5));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(2.5, 2.5, 2.5));//rd

   //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(2.5, 2.5, 2.5));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

   //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(2.5, 2.5, 2.5));


  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));
  //extend
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(7, 0, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(7, 0, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(7, 0, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(7, 0, 0));

  delay(2000);

  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(7, 0, 0));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,4.5,3.5));
  //Control signal Path immsrc
  matrix.drawLine(28, 11, 34, 11, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);
  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(7,0,0));

  matrix.drawLine(28, 11, 34, 11, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(7,0,0));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal regwrite
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,3.5,3.5));

  //Control signal Path immsrc
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);

//extend Normal
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(0, 7, 0));

//Registerfile Normal
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

//Line rd1 to alu Red
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(7,0,0));

// line extender to mux
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(7,0,0));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(7,0,0));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(7,0,0));

  delay(2000);

//mux 2 Red
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7,0,0));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7,0,0));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7,0,0));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7,0,0));
// line extender to mux normal
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(7,0,0));
  delay(200);
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(0,3.5,3.5));
  delay(2000);

  //mux 2 Normal
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7, 0,7));

  //mux to alu Red
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(7,0,0));
  delay(2000);

 //alu2 Red
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 0, 0));

   delay(1000);

//Line rd1 to alu Normal
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(2.5,2.5,2.5));

  //mux2 to alu
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);

    //Control signal Path alu control Red
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(7,0,0));
  delay(2000);


  //Control signal Path alu control
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(0,3.5,3.5));
 //alu2
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 7, 0));
  delay(2000);

//alu to data memory Red
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(7, 0, 0));
  delay(2000);

//Data Memory Red
  matrix.drawRect(49, 23, 6, 17, matrix.Color333(7, 0, 0));//reg file
//alu to data memory 
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(7, 0, 0));
  delay(400);
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(7, 0, 0));
  delay(2000);

//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(0,3.5,3.5));
//Data Memory Red
  matrix.drawRect(49, 23, 6, 17, matrix.Color333(0, 7, 0));//reg file
  delay(2000);

  //data mem to mux
  matrix.drawLine(54, 32, 57, 32, matrix.Color333(7, 0, 0));
  delay(2000);

//data mem to mux
  matrix.drawLine(54, 32, 57, 32, matrix.Color333(2.5, 2.5, 2.5));
  
  //mux 3 Red
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,0));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,0));
  delay(2000);

  // Control signal mem to reg Red 
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(7, 0, 0));
  delay(400);
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(7, 0, 0));
  delay(2000);




  //mux 3 Normal
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,7));
  // Control signal mem to reg Normal
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(0,3.5,3.5));

  delay(2000);

   //result to wd3
   matrix.drawLine(61, 33, 60, 33, matrix.Color333(7,0,0));
  delay(2000);
   matrix.drawLine(61,52, 61, 33, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 52, 61, 52, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 29, 20, 52, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(7,0,0));
  delay(400);
 
 
  

  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));
  //result to wd3
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(2.5, 2.5, 2.5));
   delay(400);
  matrix.drawLine(20, 29, 20, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20, 52, 61, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61,52, 61, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61, 33, 60, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

    //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

  // Alu plus adding 4

  //4 Red
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(7, 0, 0)); 
  delay(2000);


  // Alu plus adding 4 Red

  matrix.drawLine(8, 23, 9, 23, matrix.Color333(7, 0, 0)); 
  // pc to alu red
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(7, 0, 0));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(7, 0, 0));
  delay(2000);
  


  //alu 1 Red
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 0, 0));


  
  //4 Normal
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(2.76, 3.88, 1.82)); 

//
  matrix.drawLine(8, 23, 9, 23, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);


  //alu 1 Normal
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 7, 0));

  delay(2000);

  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7,0,0));
  delay(2000);

  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);



}


void ADD()
{
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  //pc block Red 
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(7, 0, 0));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);
  //Pc block Normal
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(0, 7, 0));
  delay(2000);

  // Pc block to IM
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  // Pc block to IM 
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(7, 0, 0));//ins memory
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(2.5, 2.5, 2.5)); // Pc block to IM
  delay(2000);

  //inst memory tto bus Red
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(7, 0, 0));
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(0, 7, 0));//ins memory
  delay(2000);

  //Bus
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(7, 0, 0));
  //inst memory tto bus normal
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  
  //Bus Normal
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(2.5, 2.5, 2.5));
  
  //bus to Control, Rg and extend RED Bus to Mux
  //Control
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(18, 3, 21, 3, matrix.Color333(7, 0, 0));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(7, 0, 0));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(7, 0, 0));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(7, 0, 0));//rd

  //Rg
  //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(7, 0, 0));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(7, 0, 0));
 
  
  //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(7, 0, 0));
  
  //Bus to mux
   //bus to mux 3:0 RED
  matrix.drawLine(18, 20, 21, 20, matrix.Color333(7, 0, 0));
  delay(2000);

  // Bus to control Normal
  matrix.drawLine(18, 3, 21, 3, matrix.Color333(2.5, 2.5, 2.5));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(2.5, 2.5, 2.5));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(2.5, 2.5, 2.5));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(2.5, 2.5, 2.5));//rd

   //bus to mux 3:0
  matrix.drawLine(18, 20, 21, 20, matrix.Color333(2.5, 2.5, 2.5));

  //mux 1
  matrix.drawLine(22, 19, 24, 21, matrix.Color333(7, 0,0));
  matrix.drawLine(22, 19, 22, 25, matrix.Color333(7, 0,0));
  matrix.drawLine(22, 25, 24, 23, matrix.Color333(7, 0,0));
  matrix.drawLine(24, 23, 24, 21, matrix.Color333(7, 0,0));

  delay(1000);



  //Control signal Path control regsrc
  matrix.drawLine(23, 15, 23, 20, matrix.Color333(7,0,0));
  delay(2000);


  //mux 1
  matrix.drawLine(22, 19, 24, 21, matrix.Color333(7, 0,7));
  matrix.drawLine(22, 19, 22, 25, matrix.Color333(7, 0,7));
  matrix.drawLine(22, 25, 24, 23, matrix.Color333(7, 0,7));
  matrix.drawLine(24, 23, 24, 21, matrix.Color333(7, 0,7));
 
  //Control signal Path control regsrc
  matrix.drawLine(23, 15, 23, 20, matrix.Color333(0,4.5,3.5));

  delay(1000);

  //mux to reg file
  matrix.drawLine(25 ,22, 26, 22, matrix.Color333(7, 0, 0));
  delay(1000);


  //bus to  Rg and extend Normal


   //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(2.5, 2.5, 2.5));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);
  
  //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(2.5, 2.5, 2.5));

  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));

  matrix.drawLine(25 ,22, 26, 22, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);

  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(7, 0, 0));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,4.5,3.5));
  //Control signal Path immsrc
  matrix.drawLine(28, 11, 34, 11, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);
  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(7,0,0));

  matrix.drawLine(28, 11, 34, 11, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(7,0,0));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal regwrite
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,3.5,3.5));

  //Control signal Path immsrc
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);

//extend Normal
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(0, 7, 0));

//Registerfile Normal
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

//Line rd1 to alu Red
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(7,0,0));

// line RG to mux
 matrix.drawLine(34, 29, 38, 29, matrix.Color333(7, 0, 0));

  delay(2000);

//mux 2 Red
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7,0,0));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7,0,0));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7,0,0));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7,0,0));
// line RG to mux
  matrix.drawLine(34, 29, 38, 29, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(0,3.5,3.5));
  delay(2000);

  //mux 2 Normal
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7, 0,7));

  //mux to alu Red
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(7,0,0));
  delay(2000);

 //alu2 Red
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 0, 0));

//Line rd1 to alu Normal
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(2.5,2.5,2.5));

  //mux2 to alu
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);

    //Control signal Path alu control Red
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(7,0,0));
  delay(2000);


  //Control signal Path alu control
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(0,3.5,3.5));
 //alu2
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 7, 0));
  delay(2000);

//alu to data memory Red
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(7, 0, 0));
  delay(2000);


//alu to data memory 
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

//alu result to mux RED
  matrix.drawLine(47, 29, 47, 42, matrix.Color333(7, 0, 0));
  matrix.drawLine(47, 42, 55, 42, matrix.Color333(7, 0, 0));
  matrix.drawLine(55, 42, 55, 34, matrix.Color333(7, 0, 0));
  matrix.drawLine(55, 34, 56, 34, matrix.Color333(7, 0, 0));



//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(7, 0, 0));
  delay(400);
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(7, 0, 0));
  delay(2000);

//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(0,3.5,3.5));
  delay(2000);

  //alu result to mux
  matrix.drawLine(47, 29, 47, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(47, 42, 55, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 42, 55, 34, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 34, 56, 34, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);

//data mem to mux

  
  //mux 3 Red
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,0));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,0));
  delay(2000);

  // Control signal mem to reg Red 
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(7, 0, 0));
  delay(200);
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(7, 0, 0));
  delay(2000);




  //mux 3 Normal
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,7));
  // Control signal mem to reg Normal
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(0,3.5,3.5));

  delay(2000);

   //result to wd3
   matrix.drawLine(61, 33, 60, 33, matrix.Color333(7,0,0));
  delay(2000);
   matrix.drawLine(61,52, 61, 33, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 52, 61, 52, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 29, 20, 52, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(7,0,0));
  delay(400);
 
 
  

  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));
  //result to wd3
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(2.5, 2.5, 2.5));
   delay(400);
  matrix.drawLine(20, 29, 20, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20, 52, 61, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61,52, 61, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61, 33, 60, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

    //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

  // Alu plus adding 4

  //4 Red
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(7, 0, 0)); 
  delay(2000);


  // Alu plus adding 4 Red

  matrix.drawLine(8, 23, 9, 23, matrix.Color333(7, 0, 0)); 
  // pc to alu red
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(7, 0, 0));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(7, 0, 0));
  delay(2000);
  


  //alu 1 Red
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 0, 0));


  
  //4 Normal
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(2.76, 3.88, 1.82)); 

//
  matrix.drawLine(8, 23, 9, 23, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);


  //alu 1 Normal
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 7, 0));

  delay(2000);


  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(7,0,0));
  delay(300);
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7,0,0));
  delay(2000);

  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(3000);

}



void SUB()
{
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  //pc block Red 
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(7, 0, 0));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);
  //Pc block Normal
  matrix.drawRect(4, 9, 3, 4, matrix.Color333(0, 7, 0));
  delay(2000);

  // Pc block to IM
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(7, 0, 0));
  delay(2000);
  // Pc block to IM 
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(7, 0, 0));//ins memory
  matrix.drawLine(7, 11, 7, 11, matrix.Color333(2.5, 2.5, 2.5)); // Pc block to IM
  delay(2000);

  //inst memory tto bus
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(7, 0, 0));
  matrix.drawRect(8, 8, 4, 7, matrix.Color333(0, 7, 0));//ins memory
  delay(2000);

  //Bus
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(7, 0, 0));
  //inst memory tto bus
  matrix.drawLine(12, 11, 17, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  
  //Bus Normal
  matrix.drawLine(18, 1, 18, 60, matrix.Color333(2.5, 2.5, 2.5));
  
  //bus to Control, Rg and extend
  //Control
  //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(7, 0, 0));

  matrix.drawLine(18, 3, 21, 3, matrix.Color333(7, 0, 0));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(7, 0, 0));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(7, 0, 0));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(7, 0, 0));//rd

  //Rg
  //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(7, 0, 0));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(7, 0, 0));
  delay(2000);
  
  //bus to Control, Rg and extend Normal
  matrix.drawLine(18, 3, 21, 3, matrix.Color333(2.5, 2.5, 2.5));///cond
  matrix.drawLine(18, 5, 21, 5, matrix.Color333(2.5, 2.5, 2.5));//op
  matrix.drawLine(18, 7, 21, 7, matrix.Color333(2.5, 2.5, 2.5));//func
  matrix.drawLine(18, 9, 21, 9, matrix.Color333(2.5, 2.5, 2.5));//rd

   //bus to reg file 19:16
  matrix.drawLine(18, 17, 26, 17, matrix.Color333(2.5, 2.5, 2.5));
  //bus to reg file 15:12
  matrix.drawLine(18, 27, 27, 27, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

   //bus to extend
  matrix.drawLine(23, 45, 19, 45, matrix.Color333(2.5, 2.5, 2.5));


  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));
  //extend
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(7, 0, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(7, 0, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(7, 0, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(7, 0, 0));

  delay(2000);

  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(7, 0, 0));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,4.5,3.5));
  //Control signal Path immsrc
  matrix.drawLine(28, 11, 34, 11, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(7, 0, 0));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);
  //Control signal regwrite
  matrix.drawLine(28, 13, 30, 13, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(7,0,0));

  matrix.drawLine(28, 11, 34, 11, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 11, 34, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(7,0,0));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal regwrite
  matrix.drawLine(30, 13, 30, 15, matrix.Color333(0,3.5,3.5));

  //Control signal Path immsrc
  matrix.drawLine(34, 34, 26, 34, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(26, 34, 26, 39, matrix.Color333(0,3.5,3.5));
  delay(2000);

//extend Normal
  matrix.drawLine(23, 43, 31, 35, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 43, 23, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(23, 46, 31, 46, matrix.Color333(0, 7, 0));
  matrix.drawLine(31, 46, 31, 35, matrix.Color333(0, 7, 0));

//Registerfile Normal
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

//Line rd1 to alu Red
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(7,0,0));

// line extender to mux
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(7,0,0));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(7,0,0));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(7,0,0));

  delay(2000);

//mux 2 Red
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7,0,0));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7,0,0));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7,0,0));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7,0,0));
// line extender to mux normal
  matrix.drawLine(31, 42, 36, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 42, 36, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(36, 33, 38, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(7,0,0));
  delay(200);
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(7,0,0));
  delay(2000);

  //Control signal Path alu source Red
  matrix.drawLine(28, 9, 40, 9, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(40, 9, 40, 28, matrix.Color333(0,3.5,3.5));
  delay(2000);

  //mux 2 Normal
  matrix.drawLine(39, 28, 39, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 28, 41, 30, matrix.Color333(7, 0,7));
  matrix.drawLine(39, 34, 41, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(41, 30, 41, 32, matrix.Color333(7, 0,7));

  //mux to alu Red
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(7,0,0));
  delay(2000);

 //alu2 Red
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 0, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 0, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 0, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 0, 0));

//Line rd1 to alu Normal
  matrix.drawLine(34, 26, 42, 26, matrix.Color333(2.5,2.5,2.5));

  //mux2 to alu
  matrix.drawLine(42, 31, 42, 31, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);

    //Control signal Path alu control Red
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(7,0,0));
  delay(2000);


  //Control signal Path alu control
  matrix.drawLine(28, 7, 45, 7, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(45, 7, 45, 25, matrix.Color333(0,3.5,3.5));
 //alu2
  matrix.drawLine(43, 24, 46, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 24, 43, 27, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 27, 44, 28, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 28, 44, 29, matrix.Color333(7, 7, 0));
  matrix.drawLine(44, 29, 43, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 30, 43, 33, matrix.Color333(7, 7, 0));
  matrix.drawLine(43, 33, 46, 30, matrix.Color333(7, 7, 0));
  matrix.drawLine(46, 30, 46, 27, matrix.Color333(7, 7, 0));
  delay(2000);

//alu to data memory Red
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(7, 0, 0));
  delay(2000);

  //alu result to mux
  matrix.drawLine(47, 29, 47, 42, matrix.Color333(7,0,0));
  matrix.drawLine(47, 42, 55, 42, matrix.Color333(7,0,0));
  matrix.drawLine(55, 42, 55, 34, matrix.Color333(7,0,0));
  matrix.drawLine(55, 34, 56, 34, matrix.Color333(7,0,0));


//alu to data memory 
  matrix.drawLine(46, 29, 48, 29, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(7, 0, 0));
  delay(400);
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(7, 0, 0));
  delay(2000);

//Control Signal path mem write
  matrix.drawLine(28, 5, 52, 5, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(52, 5, 52, 22, matrix.Color333(0,3.5,3.5));

  delay(2000);

  //alu result to mux
  matrix.drawLine(47, 29, 47, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(47, 42, 55, 42, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 42, 55, 34, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(55, 34, 56, 34, matrix.Color333(2.5, 2.5, 2.5));
  delay(1000);
  //mux 3 Red
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,0));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,0));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,0));
  delay(2000);

  // Control signal mem to reg Red 
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(7, 0, 0));
  delay(400);
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(7, 0, 0));
  delay(2000);




  //mux 3 Normal
  matrix.drawLine(57, 30, 59, 32, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 30, 57, 36, matrix.Color333(7, 0,7));
  matrix.drawLine(57, 36, 59, 34, matrix.Color333(7, 0,7));
  matrix.drawLine(59, 34, 59, 32, matrix.Color333(7, 0,7));
  // Control signal mem to reg Normal
  matrix.drawLine(28, 3, 58, 3, matrix.Color333(0,3.5,3.5));
  matrix.drawLine(58, 3, 58, 30, matrix.Color333(0,3.5,3.5));

  delay(2000);

   //result to wd3
   matrix.drawLine(61, 33, 60, 33, matrix.Color333(7,0,0));
  delay(2000);
   matrix.drawLine(61,52, 61, 33, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 52, 61, 52, matrix.Color333(7,0,0));
  delay(400);
   matrix.drawLine(20, 29, 20, 52, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(7,0,0));
  delay(400);
 
 
  

  //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(7, 0, 0));
  //result to wd3
  matrix.drawLine(27, 29, 20, 29, matrix.Color333(2.5, 2.5, 2.5));
   delay(400);
  matrix.drawLine(20, 29, 20, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(20, 52, 61, 52, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61,52, 61, 33, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(61, 33, 60, 33, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);

    //Registerfile
  matrix.drawRect(27, 16, 7, 15, matrix.Color333(0, 7, 0));
  delay(2000);

  // Alu plus adding 4

  //4 Red
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(7, 0, 0)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(7, 0, 0)); 
  delay(2000);


  // Alu plus adding 4 Red

  matrix.drawLine(8, 23, 9, 23, matrix.Color333(7, 0, 0)); 
  // pc to alu red
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(7, 0, 0));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(7, 0, 0));
  delay(2000);
  


  //alu 1 Red
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 0, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 0, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 0, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 0, 0));


  
  //4 Normal
  matrix.drawLine(6, 23, 4, 23, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(4, 23, 4, 22, matrix.Color333(2.76, 3.88, 1.82)); 
  matrix.drawLine(6, 22, 6, 25, matrix.Color333(2.76, 3.88, 1.82)); 

//
  matrix.drawLine(8, 23, 9, 23, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 11, 7, 17, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(7, 17, 10, 17, matrix.Color333(2.5, 2.5, 2.5));

  delay(2000);


  //alu 1 Normal
  matrix.drawLine(10, 16, 13, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 16, 10, 19, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 19, 11, 20, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 20, 11, 21, matrix.Color333(7, 7, 0));
  matrix.drawLine(11, 21, 10, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 22, 10, 25, matrix.Color333(7, 7, 0));
  matrix.drawLine(10, 25, 13, 22, matrix.Color333(7, 7, 0));
  matrix.drawLine(13, 22, 13, 19, matrix.Color333(7, 7, 0));

  delay(2000);


  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(7,0,0));
  delay(400);
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(7,0,0));
  delay(2000);

  //alu to pc block
  matrix.drawLine(13, 21, 15, 21, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 21, 15, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(15, 27, 2, 27, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 27, 2, 11, matrix.Color333(2.5, 2.5, 2.5));
  matrix.drawLine(2, 11, 3, 11, matrix.Color333(2.5, 2.5, 2.5));
  delay(2000);



}
