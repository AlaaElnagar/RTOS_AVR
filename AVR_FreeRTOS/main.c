/*
 * main.c

 *
 *  Created on: Dec 16, 2020
 *      Author: AlaaElnagar
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "avr/io.h"

#define TASK_CREATION					0
#define BINARY_SEAPHORE					1

#define CODE   TASK_CREATION


#if CODE == TASK_CREATION


 /*task1_handler   >>>must be globa */
TaskHandle_t  initTask_handler  ;
TaskHandle_t  buttonTask_handler  ;
TaskHandle_t  ledTask_handler  ;
/*Semaphore handler */
SemaphoreHandle_t binary_semaphore ;

/*lazem tkon paramter to void */

void vLED (void *pvParameter)
{

	for (;;)             //Extended task
	{
			/*handler , max waiting time in the status   blocking time is 100  )
	     * pdTRUE
	     * pdFalse failed
	     * */
		if (xSemaphoreTake(binary_semaphore,100)  != pdTRUE ) {

			PORTC |= (1<<2);

		}

		else {
 /*at starting semaphore is pdfalse and wat  for the next giving */

			PORTC &= ~(1<<2);

		}



	}

	return ;

}

void vButton (void *pvParameter)
{

	for (;;)             //Extended task
	{
      if (((PIND >>0 )&1) == 0 )
		{
			xSemaphoreGive(binary_semaphore);

		}
		vTaskDelay(50);   /*50 TICK WAITING */
	}

	return ;

}


void vInit (void *pvParameter)
{

	for (;;)             //Extended task
	{
		DDRC |= (1<<2);
		DDRD &= ~(1<<0);
		PORTD |= (1<<0);   /*CONNECT T O GND   Pull up  */
vTaskDelete(initTask_handler);   // or Null

	}

	return ;

}


int main(){




/*Priorities are zerro index start from zerro .
 * any thing related to task exist in the heap .
 *
 * xTaskCreate   created in the heap
 * */


	xTaskCreate(vLED,"Task1",configMINIMAL_STACK_SIZE,NULL,1,&ledTask_handler);
	xTaskCreate(vButton,"Task2",configMINIMAL_STACK_SIZE,NULL,2,&buttonTask_handler);
	xTaskCreate(vInit,"Task3",configMINIMAL_STACK_SIZE,NULL,3,&initTask_handler);   // higher priority task

	binary_semaphore = xSemaphoreCreateBinary();

    vTaskStartScheduler();


while(1);

return 0;


}

#elif CODE == BINARY_SEAPHORE





/*
 * main.c

 *
 *  Created on: Dec 16, 2020
 *      Author: AlaaElnagar
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "avr/io.h"





 /*task1_handler   >>>must be globa */
TaskHandle_t  initTask_handler  ;
TaskHandle_t  buttonTask_handler  ;
TaskHandle_t  ledTask_handler  ;
/*Semaphore handler */
SemaphoreHandle_t binary_semaphore ;

/*lazem tkon paramter to void */

void vLED (void *pvParameter)
{

	for (;;)             //Extended task
	{
	    /*handler , max waiting time in the status   blocking time )
	     * pdTRUE
	     * pdFalse failed
	     * */
		if (xSemaphoreTake(binary_semaphore,100)  != pdTRUE ) {

			PORTC |= (1<<2);

		}

		else {
 /*at starting semaphore is pdfalse and wat  for the next giving */

			PORTC &= ~(1<<2);

		}



	}

	return ;

}

void vButton (void *pvParameter)
{

	for (;;)             //Extended task
	{
      if (((PIND >>0 )&1) == 0 )
		{
			xSemaphoreGive(binary_semaphore);

		}
		vTaskDelay(50);   /*50 TICK WAITING */
	}

	return ;

}


void vInit (void *pvParameter)
{

	for (;;)             //Extended task
	{
		DDRC |= (1<<2);
		DDRD &= ~(1<<0);
		PORTD |= (1<<0);   /*CONNECT T O GND */
vTaskDelete(initTask_handler);   // or Null

	}

	return ;

}


int main(){




/*Priorities are zerro index start from zerro .
 * any thing related to task exist in the heap .
 *
 * xTaskCreate   created in the heap
 * */


	xTaskCreate(vLED,"Task1",configMINIMAL_STACK_SIZE,NULL,1,&ledTask_handler);
	xTaskCreate(vButton,"Task2",configMINIMAL_STACK_SIZE,NULL,2,&buttonTask_handler);
	xTaskCreate(vInit,"Task3",configMINIMAL_STACK_SIZE,NULL,3,&initTask_handler);   // higher priority task

	binary_semaphore = xSemaphoreCreateBinary();

    vTaskStartScheduler();


while(1);

return 0;


}




















#endif
