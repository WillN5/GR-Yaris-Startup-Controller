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

  // wait 3 seconds - give car some time to startup
  delay(3000);

  // press all buttons
  digitalWrite(IMT,HIGH);
  digitalWrite(A_SS,HIGH);
  digitalWrite(MODE_SELECT,HIGH);
  digitalWrite(LDA,HIGH);

  // wait short time - 300ms
  delay(300);

  // release short press buttons
  digitalWrite(IMT,LOW);
  digitalWrite(A_SS,LOW);
  digitalWrite(MODE_SELECT,LOW);

  // wait long time - 4s total
  delay(3700);

  // release long press buttons
  digitalWrite(LDA,LOW);

  // sleep device
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); 

}

void loop() {

}
