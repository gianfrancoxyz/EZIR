#include <IRremote.h>
#include <HID-Project.h>


int RCV_PIN = 10; //Receive Pin

//For Promethean Projector Remote MXBE
//NEC protocol, 32b
int BTN_1 = 0x0; //Power 
int BTN_2 = 0x17; //Auto Set
int BTN_3 = 0x37; //HDMI

int x = 0;

void setup() {
    Serial.begin(115200);
    IrReceiver.begin(RCV_PIN, ENABLE_LED_FEEDBACK);
    System.begin();
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.command == 0x17){
      System.write(SYSTEM_SLEEP);
    }
    IrReceiver.resume();
  }
}
