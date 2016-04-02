/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>
struct node{
	int data;
	struct node *next;
};
int getCount(struct node *head)
{
	int count = 0;
	struct node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
void bubbleSort(struct node *start)
{
	int swapped, i;
	struct node *ptr1;
	struct node *lptr = NULL;

	if (ptr1 == NULL)
		return;
	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void swap(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
struct node *merge(struct node *p, struct node *q)
{
	struct node *temp = NULL;
	struct node *r = NULL;
	r = p;
	temp = p;
	while (temp->next != p)
		temp = temp->next;
	temp->next = q;
	temp = q;
	while (temp->next != q)
		temp = temp->next;
	temp->next = r;
	return (r);
}

int merge_circularlists(struct node **head1, struct node **head2)
{
	int result;
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	*head1 = merge(*head1, *head2);
	bubbleSort(*head1);
	result = getCount(*head1);
	return result;
}
