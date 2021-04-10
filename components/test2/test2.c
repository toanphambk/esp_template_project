#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"


#define BLINK_GPIO 02
#define APP_CPU 1

static TimerHandle_t t1 = NULL;

void xTimerCallback(TimerHandle_t Timer)
{
    printf("timer expired\n");
}

void start2()
{
    t1 = xTimerCreate("test", 1000 / portTICK_PERIOD_MS, pdTRUE, (void *)1, xTimerCallback);
    if (t1 != NULL)
    {
        printf("created timer\n");
    }

    if (xTimerStart(t1, portMAX_DELAY) == pdPASS)
    {
        printf("Stared timer\n");
    }
}