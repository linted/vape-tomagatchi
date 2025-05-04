#pragma once
#ifndef TOMAGATCHI_H
#define TOMAGATCHI_H

#define CRAVE_PERIOD pdMS_TO_TICKS( 2000UL )
#define FRAMES_PER_SECOND pdMS_TO_TICKS( 33UL )
#define BUTTON_PRESS_DELAY pdMS_TO_TICKS( 500UL )

#define FRAME_DRAW_TASK_PRIORITY (tskIDLE_PRIORITY  + 1)

#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>
#include <queue.h>

int tomagatchi_setup(void);
void craveFood(  TimerHandle_t xTimerHandle );
void consumeFood(uint16_t amount);
void drawFrame(void *pvParameters);


#endif