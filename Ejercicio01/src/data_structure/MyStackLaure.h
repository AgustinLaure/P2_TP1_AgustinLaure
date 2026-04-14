#pragma once
#include <stdexcept>

namespace MyStack
{
	template<typename T>
	class MyStack
	{
	private:
		//class Node
		//{
		//public:
		//	T data;
		//	Node* prev;
		//	Node(const T& value);
		//};
		//
		//Node* topNode;
		int count;
	public:
		MyStack();
		~MyStack();
		void push(const T& value);
		T pop();
		T top();
		bool isEmpty();
		void clear();
		int getCount();
	};
}

#include "data_structure/MyStackLaure.tpp"
