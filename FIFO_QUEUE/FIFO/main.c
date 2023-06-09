/*
 * main.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Ahmed Yasser
 */

#include "fifo.h"


void main()
{
	ELEMENT_TYPE uart_buffer [width1];
	FIFO_Buf_t FIFO_UART;
	ELEMENT_TYPE i, temp=0;
	if(FIFO_init(&FIFO_UART, uart_buffer, 5) == FIFO_no_err)
		printf("fifo init --------DONE \n");

	for(i=0; i<7; i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_enqueue(&FIFO_UART, i) == FIFO_no_err)
			printf(" \t fifo enqueue -----DONE \n");
		else
			printf("\t fifo enqueue -------FAILED \n");
	}
	FIFO_print(&FIFO_UART);



		if(FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_err)
			printf("fifo dequeue %x ---------- DONE \n",temp);
		else
			printf("\t fifo dequeue -------FAILED \n");

	FIFO_print(&FIFO_UART);
}
