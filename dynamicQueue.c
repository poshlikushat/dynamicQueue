#include "dynamicQueue.h"

// Create an empty queue
void queueCreate (Queue *pqueue) {
	pqueue->capacity = 4;
	pqueue->size = 0;
	pqueue->head = 0;
	pqueue->tail = 0;
}

// Destroy the queue, free memory
void queueDestroy (Queue *pqueue) {
	free(pqueue->array);
	pqueue->array = NULL;
	pqueue->capacity = 0;
	pqueue->size = 0;
	pqueue->head = 0;
	pqueue->tail = 0;
}

// Put a value at the end of the queue
void queueEnqueue(Queue *pqueue, Pointer value) {

}

// Return number of elements in the queue
size_t queueSize(Queue *pqueue) {

}

//Delete and return a value of the first element, if it's empty return 0
Pointer queueDequeue(Queue *pqueue) {

}

//Rutrn a vakue of the first element not deleting it, if it's empyty return 0
Pointer queuePeak(Queue *pqueue) {

}