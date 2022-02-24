#pragma once

namespace LinkedList
{
	/// <summary>
	/// 列表链表（仅适用于存储指针变量）
	/// </summary>
	/// <typeparam name="T">非指针类型</typeparam>
	template<typename T> struct List
	{
	public:
		List()
		{
            head = nullptr;
            tail = nullptr;
		}

		~List()
		{
            while (head != nullptr)
            {
                Node* node = head;
                head = head->Next;
                delete node;
                node = nullptr;
            }
		}

        unsigned int Size()
        {
            return count;
        }

        void Append(T* t)
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

        bool Insert(unsigned int index, T* t)
        {
            if (index == 0)
            {
                head = new Node{ t,head };
            }
            else if (index > count)
            {
                return false;
            }
            else
            {
                Node* node = GetNodeAt(index - 1);
                Node* newNode = new Node{ t,node->Next };
                node->Next = newNode;
            }
            ++count;
            return true;
        }

        bool Remove(T* t)
        {
            if (Size() == 0)
            {
                return false;
            }
            if (head->Content == t)
            {
                DeleteHead();
                --count;
                return true;
            }
            Node* node = head;
            while (node->Next != nullptr)
            {
                if (node->Next->Content == t)
                {
                    DeleteNode(node);
                    --count;
                    return true;
                }
                node = node->Next;
            }
            return false;
        }

        bool RemoveAt(unsigned int index)
        {
            if (IsOutOfRange(index) || Size() == 0)
            {
                return false;
            }
            if (index == 0)
            {
                DeleteHead();
                --count;
                return true;
            }
            else
            {
                Node* node = head;
                while (true)
                {
                    if (index == 1)
                    {
                        DeleteNode(node);
                        --count;
                        return true;
                    }
                    node = node->Next;
                    --index;
                }
            }
            return false;
        }

        int IndexOf(T* t)
        {
            if (Size() == 0)
            {
                return -1;
            }
            int index = 0;
            Node* node = head;
            while (node != nullptr)
            {
                if (node->Content == t)
                {
                    return index;
                }
                node = node->Next;
                ++index;
            }
            return -1;
        }

        T* GetAt(unsigned int index)
        {
            Node* node = GetNodeAt(index);
            if (node == nullptr)
            {
                return nullptr;
            }
            return node->Content;
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

        bool IsOutOfRange(unsigned int index)
        {
            return index >= count;
        }

        Node* GetNodeAt(unsigned int index)
        {
            if (IsOutOfRange(index))
            {
                return nullptr;
            }
            Node* node = head;
            while (true)
            {
                if (index == 0)
                {
                    return node;
                }
                node = node->Next;
                --index;
            }
        }

        void DeleteHead()
        {
            Node* node = head;
            head = head->Next;
            delete node;
            node = nullptr;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }

        void DeleteNode(Node* previousNode)
        {
            if (previousNode->Next == tail)
            {
                previousNode->Next = nullptr;
                delete tail;
                tail = previousNode;
            }
            else
            {
                Node* deleteNode = previousNode->Next;
                previousNode->Next = deleteNode->Next;
                delete deleteNode;
                deleteNode = nullptr;
            }
        }
	};

    /// <summary>
    /// 列表链表（仅适用于存储非指针变量）
    /// </summary>
    /// <typeparam name="T">非指针类型</typeparam>
    template<typename T> struct List2
    {
    public:
        List2()
        {
            head = nullptr;
            tail = nullptr;
        }

        ~List2()
        {
            while (head != nullptr)
            {
                Node* node = head;
                head = head->Next;
                delete node;
                node = nullptr;
            }
        }

        unsigned int Size()
        {
            return count;
        }

        void Append(T t)
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

        bool Insert(unsigned int index, T t)
        {
            if (index == 0)
            {
                head = new Node{ t,head };
            }
            else if (index > count)
            {
                return false;
            }
            else
            {
                Node* node = GetNodeAt(index - 1);
                Node* newNode = new Node{ t,node->Next };
                node->Next = newNode;
            }
            ++count;
            return true;
        }

        bool RemoveAt(unsigned int index)
        {
            if (IsOutOfRange(index) || Size() == 0)
            {
                return false;
            }
            if (index == 0)
            {
                Node* node = head;
                head = head->Next;
                delete node;
                node = nullptr;

                if (head == nullptr)
                {
                    tail = nullptr;
                }
                --count;
                return true;
            }
            else
            {
                Node* node = head;
                while (true)
                {
                    if (index == 1)
                    {
                        if (node->Next == tail)
                        {
                            node->Next = nullptr;
                            delete tail;
                            tail = node;
                        }
                        else
                        {
                            Node* deleteNode = node->Next;
                            node->Next = deleteNode->Next;
                            delete deleteNode;
                            deleteNode = nullptr;
                        }
                        --count;
                        return true;
                    }
                    node = node->Next;
                    --index;
                }
            }
            return false;
        }

        T& operator[](unsigned int index)
        {
            Node* node = GetNodeAt(index);
            return node->Content;
        }
    private:
        struct Node
        {
            T Content;
            Node* Next;
        };
        Node* head;
        Node* tail;
        unsigned int count = 0;

        bool IsOutOfRange(unsigned int index)
        {
            return index >= count;
        }

        Node* GetNodeAt(unsigned int index)
        {
            if (IsOutOfRange(index))
            {
                return nullptr;
            }
            Node* node = head;
            while (true)
            {
                if (index == 0)
                {
                    return node;
                }
                node = node->Next;
                --index;
            }
        }
    };
}
