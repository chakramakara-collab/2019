#include "lcd_16x2.h"
#include "pwm_motor.h"
#include "stdio.h"
#include "speed_control.h"
#include "uart_node.h"
#include "uart_camera.h"
#include "localization.h"
#include "mekanisme_penendang.h"

/* Luas Lapangan :
 * Real : 7,2 x 4,8
 * Virtual : 200 x 133
 * */

/*
 * Variables
 */
extern uint8_t ballYCoor;
extern float Y_pos, Y_poscmps;
extern float X_pos, X_poscmps;
extern float theta;
extern float sudut;
int counterSrf = 0;
int x, y;
int a, b;

int main(void)
{
	SystemInit();

	lcd_init();
	TM_DELAY_Init();
	init_lcdTimer();
	lcd_clear();
	init_mode();
	init_proximity();
	init_speed_control();
	init_node();
	init_camera();
	init_penendang();
	init_handle();
//	init_srf();
	handleOff();
//	if(GPIO_ReadInputDataBit(GPIOE,GPIO_PIN_8) == 1){
//		while(1)
//		{
//			penalty();
//		}
//	}
//	else{
//		maju(150);
//		Delayms(3000);
//	}

	Delayms(3000);


	fungsiautosudut();
//	kickBall();

//	maju kickoff 2 detik
//	maju1(450);
//	Delayms(1800);
//	stop();

//	maju kickoff 3 detik
//	maju1(300);
//	Delayms(2300);

//	if(GPIO_ReadInputDataBit(GPIOC,GPIO_PIN_7) == 1)
//	{
//		Delayms(3000);
//		maju(120);
//		Delayms(4000);
//	}
//	else {
//		Delayms(2000);
//	}
//	stop();
	int f = 0;
    while(1)
    {
//    	stop();
//    	if(Y_pos < 2000.0)
//    		maju(30);
//    	else
//    		stop();
//    	stop();


//    	if(compassHeading >= 179 && compassHeading <= 181)
//    	{
//    		f = 1;
//    	}
//    	if(f == 1)
//    	{
//    		mundur(PID(Y_poscmps, -2000.0, 150));
//			kiri(PID(X_poscmps, 1000, 150));
//    	}
//    	else
//		{
//			rotateAntiClockWise(50);
//		}


//    	maju(PID(Y_poscmps, -2000.0, 50));

//    	maju(150);

    	x = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
//    	y = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3);
//    	a = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4);
//    	b = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5);
    	startMain(OFF,OFF);

//    	maju(100);
//    	handleRotateIn();
//    	if(gotoHeadZero())
//    	{
//    		stop();
//    	}
//    	startMain(ON,OFF);
    }
}
