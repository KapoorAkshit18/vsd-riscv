#include <ch32v00x.h>
#include <debug.h>

/* Initialize Timer 1 for PWM on PD2 */
void TIM1_PWMOut_Init(u16 arr, u16 psc, u16 ccp)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    TIM_OCInitTypeDef TIM_OCInitStructure = {0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);

    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Disable);
    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_Cmd(TIM1, ENABLE);
}

/* Configure PD3 as input for PIR sensor */
void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Input pull-up
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

int main(void)
{
    uint8_t pir_status;

    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    /* Initialize PWM for servo at center position */
    TIM1_PWMOut_Init(199, 2399, 15);

    while (1)
    {
        /* Read PIR sensor status */
        pir_status = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3);

        if (pir_status == 1) // Motion detected (active LOW or depending on wiring)
        {
            // Sweep servo left to right when motion detected
            for(int pulse = 10; pulse <= 20; pulse++) {
                TIM1_PWMOut_Init(199, 2399, pulse);
                Delay_Ms(20);
            }
            for(int pulse = 20; pulse >= 10; pulse--) {
                TIM1_PWMOut_Init(199, 2399, pulse);
                Delay_Ms(20);
            }
        }
        else
        {
            // Keep servo at center when no motion
            TIM1_PWMOut_Init(199, 2399, 15);
        }
    }
}
