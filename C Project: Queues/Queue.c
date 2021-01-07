#include "Queue.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in Queue.h.
 *
 * ****/

//mallocs a new queue
Queue newQueue()
{
	Queue q = (QueueImp*)malloc(sizeof(QueueImp));

	q->head = NULL;
	q->foot = NULL;

	return q;
}

//frees all elements of the queue, then the queue itself
void freeQueue(Queue q)
{
	Element *e;

	while(isEmpty(q) == 0)
	{
		dequeue(q, e);
	}

	free(q);
}

//creates a node based off a given value
NodeLL *allocateNode(Element value)
{
	NodeLL* new;
	new = (NodeLL*)malloc(sizeof(NodeLL));

	if(new == NULL)
	{
		printf("Error: unable to allocate Node\n");
	}	

	new->element = value;
	new->next = NULL;
	return new;
}

//allocates a node, places the element value into the node, and inserts into the back of the queue
void enqueue(Queue q, Element element)
{
	NodeLL* new = allocateNode(element);

	if(q-> foot == NULL)
	{
		q->head = new;
		q->foot = new;
	}

	else
	{
		q->foot->next = new;
		q->foot = q->foot->next;
	}

}

//removes item at front of the queue and frees it
int dequeue(Queue q, Element *e)
{
	if(q->foot == NULL)
	{
		printf("Error: Queue is empty\n");
		e->shopperID = 0;
		e->numberOfItems = 0;
		return 0;
	}

	else if(q->head == q->foot)
	{
		e = &q->head->element;
		q->head = NULL;
		q->foot = NULL;
		return 1;
	}

	else
	{
		NodeLL* p = q->head;
		q->head = q->head->next;
		e = &p->element;
		free(p);
		return 1;
	}
}

//checks whether or not the queue is empty
int isEmpty(Queue q)
{
	if(q->head == NULL && q->foot == NULL)
	{
		return 1;
	}

	return 0;
}

//returns the element at the fron of the array without removing it
int frontElement(Queue q, Element *e)
{
	if(q->head == NULL)
	{
		printf("Error: queue is empty\n");
		return 0;
	}

	else
	{
		NodeLL *p = q->head;
		e = &p->element;
		return 1;
	}
}
