#include "mbed.h"
DigitalIn bryter(p12); //definerer bryter for avlesning
/*danner et 4-bits ord LED-rekka, MSB=LED1, LSB=LED4 */

BusOut lys (LED4,LED3,LED2,LED1);
int main() {
    int status,ii;
    while(1) {
        if (bryter) { // Høyreskirft?
        status=8; // Initierer MSB=1
        for(ii=0; ii<4 ;ii++) { // Løkke for 4 runder
            lys=status; // Setter ut verdi til dioderekka
            status >>=1; // Skifter til høyre
            //wait_us(4000);
            ThisThread::sleep_for(30ms);
            }
        }
    else{
        status=1; // Initierer LSB=1
        for(ii=0; ii<4 ;ii++) { // Løkke for 4 runder
            lys=status; // Setter ut verdi til dioderekka
            status <<=1; // Skifter til venstre
            ThisThread::sleep_for(30ms);
            }
        }
    }
}
