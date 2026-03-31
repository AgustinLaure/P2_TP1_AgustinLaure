#pragma once
#include <iostream>

namespace MyList
{
	template <typename T>	

	class MyList
	{
	private:

		struct Node
		{
			T element;
			Node* prev;
			Node* next;
		};

		Node* head;
		Node* tail;
		int count = 0;

		Node* getNodeAt(int index);

	public:

		MyList();
		~MyList();

		void pushFront(const T& value);
		void pushBack(const T& value);
		T popFront();
		T popBack();
		void clear();
		int getCount() const { return count; } inline
			void insertAt(const T& value, int index);

		void RemoveAt(int index);
		T& operator[](int index);
	};
}
