Title: Read and W#rite GPIO on the Galileo Gen 2 Board

Description:

A microkernel application that demonstrates GPIO input and output on
the Galileo Gen2 board.

A button must be connected to the D3 connector pin and an LED must be
connected to the D4 connector pin.

The Grove Starter Kit for Arduino from Seeed Studio is suggested for use with
this example. To simplify device access, the Base Shield is installed
onto the Arduino connectors and appropriate Grove modules are connected to
the ports matching the specified connector pins.

The application performs as follows:

1) The on-board LED (same as D13) blinks constantly.

2) The input value of the D3 connector pin is polled and printed on the screen.

3) The output value of the D4 connector pin is determined by the input value of
   the D3 connector pin. An LED connected to the D4 connector pin is
   turned off if the value on input pin D3 is low (0v). The LED is
   turned on if the value on input pin D3 is high (5v).


Sample Output matches the state of the button and the LED.

Booting...
Jumping to boot image at 0x100000...
Pin 3 configured
Pin 4 configured
Pin 13 configured
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Hi
D3 = Hi
D3 = Hi
D3 = Hi
D3 = Low
D3 = Low
D3 = Low
D3 = Hi
D3 = Hi
D3 = Hi
D3 = Hi
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low
D3 = Low

<repeats endlessly>
