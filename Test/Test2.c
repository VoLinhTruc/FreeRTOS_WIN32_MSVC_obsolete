//#include "Test2.h"
//#include <stdio.h>
//#include <conio.h>
//
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "uthash.h"
//
//void in(void* pvParameters)
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
//				if (createFlatCommTask(NULL, 0, sizeof(Flat_Comm_MQ), NULL, 5, sizeof(Flat_Comm_MQ),
//					sendingTask, "Send Task", 1024, tskIDLE_PRIORITY, &sending_fc_task) != 1)
//				{
//					deleteFlatCommTask(sending_fc_task);
//				}
//				else
//				{
//					printf("sending_fc_task CREATED\r\n");
//				}
//			}
//		}
//		if (input == 2)
//		{
//			signed char result = 0;
//			if (receiving_fc_task == NULL)
//			{
//				if ((sending_fc_task != NULL) && (sending_fc_task->qout != NULL))
//				{
//					if (createFlatCommTask(sending_fc_task->qout, 0, sizeof(Flat_Comm_MQ), NULL, 0, sizeof(Flat_Comm_MQ),
//						receivingTask, "Rev Task", 1024, tskIDLE_PRIORITY, &receiving_fc_task) != 1)
//					{
//						deleteFlatCommTask(receiving_fc_task);
//					}
//					else
//					{
//						printf("(sending_fc_task != NULL) && (sending_fc_task->qout != NULL)\r\n");
//					}
//				}
//				else
//				{
//					if (createFlatCommTask(NULL, 0, sizeof(Flat_Comm_MQ), NULL, 0, sizeof(Flat_Comm_MQ),
//						receivingTask, "Rev Task", 1024, tskIDLE_PRIORITY, &receiving_fc_task) != 1)
//					{
//						deleteFlatCommTask(receiving_fc_task);
//					}
//					else
//					{
//						printf("!(sending_fc_task != NULL) && (sending_fc_task->qout != NULL)\r\n");
//					}
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
//				if (receiving_fc_task != NULL)
//				{
//					receiving_fc_task->qin = NULL;
//				}
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
//			char* mess = (char*)pvPortMalloc(20);
//			strcpy(mess, "This is message");
//			char* data = (char*)pvPortMalloc(20);
//			strcpy(data, "This is data");
//			Flat_Comm_MQ* mq = NULL;
//			createMQ(mess, data, &mq);
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
//typedef struct example_user_t {
//	int id;
//	int cookie;
//	UT_hash_handle hh;
//} example_user_t;
//
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
//				Flat_Comm_MQ* mq = NULL;
//				if (xQueueReceive(fc_task->qin, &mq, 100) == pdTRUE)
//				{
//					printf("%s ", mq->mess);
//					printf("%s ", mq->data);
//
//					deleteMQ(mq);
//					//printf("%s %s %d %s\r\n", pcTaskGetName(fc_task->task), (char*)(mq->mess), *(int*)(mq->dat.num_data), (char*)(mq->dat.str_data));
//				}
//			}
//		}
//
//		printf("%s is running\r\n", pcTaskGetName(fc_task->task));
//
//
//		static example_user_t* user, * users = NULL;
//		static int count = 0;
//		if (count < 5)
//		{
//			user = (example_user_t*)malloc(sizeof(example_user_t));
//			if (user == NULL)
//			{
//				break;
//			}
//
//			user->id = count;
//			user->cookie = count * count;
//
//			HASH_ADD_INT(users, id, user);
//
//			count++;
//		}
//		else
//		{
//			int id = 2;
//			example_user_t* result = NULL;
//			HASH_FIND_INT(users, &id, result);
//			printf("%d\r\n", result->cookie);
//			HASH_DEL(users, result);
//
//			id = 0;
//			HASH_FIND_INT(users, &id, result);
//			printf("%d\r\n", result->cookie);
//			HASH_DEL(users, result);
//
//			id = 3;
//			HASH_FIND_INT(users, &id, result);
//			printf("%d\r\n", result->cookie);
//			HASH_DEL(users, result);
//
//			id = 4;
//			HASH_FIND_INT(users, &id, result);
//			printf("%d\r\n", result->cookie);
//			HASH_DEL(users, result);
//
//			id = 1;
//			HASH_FIND_INT(users, &id, result);
//			printf("%d\r\n", result->cookie);
//			HASH_DEL(users, result);
//
//			count = 0;
//		}
//
//		vTaskDelay(237);
//	}
//}