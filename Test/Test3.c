//#include "Test3.h"
//#include <stdio.h>
//#include <conio.h>
//
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "uthash.h"
//
//#include "Flat_Comm_Model.h"
//typedef struct {
//	char app_name[32];
//	Flat_Comm* flat_comm_app;
//	UT_hash_handle hh;
//} Flat_Comm_App_Table;
//
//void in(void* pvParameters)
//{
//	(void*)pvParameters;
//	static Flat_Comm_App_Table* app, * app_list= NULL;
//	static int count = 0;
//
//	while (1)
//	{
//
//		//if (count < 5)
//		//{
//		//	user = (example_user_t*)malloc(sizeof(example_user_t));
//		//	if (user == NULL)
//		//	{
//				//continue;
//		//	}
//		//
//		//	user->id = count;
//		//	user->cookie = count * count;
//		//
//		//	HASH_ADD_INT(users, id, user);
//		//
//		//	count++;
//		//}
//		//else
//		//{
//		//	int id = 2;
//		//	example_user_t* result = NULL;
//		//	HASH_FIND_INT(users, &id, result);
//		//	printf("%d\r\n", result->cookie);
//		//	HASH_DEL(users, result);
//		//
//		//	id = 0;
//		//	HASH_FIND_INT(users, &id, result);
//		//	printf("%d\r\n", result->cookie);
//		//	HASH_DEL(users, result);
//		//
//		//	id = 3;
//		//	HASH_FIND_INT(users, &id, result);
//		//	printf("%d\r\n", result->cookie);
//		//	HASH_DEL(users, result);
//		//
//		//	id = 4;
//		//	HASH_FIND_INT(users, &id, result);
//		//	printf("%d\r\n", result->cookie);
//		//	HASH_DEL(users, result);
//		//
//		//	id = 1;
//		//	HASH_FIND_INT(users, &id, result);
//		//	printf("%d\r\n", result->cookie);
//		//	HASH_DEL(users, result);
//		//
//		//	count = 0;
//		//}
//
//		if (count < 4)
//		{
//			app = (Flat_Comm_App_Table*)malloc(sizeof(Flat_Comm_App_Table));
//			if (app == NULL)
//			{
//				continue;
//			}
//
//			sprintf(app->app_name, "FC_APP: %d", count);
//			Flat_Comm* temp = (Flat_Comm*)malloc(sizeof(Flat_Comm));
//			temp->qin_owner = count/2;
//			temp->qout_owner = count%2;
//			app->flat_comm_app = temp;
//
//			HASH_ADD_STR(app_list, app_name, app);
//
//			count++;
//		}
//		else
//		{
//			char key[32];
//			sprintf(key, "FC_APP: %d", 0);
//			Flat_Comm_App_Table* result = NULL;
//			HASH_FIND_STR(app_list, key, result);
//			printf("%d %d\r\n", result->flat_comm_app->qin_owner, result->flat_comm_app->qout_owner);
//			HASH_DEL(app_list, result);
//			free(result->flat_comm_app);
//			free(result);
//
//			sprintf(key, "FC_APP: %d", 3);
//			HASH_FIND_STR(app_list, key, result);
//			printf("%d %d\r\n", result->flat_comm_app->qin_owner, result->flat_comm_app->qout_owner);
//			HASH_DEL(app_list, result);
//			free(result->flat_comm_app);
//			free(result);
//
//			sprintf(key, "FC_APP: %d", 1);
//			HASH_FIND_STR(app_list, key, result);
//			printf("%d %d\r\n", result->flat_comm_app->qin_owner, result->flat_comm_app->qout_owner);
//			HASH_DEL(app_list, result);
//			free(result->flat_comm_app);
//			free(result);
//
//			sprintf(key, "FC_APP: %d", 2);
//			HASH_FIND_STR(app_list, key, result);
//			printf("%d %d\r\n", result->flat_comm_app->qin_owner, result->flat_comm_app->qout_owner);
//			HASH_DEL(app_list, result);
//			free(result->flat_comm_app);
//			free(result);
//
//			count = 0;
//		}
//
//		printf("IN is running\r\n");
//
//		vTaskDelay(1);
//	}
//
//}