#pragma once

namespace LinkedList
{
	/// <summary>
	/// 队列链表
	/// </summary>
	/// <typeparam name="T">非指针类型</typeparam>
	template<typename T> struct Queue
	{
	public:
		Queue()
		{
			head = nullptr;
			tail = nullptr;
		}

		~Queue()
		{
			while (head != nullptr)
			{
				Node* node = head;
				head = head->Next;
				node->Next = nullptr;
				delete node;
				node = nullptr;
			}
		}

		unsigned int Size()
		{
			return count;
		}

		void Push(T* t)
		{
			if (tail == nullptr)
			{
				head = new Node{ t,nullptr };
				tail = head;
			}
			else
			{
				tail->Next = new Node{ t,nullptr };
				tail = tail->Next;
			}
			++count;
		}

		T* Pop()
		{
			if (head == nullptr)
			{
				return nullptr;
			}
			T* t = head->Content;

			Node* node = head;
			head->Content = nullptr;
			head = head->Next;
			delete node;
			node = nullptr;

			if (head == nullptr && tail != nullptr)
			{
				tail = nullptr;
			}
			count = count > 0 ? count - 1 : count;

			return t;
		}
	private:
		struct Node
		{
			T* Content;
			Node* Next;

			~Node()
			{
				if (Content != nullptr)
				{
					delete Content;
					Content = nullptr;
				}
			}
		};
		Node* head;
		Node* tail;
		unsigned int count = 0;
	};
}
