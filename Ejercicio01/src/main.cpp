#include "data_structure/MyStackLaure.h"
#include "data_structure/MyQueueLaure.h"
#include "data_structure/MyListLaure.h"

using namespace std;
using namespace MyStackLaure;
using namespace MyQueueLaure;
using namespace MyListLaure;

static const int stackMinRandomNumbers = 5;
static const int stackMaxRandomNumbers = 10;

static const int QueueMinRandomNumbers = 5;
static const int QueueMaxRandomNumbers = 10;

static const int floatDecimalPrecision = 100;

float GetHighest(MyList<float>& list, float range);

int main()
{
	srand(time(0));

	MyStack<float>* stack = new MyStack<float>();
	int stackSize = rand() % (stackMaxRandomNumbers - stackMinRandomNumbers - 1) + stackMinRandomNumbers + 1;

	cout << "Stack values: " << endl << endl;
	for (int i = 0; i < stackSize; i++)
	{
		int randomInt = rand();
		float randomDecimal = static_cast<float>(rand() % floatDecimalPrecision) / floatDecimalPrecision;
		float randomFloat = randomInt + randomDecimal;

		stack->push(randomFloat);
		cout << randomFloat << endl;
	}

	cout << endl << endl;

	MyQueue<float>* queue = new MyQueue<float>();
	int queueSize = rand() % (QueueMaxRandomNumbers - QueueMinRandomNumbers - 1) + QueueMinRandomNumbers + 1;

	cout << "Queue values: " << endl << endl;
	for (int i = 0; i < queueSize; i++)
	{
		int randomInt = rand();
		float randomDecimal = static_cast<float>(rand() % floatDecimalPrecision) / floatDecimalPrecision;
		float randomFloat = randomInt + randomDecimal;

		queue->enqueue(randomFloat);
		cout << randomFloat << endl;
	}

	cout << endl << endl;

	MyList<float>* list = new MyList < float>();

	MyList<float>* numbersList = new MyList<float>();

	int stackCount = stack->getCount();
	for (int i = 0; i < stackCount; i++)
	{
		numbersList->pushFront(stack->pop());
	}

	int queueCount = queue->getCount();
	for (int i = 0; i < queueCount; i++)
	{
		numbersList->pushFront(queue->dequeue());
	}

	float highestFloat = INT_MAX;
	int count3 = numbersList->getCount();
	for (int i = 0; i < numbersList->getCount(); i++)
	{
		highestFloat = GetHighest(*numbersList, highestFloat);
		list->insertAt(highestFloat, i);
	}

	cout << "List values: " << endl << endl;
	for (int i = 0; i < list->getCount(); i++)
	{
		cout << (*list)[i] << endl;
	}
	cout << endl << endl;

	delete numbersList;
	delete stack;
	delete queue;
	delete list;

	return 0;
}

float GetHighest(MyList<float>& list, float range)
{
	float highest = 0.f;

	for (int i = 0; i < list.getCount(); i++)
	{
		if (list[i] > highest && list[i] < range)
		{
			highest = list[i];
		}
	}

	return highest;
}