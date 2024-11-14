#include "dynamicQueue.h"

// Create an empty queue
void queueCreate (Queue *pqueue) {
	pqueue->capacity = 1000;
	pqueue->size = 0;
	pqueue->head = 0;
	pqueue->tail = 0;
	pqueue->array = malloc(sizeof(Pointer) * pqueue->capacity);
}

// Destroy the queue, free memory
void queueDestroy (Queue *pqueue) {
	if(pqueue->array != NULL) {
		free(pqueue->array);
	}
	
	pqueue->array = NULL;
	pqueue->capacity = 0;
	pqueue->size = 0;
	pqueue->head = 0;
	pqueue->tail = 0;
}

// Put a value at the end of the queue
void queueEnqueue(Queue *pqueue, Pointer value) {
	if (pqueue->size == pqueue->capacity) {
		size_t newCapacity = pqueue->capacity * 2;
		Pointer *newArray = realloc(pqueue->array, newCapacity * sizeof(Pointer));

		if (newArray == NULL) {
			abort();
		}

		pqueue->capacity = newCapacity;
		pqueue->array = newArray;
	}

	pqueue->array[pqueue->tail] = value;

	pqueue->tail = (pqueue->tail + 1) % pqueue->capacity;

	pqueue->size++;
}

// Return a number of elements in the queue
size_t queueSize(Queue *pqueue) {
	return pqueue->size;
}

//Delete and return a value of the first element, if it's empty return NULL
Pointer queueDequeue(Queue *pqueue) {
	if (pqueue->size == 0)
		return NULL;

	Pointer headValue = pqueue->array[pqueue->head];

	pqueue->head = (pqueue->head + 1) % pqueue->capacity;

	pqueue->size--;
	return headValue;
}

//Rutrn a value of the first element not deleting it, if it's empyty return NULL
Pointer queuePeek(Queue *pqueue) {
	return (pqueue->size == 0) ? NULL : pqueue->array[pqueue->head];
}