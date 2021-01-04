//#include "Test1.h"
//#include <stdio.h>
//#include <conio.h>
//
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//
//void in(void *pvParameters)
//{
//	(void*)pvParameters;
//	Flat_Comm* sending_fc_task = NULL;
//	Flat_Comm* receiving_fc_task = NULL;
//
//	while (1)
//	{
//		int input;
//		scanf("%d", &input);
//		if (input == 1)
//		{
//			if (sending_fc_task == NULL)
//			{
//				sending_fc_task = createFlatCommTask(NULL, 0, sizeof(Flat_Comm_MQ), NULL, 5, sizeof(Flat_Comm_MQ),
//					sendingTask, "Send Task", 1024, tskIDLE_PRIORITY);
//			}
//		}
//		if (input == 2)
//		{
//			if (receiving_fc_task == NULL)
//			{
//				if ((sending_fc_task != NULL) && (sending_fc_task->qout != NULL))
//				{
//					receiving_fc_task = createFlatCommTask(sending_fc_task->qout, 0, sizeof(Flat_Comm_MQ), NULL, 0, sizeof(Flat_Comm_MQ),
//						receivingTask, "Rev Task", 1024, tskIDLE_PRIORITY);
//					printf("(sending_fc_task != NULL) && (sending_fc_task->qout != NULL)\r\n");
//				}
//				else
//				{
//					receiving_fc_task = createFlatCommTask(NULL, 0, sizeof(Flat_Comm_MQ), NULL, 0, sizeof(Flat_Comm_MQ),
//						receivingTask, "Rev Task", 1024, tskIDLE_PRIORITY);
//					printf("!(sending_fc_task != NULL) && (sending_fc_task->qout != NULL)\r\n");
//				}
//			}
//			else
//			{
//				if (receiving_fc_task->qin == NULL)
//				{
//					receiving_fc_task->qin = sending_fc_task->qout;
//					printf("!(receiving_fc_task == NULL)\r\n");
//				}
//			}
//		}
//		if (input == 3)
//		{
//			if (sending_fc_task != NULL)
//			{
//				receiving_fc_task->qin = NULL;
//				deleteFlatCommTask(sending_fc_task);
//				sending_fc_task = NULL;
//			}
//		}
//		if (input == 4)
//		{
//			if (receiving_fc_task != NULL)
//			{
//				deleteFlatCommTask(receiving_fc_task);
//				receiving_fc_task = NULL;
//			}
//		}
//		printf("IN is running %d \r\n", input);
//		vTaskDelay(1);
//	}
//}
//
//void sendingTask(void* pvParameters)
//{
//	Flat_Comm* fc_task = (Flat_Comm*)pvParameters;
//
//	while (1)
//	{
//		if (fc_task->qout != NULL)
//		{
//			static int count = 0;
//
//			Specific_MQ* mq = createMQ("MESS", count++, "BlaBla");
//			//mq->mess = (char*)pvPortMalloc(20);
//			//(char*)(mq->mess) = "This is mess";
//			//mq->data = (int*)pvPortMalloc(sizeof(int));
//			//*(int*)(mq->data) = count++;
//
//			xQueueSend(fc_task->qout, &mq, 1000);
//		}
//
//		printf("%s is running\r\n", pcTaskGetName(fc_task->task));
//
//		vTaskDelay(1020);
//	}
//}
//
//void receivingTask(void* pvParameters)
//{
//	Flat_Comm* fc_task = (Flat_Comm*)pvParameters;
//
//	while (1)
//	{
//		//static int count = 0;
//
//		//Flat_Comm_MQ* mq = (Flat_Comm_MQ*)pvPortMalloc(sizeof(Flat_Comm_MQ));
//		//mq->mess = (int*)pvPortMalloc(sizeof(int));
//		//*(int*)(mq->mess) = 1;
//		//mq->data = (int*)pvPortMalloc(sizeof(int));
//		//*(int*)(mq->data) = count++;
//		//xQueueSend(fc_task->qout, mq, 1000);
//
//		if (fc_task->qin != NULL)
//		{
//
//			if (uxQueueMessagesWaiting(fc_task->qin) > 0)
//			{
//				Specific_MQ* mq = NULL;
//				if (xQueueReceive(fc_task->qin, &mq, 100) == pdTRUE)
//				{
//					printf("%s ", mq->mess);
//					printf("%d ", mq->dat.num_data);
//					printf("%s ", mq->dat.str_data);
//
//					deleteMQ(mq);
//					//printf("%s %s %d %s\r\n", pcTaskGetName(fc_task->task), (char*)(mq->mess), *(int*)(mq->dat.num_data), (char*)(mq->dat.str_data));
//				}
//			}
//		}
//
//		printf("%s is running\r\n", pcTaskGetName(fc_task->task));
//
//		vTaskDelay(513);
//	}
//}
//
//Specific_MQ* createMQ(char* mess, int num, char* str)
//{
//	Specific_MQ* mq = (Specific_MQ*)pvPortMalloc(sizeof(Specific_MQ));
//	strcpy(mq->mess, mess);
//	mq->dat.num_data = num;
//	strcpy(mq->dat.str_data, str);
//	return mq;
//}
//
//signed char deleteMQ(Specific_MQ* mq)
//{
//	if (mq != NULL)
//	{
//		vPortFree(mq);
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}