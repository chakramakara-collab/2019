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
int counterSrf = 0;
int x, y;

int main(void)
{
	SystemInit();

	lcd_init();
	TM_DELAY_Init();
	init_lcdTimer();
	lcd_clear();
//	init_mode();
	init_proximity();
	init_speed_control();
	init_node();
	init_camera();
	init_handle();
	init_penendang();
//	init_srf();
	Delayms(2000);
//	if(GPIO_ReadInputDataBit(GPIOE,GPIO_PIN_8) == 1){
////		while(1)
////		{
////			penalty();
////		}
//	}
//	else{
//		maju(150);
//		Delayms(3000);
//	}
	kickBall();

    while(1)
    {


//    	kiri(100);
//		Delayms(1600);
//    	kanan(100);
//		Delayms(1600);
//    	stop();
    	//TES KICKER

//    	if(Y_pos != 1000)
//    	{
//    		maju(100);
//    	}
//    	else
//    	{
//    		stop();
//    	}

    	// wajib ga boleh dikomen, bagian dari sistem:
//    	maju(30);
//    	x = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
//    	y = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14);
//    	handleRotateIn();
//    	kickOff1();
//    	tesRotateMap();
//    	tesMapping();
//    	getProxy();
//    	ballGet();
//    	getBall();
//    	motorSpeed(30,30,30,30);
//    	gotoXY(10,0);
//    	tesKicker();
//    	tesHandle();
//    	tesMotor(30);
//    	kiri(30);
//    	counterSrf++;
//    	if(counterSrf == 1000){
//    		tesSRF();
//    		counterSrf =0;
//    	}
//    	rotateAntiClockWise(15);
//    	gotoxyCoach();
//    	handleOff();
//    	tesSRF();
//    	keeper();
//    	startMain(OFF,OFF);

//    	getBallNew();
//    	outBall1();
//    	outBall2();
//    	Delayms(100);
//    	penalty();
//    	kickBall();
    }
}
