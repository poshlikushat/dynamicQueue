#include <assert.h>
#include <stdio.h>
#include "dynamicQueue.h"

void testQueueCreateAndSize()
{
	Queue q;
	queueCreate(&q);
	assert(queueSize(&q) == 0); // Очередь должна быть пустой
	queueDestroy(&q);
}

void testQueueEnqueue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);		// Добавляем элемент
	assert(queueSize(&q) == 1); // Размер очереди должен быть 1
	queueEnqueue(&q, &b);		// Добавляем ещё один элемент
	assert(queueSize(&q) == 2); // Размер очереди должен быть 2
	queueDestroy(&q);
}

void testQueueDequeue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);

	// Проверяем dequeue
	assert(*(int *)queueDequeue(&q) == 10); // Должен вернуть 10
	assert(queueSize(&q) == 1);				// Размер очереди должен быть 1
	assert(*(int *)queueDequeue(&q) == 20); // Должен вернуть 20
	assert(queueSize(&q) == 0);				// Очередь должна быть пустой
	queueDestroy(&q);
}

void testQueuePeek()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);

	assert(*(int *)queuePeek(&q) == 10); // Должен вернуть 10, не удаляя элемент
	queueDequeue(&q);					 // Удаляем 10
	assert(*(int *)queuePeek(&q) == 20); // Должен вернуть 20, так как это следующий элемент
	queueDestroy(&q);
}

void testQueueResize()
{
	Queue q;
	queueCreate(&q);
	int a = 10;
	for (int i = 0; i < 1000; i++)
	{
		queueEnqueue(&q, &a); // Добавляем 1000 одинаковых элементов
	}
	assert(queueSize(&q) == 1000); // Размер очереди должен быть 1000
	queueDestroy(&q);
}

void testQueueEmptyDequeue()
{
	Queue q;
	queueCreate(&q);
	assert(queueDequeue(&q) == NULL); // При попытке удалить из пустой очереди должно вернуть NULL
	queueDestroy(&q);
}

void testQueueEmptyPeek()
{
	Queue q;
	queueCreate(&q);
	assert(queuePeek(&q) == NULL); // При попытке посмотреть первый элемент пустой очереди должно вернуть NULL
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

	assert(*(int *)queueDequeue(&q) == 1); // Первый элемент должен быть 1
	assert(*(int *)queueDequeue(&q) == 2); // Второй элемент должен быть 2
	assert(*(int *)queueDequeue(&q) == 3); // Третий элемент должен быть 3
	queueDestroy(&q);
}

void testQueueOverflow()
{
	Queue q;
	queueCreate(&q);
	int a = 10;

	// Заполняем очередь до максимума
	for (int i = 0; i < 100; i++)
	{
		queueEnqueue(&q, &a);
	}

	// Теперь очередь должна быть полна
	assert(queueSize(&q) == 100); // Размер должен быть 100
	queueDestroy(&q);
}

void testQueueAfterDequeue()
{
	Queue q;
	queueCreate(&q);
	int a = 10, b = 20;
	queueEnqueue(&q, &a);
	queueEnqueue(&q, &b);
	queueDequeue(&q); // Удаляем первый элемент (10)

	assert(queueSize(&q) == 1);			 // Размер должен быть 1
	assert(*(int *)queuePeek(&q) == 20); // Следующий элемент должен быть 20
	queueDestroy(&q);
}

int runAllTests()
{
	// Запускаем все тесты
	testQueueCreateAndSize();
	testQueueEnqueue();
	testQueueDequeue();
	testQueuePeek();
	testQueueResize();
	testQueueEmptyDequeue();
	testQueueEmptyPeek();
	testQueueEnqueueAndDequeue();
	testQueueOverflow();
	testQueueAfterDequeue();

	printf("All tests passed!\n");

	return 0;
}