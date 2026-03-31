#pragma once
#include <stdexcept>

	template<typename T>
	class MyQueue
	{
	private:
		class Node
		{
		public:
			T data;
			Node* next;
			Node(const T& value)
			{
				data = value;
				next = nullptr;
			}
		};
		Node* frontNode;
		Node* backNode;
		int count;
	public:
		MyQueue()
		{
			frontNode = nullptr;
			backNode = nullptr;
			count = 0;
		}
		~MyQueue()
		{
			clear();
		}
		void enqueue(const T& value)
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
		T dequeue()
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
		T front() { return frontNode->data; }

		T back() { return backNode->data; }
		bool isEmpty() { return count <= 0; }
		void clear()
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
		int getCount() { return count; }
	};