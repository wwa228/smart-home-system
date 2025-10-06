
#include <msp430.h>

void main(void)
{
WDTCTL = WDTPW | WDTHOLD;

PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                           // to activate previously configured port settings

gpioInitIn(4,BIT1); //input
gpioInitIn(2,BIT3); //input
gpioInitOut(1,BIT0); //output
gpioInitOut(6,BIT6); //output

unsigned char value = 0;
while(1){
    value = gpioInitStatus(4, BIT1);

        if(value == 0x00){
            _delay_cycles(5000);

            gpioWrite(1, BIT0, 1); }

            else
            gpioWrite(1, BIT0, 0);
        _delay_cycles(5000);

}
//return 0;
}
