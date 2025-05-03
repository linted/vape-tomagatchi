#include <stdio.h>

#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>
#include <queue.h>


#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_gpio.h"


#include "tomagatchi.h"


static uint16_t hunger = 0;


void tomagatchi_setup(void) {
    // Setup frame task
    xTaskCreate(drawFrame, "draw frame", configMINIMAL_STACK_SIZE, NULL, FRAME_DRAW_TASK_PRIORITY, NULL);

    // Add a hunger mechanism
    static TimerHandle_t craveTimer = NULL;
    craveTimer = xTimerCreate( "Craving", CRAVE_PERIOD, pdTRUE, NULL, craveFood);
    xTimerStart(craveTimer, 0);
}


void craveFood(  TimerHandle_t xTimerHandle ) {

    if ( hunger <3 ) {
        hunger = 0;
    }  else {
        hunger -= 3;
    }

}

 void consumeFood(uint16_t amount) {
    if (hunger + amount < hunger) {
        hunger = (1<< 16) -1;
    } else {
        hunger += amount;
    }
}



 void drawFrame(void *pvParameters) {

    TickType_t xNextWakeTime;
    const TickType_t xBlockTime = FRAMES_PER_SECOND;

    /* Prevent the compiler warning about the unused parameter. */
    ( void ) pvParameters;

    /* Initialise xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ; ; )
    {
        /* Place this task in the blocked state until it is time to run again.
         * The block time is specified in ticks, pdMS_TO_TICKS() was used to
         * convert a time specified in milliseconds into a time specified in ticks.
         * While in the Blocked state this task will not consume any CPU time. */      
        vTaskDelayUntil( &xNextWakeTime, xBlockTime );

        // TODO: Draw time is not currently being accounted for. If frame rate feels slow, we may need to decrease sleep time

        // TODO: Draw frame

    }



}