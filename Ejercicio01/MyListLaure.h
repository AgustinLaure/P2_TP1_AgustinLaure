#pragma once
#include <iostream>

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
		Node* getNodeAt(int index)
		{
			Node* resultNode = head;
			for (int i = 0; i < index; i++)
			{
				resultNode = resultNode->next;
			}
			return resultNode;
		}
	public:
		MyList() : head(nullptr), tail(nullptr), count(0) {}
		~MyList() {}
		void pushFront(const T& value)
		{
			Node* newNode = new Node();
			newNode->element = value;
			newNode->prev = nullptr;
			if (count <= 0)
			{
				newNode->next = nullptr;
				tail = newNode;
			}
			else
			{
				newNode->next = head;
				head->prev = newNode;
			}
			head = newNode;
			count++;
		}
		void pushBack(const T& value)
		{
			Node* newNode = new Node();
			newNode->element = value;
			newNode->next = nullptr;
			if (count <= 0)
			{
				newNode->prev = nullptr;
				head = newNode;
			}
			else
			{
				newNode->prev = tail;
				tail->next = newNode;
			}
			tail = newNode;
			count++;
		}
		T popFront()
		{

			if (count <= 0)
			{
				throw std::out_of_range("No hay ningun elemento que sacar");
			}
			T element = head->element;
			if (count <= 1)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				head = head->next;
				delete head->prev;
				head->prev = nullptr;
			}
			count--;
			return element;
		}
		T popBack()
		{
			if (count <= 0)
			{
				throw std::out_of_range("No hay ningun elemento que sacar");
			}
			T element = tail->element;
			if (count <= 1)
			{
				delete tail;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
			}
			count--;
			return element;
		}
		void clear()
		{
			if (count <= 0)
			{
				throw std::out_of_range("No hay ningun elementos que sacar");
			}
			Node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
				delete curr->prev;
				curr->prev = nullptr;
				head = curr;
			}
			delete curr;
			curr = nullptr;
			head = nullptr;
			tail = nullptr;
			count = 0;
		}
		int getCount() const { return count; } inline
			void insertAt(const T& value, int index)
		{
			if (index > count || index < 0)
			{
				throw std::out_of_range("Esa posicion no es valida");
			}
			if (index <= 0)
			{
				pushFront(value);

			}
			else if (index >= count)
			{
				pushBack(value);
			}
			else
			{
				Node* newNode = new Node();
				newNode->element = value;
				Node* prevNode = getNodeAt(index - 1);
				newNode->next = prevNode->next;
				newNode->prev = prevNode;
				prevNode->next = newNode;
				newNode->next->prev = newNode;
				count++;
			}
		}
		void RemoveAt(int index)
		{
			if (index > count - 1 || index < 0)
			{
				throw std::out_of_range("Esa posicion no es valida");
			}
			if (index <= 0)
			{
				popFront();
			}
			else if (index >= count - 1)
			{
				popBack();
			}
			else
			{
				Node* toDelete = getNodeAt(index);
				toDelete->prev->next = toDelete->next;
				toDelete->next->prev = toDelete->prev;
				delete toDelete;
				toDelete = nullptr;
				count--;
			}
		}
		T& operator[](int index)
		{
			if (index > count - 1 || index < 0)
			{
				throw std::out_of_range("El elemento no esta en la lista");
			}
			return getNodeAt(index)->element;
		}
	};