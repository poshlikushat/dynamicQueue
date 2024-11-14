#include <assert.h>
#include <stdio.h>
#include "dynamicQueue.h"

void testQueueCreate()
{
	Queue q;
	queueCreate(&q);
	assert(queueSize(&q) == 0); 
	queueDestroy(&q);
}

void testQueueEnqueue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	assert(queueSize(&q) == 1); 
	queueEnqueue(&q, &b);		
	assert(queueSize(&q) == 2); 
	queueDestroy(&q);
}

void testQueueDequeue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);

	assert(*(int *)queueDequeue(&q) == 10); 
	assert(queueSize(&q) == 1);				
	assert(*(int *)queueDequeue(&q) == 20); 
	assert(queueSize(&q) == 0);				
	queueDestroy(&q);
}

void testQueuePeek()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);

	assert(*(int *)queuePeek(&q) == 10);
	assert(*(int *)queuePeek(&q) == 10);
	queueDequeue(&q);					 
	assert(*(int *)queuePeek(&q) == 20); 
	queueDestroy(&q);
}

void testQueueCapacity()
{
	Queue q;
	queueCreate(&q);
	q.capacity = 4;
	int a = 10;
	for (int i = 0; i < 1000; i++)
	{
		queueEnqueue(&q, &a); 
	}
	assert(queueSize(&q) == 1000); 
	queueDestroy(&q);
}

void testQueueEmptyDequeue()
{
	Queue q;
	queueCreate(&q);
	assert(queueDequeue(&q) == NULL); 
	queueDestroy(&q);
}

void testQueueEmptyPeek()
{
	Queue q;
	queueCreate(&q);
	assert(queuePeek(&q) == NULL);
	queueDestroy(&q);
}

void testQueueEnqueueAndDequeue()
{
	Queue q;
	queueCreate(&q);
	int a = 1, b = 2, c = 3;

	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);
	queueEnqueue(&q, &c);

	assert(*(int *)queueDequeue(&q) == 1); 
	assert(*(int *)queueDequeue(&q) == 2); 
	assert(*(int *)queueDequeue(&q) == 3); 
	queueDestroy(&q);
}


void testQueueAfterDequeue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);
	queueDequeue(&q); 

	assert(queueSize(&q) == 1);			 
	assert(*(int *)queuePeek(&q) == 20);
	queueDestroy(&q);
}

int RunAlltests()
{
	testQueueCreate();
	testQueueEnqueue();
	testQueueDequeue();
	testQueuePeek();
	testQueueResize();
	testQueueEmptyDequeue();
	testQueueEmptyPeek();
	testQueueEnqueueAndDequeue();
	testQueueAfterDequeue();

	printf("All tests passed!\n");

	return 0;
}


/*
	Capacity должно быть фиксировано
	и добавить функцию main
*/