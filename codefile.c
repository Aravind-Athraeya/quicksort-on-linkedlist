// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include<conio.h>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include <unordered_set>

using namespace std;




typedef struct ListNode
{
	int value;
	struct ListNode *header;
	struct ListNode *Next;
	struct ListNode *tailer;
}node;




void push(node** head_ref, int new_data)
{
	/* allocate node */
	node* new_node = new node();

	/* put in the data  */
	new_node->value = new_data;

	/* link the old list off the new node */
	new_node->Next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

int findListLength(ListNode *list) //returns length of list
{
	int counter = 0;
	for (; list != NULL; list = list->Next)
	{
		++counter;
	}
	return counter;
}






node* GetPivot(node* head) {



	int list_length = findListLength(head);
	int pivot_position = rand() % list_length;

	for (int count = 0; count < pivot_position; count++)
	{
		head = head->Next;
	}
	return head;





}


node *getTail(node *cur)
{
	while (cur != NULL && cur->Next != NULL)
		cur = cur->Next;
	return cur;
}


node * MergeAndReturn(node* left_list, node * pivot, node * right_list)
{
	pivot->Next = right_list;

	if (left_list == NULL)	return pivot;

	ListNode * left_tail = getTail(left_list);
	left_tail->Next = pivot;

	return left_list;
}



node* QuickSort(node* head) {


	node *leftSub = NULL;
	node *rightSub = NULL;


	if ((head == NULL) || (head->Next == NULL))
	{
		return head;
	}


	node* pivot = GetPivot(head);





	for (node * current_node = head; current_node != NULL;)
	{
	
		node * next_node = current_node->Next;

		if (current_node != pivot)
		{
			if (current_node->value <= pivot->value)
			{
				current_node->Next = leftSub;
				leftSub = current_node;
			}
			else
			{
				current_node->Next = rightSub;
				rightSub = current_node;
			}
		}
		current_node = next_node;
	}

	return MergeAndReturn(QuickSort(leftSub), pivot, QuickSort(rightSub));








	//	return MergedSortedList;
}


int main()
{
	node *lstOne = NULL;

	push(&lstOne, 2);
	push(&lstOne, 3);
	push(&lstOne, 21);
	push(&lstOne, 33);
	push(&lstOne, 42);
	push(&lstOne, 53);
	push(&lstOne, 62);
	push(&lstOne, 3);

  node* find = 	QuickSort(lstOne);

	return 0;
}
