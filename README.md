#通用计时器
组成：
1. 自动装载计数器TIMx_CNT
2. 16位可编程预分频器TIMxS_PSC(计时器时钟分频系数为1~65535之间任一数值)
3. 4个独立通道TIMx_x_CH1~4

作用：A．输入捕获
     B．输出比较
     C．PWM 生成(边缘或中间对齐模式) ，注意：TIM9~TIM14 不支持中间对齐模式
     D．单脉冲模式输出

4. 可使用外部信号（TIMx_ETR）控制定时器和定时器互联的同步电路

5.如下事情发生时产生中断：
A．更新：计数器向上溢出/向下溢出，计数器初始化(通过软件或者内部/外部触发) 
B．触发事件(计数器启动、停止、初始化或者由内部/外部触发计数) 
C．输入捕获
D．输出比较
E．支持针对定位的增量(正交)编码器和霍尔传感器电路（TIM9~TIM14 不支持）
F．触发输入作为外部时钟或者按周期的电流管理（TIM9~TIM14 不支持）

##定时器时钟来源
1）内部时钟（CK_INT）
2）外部时钟模式 1：外部输入脚（TIx）
3）外部时钟模式 2：外部触发输入（ETR），仅适用于 TIM2、TIM3、TIM4
4）内部触发输入（ITRx）：使用 A 定时器作为 B 定时器的预分频器（A 为 B 提供时钟）

1）内部时钟（CK_INT）
2）外部时钟模式 1：外部输入脚（TIx）
3）外部时钟模式 2：外部触发输入（ETR），仅适用于 TIM2、TIM3、TIM4
4）内部触发输入（ITRx）：使用 A 定时器作为 B 定时器的预分频器（A 为 B 提供时钟）

###定时器配置步骤
1. 时钟使能
2. 初始化定时器参数,设置自动重装值，分频系数，计数方式等
3. 设置 TIM3_DIER 允许（**使能**）更新中断
4. TIM3 中断优先级设置（**misc.c**）
     1. 系统运行开始的时候设置中断分组。确定组号，也就是确定抢占优先级和响应优先级
     的分配位数。调用函数为 NVIC_PriorityGroupConfig();
     2. 设置所用到的中断的中断优先级别。对每个中断调用函数为 NVIC_Init();
5. 允许 TIM3 工作，也就是使能 TIM3
6. 编写中断服务函数(**中断产生后自动执行**)
      