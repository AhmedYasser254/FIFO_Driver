/**********************
 * file name: fifo.h
 *
 *  Created on: Apr 29, 2023
 *
 *  Author: Ahmed Yasser
 ***********************/

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"


//User Configuration
/*the first thing select the element width or element type
 * (uint8_t, uint26_t, uint32_t,.....)
 */
#define ELEMENT_TYPE uint8_t


//Create buffer
#define width1 5




//FIFO data types
typedef struct{
	unsigned int length;
	unsigned int count;
	ELEMENT_TYPE* head;		//Pointer from the type of the element width
	ELEMENT_TYPE* tail;	 	//Pointer from the type of the element width
	ELEMENT_TYPE* base;	 	//Pointer from the type of the element width
}FIFO_Buf_t;

typedef enum{
	FIFO_no_err,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_Buf_t_status;



//APIs
FIFO_Buf_t_status FIFO_init	(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, uint32_t length);
FIFO_Buf_t_status FIFO_enqueue(FIFO_Buf_t* fifo, ELEMENT_TYPE item);
FIFO_Buf_t_status FIFO_dequeue(FIFO_Buf_t* fifo, ELEMENT_TYPE* item);
FIFO_Buf_t_status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
