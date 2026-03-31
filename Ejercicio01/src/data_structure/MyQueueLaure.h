#pragma once
#include <stdexcept>

namespace MyQueue
{
	template<typename T>
	class MyQueue
	{
	private:
		class Node
		{
		public:
			T data;
			Node* next;
			Node(const T& value);
		};

		Node* frontNode;
		Node* backNode;
		int count;

	public:
		MyQueue();

		~MyQueue();

		void enqueue(const T& value);
		T dequeue();
		T front();
		T back();
		bool isEmpty();
		void clear();
		int getCount();
	};
}
