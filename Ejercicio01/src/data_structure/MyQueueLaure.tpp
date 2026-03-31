#include "MyQueueLaure.h"

namespace MyQueue
{
	template<typename T>
	MyQueue<T>::MyQueue::Node::Node(const T& value) : data(value), next(nullptr) {}

	template<typename T>
	MyQueue<T>::MyQueue()
	{
		frontNode = nullptr;
		backNode = nullptr;
		count = 0;
	}

	template<typename T>
	MyQueue<T>::~MyQueue()
	{
		clear();
	}

	template<typename T>
	void MyQueue<T>::enqueue(const T& value)
	{
		Node* newElement = new Node(value);
		if (count != 0)
		{
			backNode->next = newElement;
		}
		else
		{
			frontNode = newElement;
		}
		backNode = newElement;
		count++;
	}

	template<typename T>
	T MyQueue<T>::dequeue()
	{
		if (count == 0)
		{
			throw std::out_of_range("No hay elementos");
		}
		Node* toRemoveNode = frontNode;
		T data = toRemoveNode->data;
		if (count == 1)
		{
			frontNode = nullptr;
			backNode = nullptr;
		}
		else
		{
			frontNode = toRemoveNode->next;
		}
		delete toRemoveNode;
		toRemoveNode = nullptr;
		count--;
		return data;
	}

	template<typename T>
	T MyQueue<T>::front() { return frontNode->data; }

	template<typename T>
	T MyQueue<T>::back() { return backNode->data; }

	template<typename T>
	bool MyQueue<T>::isEmpty() { return count <= 0; }

	template<typename T>
	void MyQueue<T>::clear()
	{
		if (count > 1)
		{
			Node* currentNode = frontNode;
			while (frontNode->next != nullptr)
			{
				currentNode = currentNode->next;
				delete frontNode;
				frontNode = currentNode;
			}
		}
		if (frontNode)
		{
			delete frontNode;
		}
		frontNode = nullptr;
		backNode = nullptr;
		count = 0;
	}

	template<typename T>
	int MyQueue<T>::getCount() { return count; }
}