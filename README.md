<!--
 * @Author: YTL2814454117 2814454117@qq.com
 * @Date: 2022-08-12 15:00:25
 * @LastEditors: YTL2814454117 2814454117@qq.com
 * @LastEditTime: 2022-08-12 22:24:14
 * @FilePath: \proj_8.12\README.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
#PWM原理
CCRx用来改变PWM的输出占空比 
ARR用来控制PWM的频率

##步骤
1）开启 TIM14 和 GPIO 时钟，配置 PF9 选择复用功能 AF9（TIM14）输出。
```C
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);    //使能 GPIOA 时钟
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_TIM14); //  PA7复用为 TIM14
```
2）初始化 TIM14,设置 TIM14 的 ARR 和 PSC 等参数。
3）设置 TIM14_CH1 的 PWM 模式，使能 TIM14 的 CH1 输出。
```C
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;             // PWM 调制模式 1
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;      //输出极性低
    TIM_OC1Init(TIM14, &TIM_OCInitStructure);                     //初始化外设 TIM14OC1
```
4）使能 TIM14。
5）修改 TIM14_CCR1 来控制占空比。




学习了pwm中ccrx和aar的一些性质，以及pwm输出的原理以及整个过程的函数调用，先使能时钟，然后将LEDio口复用为TIM14，初始化TIM14，设置相关参数，设置通道1的PWM模式并使能，最后修改TIM14_CCR1。遇到的问题就是没有把正确的led灯匹配到TIM14上，导致一开始灯一直常亮，代码修修改改也没解决，仔细看手册后发现问题就很快解决了。还是得认真看手册，磨刀不误砍柴工。复习了一下定时器的函数调用以及整个流程的实现，在李享学长的帮助下将keil环境配置到了vscode中，并且完善了工程模板，便于后续使用。现在感觉学了的东西就算做了作业印象也不深，还得花不少时间复习才能记住一部分内容。每天都是新挑战的感觉挺好的。