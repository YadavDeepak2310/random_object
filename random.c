#include <stdlib.h>
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xiomodule.h"

int random_m(int a)
{
	int rndm;
	rndm = rand() % a;
	return rndm;
}
int main()
{
	init_platform();

	 char xob_11,xob_12,xob_13, ob_num1;
	 char xob_21,xob_22,xob_23, ob_num2;
	 char ob_num;
	 int xobst1;
	 int xobst2;
	 char pos;

	 u16 loc = 0x08;

	 XIOModule gpo;

	 XIOModule_Initialize(&gpo, XPAR_IOMODULE_0_DEVICE_ID);
	 XIOModule_Start(&gpo);

	 xil_printf("DEEPAK YADAV\n\r");
	 xil_printf("Date : 11/24/2018\n\r");

	 while(1)
	 {

     ob_num1 = random_m(3);
     ob_num2 = random_m(3);
     ob_num = (ob_num2 << 4) | ob_num1;

     XIOModule_DiscreteWrite ( &gpo, 1, ob_num);

     xob_11 = random_m(2);
	 xob_12 = random_m(2);
	 xob_13 = random_m(2);

	 xobst1 = (xob_13 << 8) | (xob_12 << 4) | xob_11;
	 XIOModule_DiscreteWrite ( &gpo, 2, xobst1);

	 xob_21 = random_m(2);
	 xob_22 = random_m(2);
	 xob_23 = random_m(2);

	 xobst2 = (xob_23 << 8) | (xob_22 << 4) | xob_21;
	 XIOModule_DiscreteWrite ( &gpo, 4, xobst2);

	 pos = inbyte();

     if (((loc-0x1) > -1) && ((loc+0x1)<15)){
     switch (pos) {
          	 case 'w' : loc = loc;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'W' : loc = loc;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'a' : loc = loc - 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'A' : loc = loc - 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 's' : loc = loc + 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'S' : loc = loc + 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'd' : loc = loc + 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 case 'D' : loc = loc + 0x01;XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	 	 break;
          	 default :XIOModule_DiscreteWrite ( &gpo, 3, loc);
          	     break;
          	 	 	  }
     }else if(loc == 0){
    	 loc = loc + 0x01;
     }else if(loc == 14){
    	 loc = loc - 0x01;
	 }
	 else
	 {
		 xil_printf("You've reached Edge, reverse direction\n\r");
	 }
	 }
	 cleanup_platform();

	 return 0;
}

