// Will Norman
// March 2025
// GR Yaris Startup Controller
// For use with PCB v1.0

// To program the ATtiny85 dev board, you must include the following:
// File / Preferences / Additional boards manager URLs:
// http://drazzy.com/package_drazzy.com_index.json
// Boards Manager --> Install "ATTinyCore" by Spence
// Tools / Board: ATTinyCore / ATtiny85 (Micronucleus / DigiSpark)

#include <avr/sleep.h>

// Define output pins
#define LDA 0
#define IMT 1
#define A_SS 2
#define MODE_SELECT 3

void setup() {

  // Setup pins as outputs
  pinMode(LDA,OUTPUT);
  pinMode(IMT,OUTPUT);
  pinMode(A_SS,OUTPUT);
  pinMode(MODE_SELECT,OUTPUT);
  
  // Ensure pins are driven low
  digitalWrite(LDA,LOW);
  digitalWrite(IMT,LOW);
  digitalWrite(A_SS,LOW);
  digitalWrite(MODE_SELECT,LOW);

  // wait 12 seconds - give time for screen to load to debug
  delay(12000);

  // Press buttons sequentially

  // Lane departue alert
  digitalWrite(LDA,HIGH); // press LDA
  delay(4000); // wait long time
  digitalWrite(LDA,LOW); // release LDA
  delay(1000); // wait short time

  // iMT
  digitalWrite(IMT,HIGH); // press iMT
  delay(700); // wait short time
  digitalWrite(IMT,LOW); // release iMT
  delay(1000); // wait short time

  // Auto stop/start
  digitalWrite(A_SS,HIGH); // press stop/start
  delay(700); // wait short time
  digitalWrite(A_SS,LOW); // release stop/start
  delay(1000); // wait short time

  // Sport / track mode
  digitalWrite(MODE_SELECT,HIGH); // press mode select
  delay(700); // wait short time
  digitalWrite(MODE_SELECT,LOW); // release mode select
  delay(1000); // wait short time

  // sleep device
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); 

}

void loop() {

}
