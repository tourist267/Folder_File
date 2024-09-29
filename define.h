IO_LED1			          	R3
IO_LED1_OUT  			          TRIS3 = 0
IO_LED1_ON   			          IO_LED1 = 1
IO_LED1_OFF  			          IO_LED1 = 0
IO_LED1_IN   			          TRIS3 = 1

 
IO_LED2			          	R2
IO_LED2_OUT  			          TRIS2 = 0
IO_LED2_ON   			          IO_LED2 = 1
IO_LED2_OFF  			          IO_LED2 = 0
IO_LED2_IN   			          TRIS2 = 1

 
IO_LED3			          	R4
IO_LED3_OUT  			          TRIS4 = 0
IO_LED3_ON   			          IO_LED3 = 1
IO_LED3_OFF  			          IO_LED3 = 0
IO_LED3_IN   			          TRIS4 = 1

 
IO_LED1			          	R3A
IO_LED1_OUT  			          TRIS3A = 0
IO_LED1_ON   			          IO_LED1 = 1
IO_LED1_OFF  			          IO_LED1 = 0
IO_LED1_IN   			          TRIS3A = 1

 
IO_LED1			          	RA3
IO_LED1_OUT  			          TRISA3 = 0
IO_LED1_ON   			          IO_LED1 = 1
IO_LED1_OFF  			          IO_LED1 = 0
IO_LED1_IN   			          TRISA3 = 1

 
IO_LED3			          	RB12
IO_LED3_OUT  			          TRISB12 = 0
IO_LED3_ON   			          IO_LED3 = 1
IO_LED3_OFF  			          IO_LED3 = 0
IO_LED3_IN   			          TRISB12 = 1

 
IO_LED1			          	RA3
IO_LED1_OUT  			          TRISA3 = 0
IO_LED1_ON   			          IO_LED1 = 1
IO_LED1_OFF  			          IO_LED1 = 0
IO_LED1_IN   			          TRISA3 = 1

 
IO_LED2			          	RB6
IO_LED2_OUT  			          TRISB6 = 0
IO_LED2_ON   			          IO_LED2 = 1
IO_LED2_OFF  			          IO_LED2 = 0
IO_LED2_IN   			          TRISB6 = 1

 
IO_LED3			          	RC1
IO_LED3_OUT  			          TRISC1 = 0
IO_LED3_ON   			          IO_LED3 = 1
IO_LED3_OFF  			          IO_LED3 = 0
IO_LED3_IN   			          TRISC1 = 1

 
IO_CHARGE_NE			          	RB5
IO_CHARGE_NE_OUT  			          TRISB5 = 0
IO_CHARGE_NE_ON   			          IO_CHARGE_NE = 1
IO_CHARGE_NE_OFF  			          IO_CHARGE_NE = 0
IO_CHARGE_NE_IN   			          TRISB5 = 1

 
IO_LED			          	P03
IO_LED_OUT  			          P03CFG = 0x00;P0TRIS |= BIT3
IO_LED_ON   			          IO_LED = 1
IO_LED_OFF  			          IO_LED = 0
IO_LED_IN   			          P03CFG = 0x00;P0TRIS &= ~BIT3;P0UP |= BIT3

 
IO_V1			          	FP54
IO_V1			          	FP54M

 
IO_V2			          	FP36
IO_V2			          	FP36M

 
IO_V1			          FP25
IO_V1M			          FP25M

 
IO_V2			          FP26
IO_V2M			          FP26M

 
#define IO_V			          FP00
#define IO_VM			          FP00M

 
#define IO_SAT			          	P25
#define IO_SAT_OUT  			          P2M |= BIT5
#define IO_SAT_ON   			          IO_SAT = 1
#define IO_SAT_OFF  			          IO_SAT = 0
#define IO_SAT_IN   			          P2M &= ~BIT5;P2UR |= BIT5

 
#define IO_PIN			          FP23
#define IO_PINM			          FP23M

 
