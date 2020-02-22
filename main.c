#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region Structure Definitions

#pragma region Data Structure Definitions

// Node for singly-linked list (usage: data)
typedef struct _slnode
{
	void *data;
	void *next;
} SL_DataNode;

// Node for doubly-linked list (usage: data)
typedef struct _dlnode
{
	void *data;
	void *next;
	void *prev;
} DL_DataNode;

// Link list structure. For singly or doubly linked lists
typedef struct _list
{
	void *HEAD;
	void *TAIL;
} List;

#pragma endregion

/**
 * year - year of the date.
 * month - month from 0 - 11 (january = 0)
 * day - day of the month 0 - 30 (day 1 = 0)
 * */
typedef struct _day
{
	int year;
	int month;
	int day;
} Date;

// TODO - Construct/Store Full name using firstName and lastName
/**
 * _id 				- key to use in the data row
 * first_name - first name of a user (max. characters 50)
 * last_name 	- last name of the user (max. characters 50)
 * full_name	- full name of the user
 * birth_day	- DataType of Date to store Birth Day
 * nic_no			- National Identity Card (NIC) number (Sri Lanka)
 * */
typedef struct _user
{
	int _id;
	char first_name[50];
	char last_name[50];
	char full_name[150];
	Date birth_day;
	double nic_no;
} User;

#pragma endregion

List *UserList;

#pragma region Prototype Functions

void setup();

// Controllers
List *createList();
SL_DataNode *addNodetoList(List *);

// Models
void addUserToList(User, List *);

#pragma endregion

int main()
{
	setup();

	int op = -1;
	while (op != 0)
	{
		printf("\n"
					 "======== MENU ========\n"
					 "  1.Register Student\n"
					 "  0.Exit\n\n"
					 "Enter list no: ");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			break;

		case 1:
			// TODO - create User from user inputs
			break;

		default:
			printf("Unknown Command, Try again!\n");
			break;
		}
	}

	return 0;
}

void setup()
{
	UserList = createList();
	User root = {1,
							 "root",
							 "root",
							 "root",
							 {0, 0, 0},
							 0};

	addUserToList(root, UserList);
}

#pragma region Data Structure Controllers

List *createList()
{
	List *temp = (List *)malloc(sizeof(List));
	if (temp == NULL)
	{
		// printf("Unable to create a `List`!\n");
		return NULL;
	}
	// printf("`List` created successfully.\n");
	temp->HEAD = NULL;
	temp->TAIL = NULL;

	return temp;
}

SL_DataNode *addNodeToList(List *list)
{
	SL_DataNode *temp = (SL_DataNode *)malloc(sizeof(SL_DataNode));
	if (temp == NULL)
	{
		// printf("Unable to create `SL_DataNode`!\n");
		return NULL;
	}

	temp->data = NULL;
	temp->next = NULL;
	SL_DataNode *tail = (SL_DataNode *)list->TAIL;
	if (list->HEAD == NULL)
	{
		list->HEAD = temp;
		tail = temp;
		return temp;
	}

	tail->next = temp;
	tail = temp;
	return temp;
}

#pragma endregion

#pragma region Models

void addUserToList(User user, List *list)
{
	User *temp = (User *)malloc(sizeof(User));
	SL_DataNode *tail = (SL_DataNode *)list->TAIL;
	if (tail == NULL)
	{
		temp->_id = 1;
	}
	else
	{
		User *lastUser = (User *)tail->data;
		temp->_id = lastUser->_id++;
	}

	SL_DataNode *newTail = addNodeToList(list);

	strcpy(temp->full_name, user.full_name);
	strcpy(temp->first_name, user.first_name);
	strcpy(temp->last_name, user.last_name);

	temp->birth_day.year = user.birth_day.year;
	temp->birth_day.month = user.birth_day.month;
	temp->birth_day.day = user.birth_day.day;

	temp->nic_no = user.nic_no;

	newTail->data = temp;
}

#pragma endregion
