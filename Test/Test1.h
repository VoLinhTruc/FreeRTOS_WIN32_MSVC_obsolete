//#pragma once
//
//#include <stdio.h>
//#include <conio.h>
//
//#include "FreeRTOS.h"
//#include "task.h"
//
//#include "Flat_Comm_Model.h"
//
//typedef struct
//{
//	char mess[10];
//	struct data
//	{
//		int num_data;
//		char str_data[10];
//	}dat;
//}Specific_MQ;
//
//void in(void* pvParameters);
//
//void sendingTask(void* pvParameters);
//void receivingTask(void* pvParameters);
//
//Specific_MQ* createMQ(char* mess, int num, char* str);
//signed char deleteMQ(Specific_MQ* mq);