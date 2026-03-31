#include "MyStackLaure.h"

namespace MyStack
{
	template<typename T>
	MyStack<T>::MyStack::Node::Node(const T& value) : data(value), prev(nullptr) {}

	template<typename T>
	MyStack<T>::MyStack()
	{
		topNode = nullptr;
		count = 0;
	}

	template<typename T>
	MyStack<T>::~MyStack()
	{
		clear();
	}

	template<typename T>
	void MyStack<T>::push(const T& value)
	{
		Node* newNode = new Node(value);
		if (count > 0)
		{
			newNode->prev = topNode;
		}
		topNode = newNode;
		count++;
	}

	template<typename T>
	T MyStack<T>::pop()
	{
		if (count <= 0)
		{
			throw std::out_of_range("No hay elementos que sacar");
		}
		T data = topNode->data;
		Node* prev = nullptr;
		if (count > 1)
		{
			prev = topNode->prev;
		}
		delete topNode;
		if (prev)
		{
			topNode = prev;
		}
		else
		{
			topNode = nullptr;
		}
		count--;
		return data;
	}

	template<typename T>
	T MyStack<T>::top()
	{

		if (count <= 0)
		{
			throw std::out_of_range("no hay ningun elemento");
		}
		return topNode->data;
	}

	template<typename T>
	bool MyStack<T>::isEmpty() { return count <= 0; }

	template<typename T>
	void MyStack<T>::clear()
	{
		if (count > 1)
		{
			Node* curr = topNode;
			while (curr->prev)
			{
				curr = curr->prev;
				delete topNode;
				topNode = curr;
			}
		}
		if (topNode)
		{
			delete topNode;
		}
		topNode = nullptr;
		count = 0;
	}

	template<typename T>
	int MyStack<T>::getCount() { return count; }
}