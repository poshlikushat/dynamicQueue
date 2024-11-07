#pragma once
#include <stdlib.h>

typedef struct tQueue
{
	Pointer *array;
	size_t capacity;
	size_t size;
	size_t head;
	size_t tail;
} Queue;

typedef void *Pointer;

void queueCreate(Queue *pqueue);

void queueDestroy(Queue *pqueue);

void queueEnqueue(Queue *pqueue, Pointer value);

size_t queueSize(Queue *pqueue);

Pointer queueDequeue(Queue *pqueue);

Pointer queuePeak(Queue *pqueue);