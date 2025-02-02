#include "ventilatePlant.h"

/*
환풍 기능(증산 작용 활성화를 위한 환풍 기능)
*/
void *ventilate_plant(void *arg)
{
    int duty = 0;
    int dir = 0;
    int divisor = 0;

    // wiringPiSetupGpio();

    pinMode(MOTOR_PWM_PIN1, PWM_OUTPUT); // GPIO 18 PWM
    pinMode(MOTOR_PWM_PIN2, PWM_OUTPUT); // GPIO 19 PWM
    pwmSetMode(PWM_MODE_MS);

    pwmSetRange(100);
    divisor = 192 / 2;
    duty = 30;

    pwmSetClock(divisor);

    printf("[화분 회전 기능 Start...]\n");
    pwmWrite(MOTOR_PWM_PIN2, duty);
    pwmWrite(MOTOR_PWM_PIN1, 0);
    printf("[화분 회전 기능 End...]\n");
}