#pragma once
#include <stdlib.h>

typedef void *Pointer;

typedef struct tQueue
{
	Pointer *array;
	size_t capacity;
	size_t size;
	size_t head;
	size_t tail;
} Queue;


/* Создать пустую очередь */
void queueCreate(Queue *pqueue);

/* Уничтожить очередь, освободив выделенную память */
void queueDestroy(Queue *pqueue);

/* Поместить значение value в конец очереди */
void queueEnqueue(Queue *pqueue, Pointer value);

/* Возвращает количество элементов в очереди (0, если очередь пуста) */
size_t queueSize(Queue *pqueue);

/* Исключить и вернуть значение первого элемента очереди.
   Если очередь пуста, возвращает 0 */
Pointer queueDequeue(Queue *pqueue);

/*
 * Возвращает значение первого элемента, не удаляя его из очереди.
 * Если очередь пуста, возвращает 0
 */
Pointer queuePeek(Queue *pqueue);