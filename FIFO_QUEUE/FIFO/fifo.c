/*
 * fifo.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Ahmed Yasser
 */
#include "fifo.h"

FIFO_Buf_t_status FIFO_init	(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, uint32_t length)
{
	if(buf == NULL)
		return FIFO_NULL;
	fifo->base = buf;
	fifo->head = buf;
	fifo->length = length;
	fifo->count = 0;
	fifo->tail = buf;
	return FIFO_no_err;
}
FIFO_Buf_t_status FIFO_enqueue(FIFO_Buf_t* fifo, ELEMENT_TYPE item)
{
	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_NULL;
	if(FIFO_IS_FULL(fifo) == FIFO_full)
		return FIFO_full;
	*(fifo->head) = item;
	// Circular FIFO
	if( fifo->head == (fifo->base) + (fifo->length * sizeof(ELEMENT_TYPE)))
		fifo->head = fifo->base;
	else
		fifo->head ++;

	fifo->count ++;

	return FIFO_no_err;


}


FIFO_Buf_t_status FIFO_dequeue(FIFO_Buf_t* fifo, ELEMENT_TYPE* item)
{

	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_NULL;

	//check FIFO is empty
	if(fifo->count == 0)
		return FIFO_empty;
	*item = (*fifo->tail);
	fifo->count --;
	if( fifo->tail == (fifo->tail) + (fifo->length * sizeof(ELEMENT_TYPE)))
		fifo->tail = fifo->base;
	else
		fifo->tail ++;
	return FIFO_no_err;
}


FIFO_Buf_t_status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail )
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_full;
	return FIFO_no_err;
}



void FIFO_print(FIFO_Buf_t* fifo)
{
	ELEMENT_TYPE* temp;
	int i;
	if(fifo->count == 0)
		printf("fifo is empty \n");
	else
	{
		temp = fifo->tail ;
		printf("\n =======fifo_printf========\n");
		for(i=0; i<fifo->count; i++)
		{
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("====================\n");
}
}


