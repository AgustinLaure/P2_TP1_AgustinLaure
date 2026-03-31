#pragma once
#include <stdexcept>

	template<typename T>
	class MyStack
	{
	private:
		class Node
		{
		public:
			T data;
			Node* prev;
			Node(const T& value)
			{
				data = value;
				prev = nullptr;
			}
		};
		Node* topNode;
		int count;
	public:
		MyStack()
		{
			topNode = nullptr;
			count = 0;
		}
		~MyStack()
		{
			clear();
		}
		void push(const T& value)
		{
			Node* newNode = new Node(value);
			if (count > 0)
			{
				newNode->prev = topNode;
			}
			topNode = newNode;
			count++;
		}
		T pop()
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
		T top()
		{

			if (count <= 0)
			{
				throw std::out_of_range("no hay ningun elemento");
			}
			return topNode->data;
		}
		bool isEmpty() { return count <= 0; }
		void clear()
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
		int getCount() { return count; }
	};
