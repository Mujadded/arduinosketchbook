//for matthew hardware
#include <VirtualWire.h>

#define RADIO_RX 2
#define STATUS_LED 13
#include "WProgram.h"
void setup();
void loop();
void setup()
{
     Serial.begin(57600);
     Serial.println("setup");
     pinMode( RADIO_RX, INPUT );
     vw_set_rx_pin( RADIO_RX );
     vw_setup(4000); // Bits per sec
     vw_rx_start();    // Start the receiver PLL running
     pinMode( STATUS_LED, OUTPUT );
     digitalWrite( STATUS_LED, HIGH );
}
void loop()
{

     uint8_t buf[2];
     uint8_t buflen = 2;
     if (vw_get_message(buf, &buflen)) // Non-blocking
     {
digitalWrite( STATUS_LED, HIGH );           
       int i;
           // Message with a good checksum received, dump HEX
           Serial.print("Got: ");
           for (i = 0; i < buflen; i++)
           {
               Serial.print(buf[i], HEX);
               Serial.print(" ");
           }
           Serial.println("");
           digitalWrite( STATUS_LED, LOW );
   }
}


int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

