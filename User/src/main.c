#include "main.h"
#include "pwm.h"
#include "misc.h"
#include "delay.h"

int main()
{
	SystemInit(); //系统初始化
	unsigned short led0pwmval = 0;
	unsigned char dir = 1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置系统中断优先级分组 2
	TIM14_PWM_Init(500 - 1, 84 - 1);				//定时器时钟为 84M，分频系数为 84，所以计数频率
													//为 84M/84=1Mhz,重装载值 500，所以 PWM 频率为 1M/500=2Khz.

	while (1)
	{
		delay_ms(10);
		if (dir)
			led0pwmval++; // dir==1 led0pwmval 递增
		else
			led0pwmval--; // dir==0 led0pwmval 递减
		if (led0pwmval > 200)
			dir = 0; // led0pwmval 到达 300 后，方向为递减
		if (led0pwmval == 0)
			dir = 1;						// led0pwmval 递减到 0 后，方向改为递增
		TIM_SetCompare1(TIM14, led0pwmval); //修改比较值，修改占空比
	}
}
