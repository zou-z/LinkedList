#pragma once
#include <iostream>

namespace LinkedList
{
    /// <summary>
    /// 栈链表
    /// </summary>
    /// <typeparam name="T">非指针类型</typeparam>
    template<typename T> struct Stack
    {
    public:
        Stack()
        {
            top = nullptr;
        }

        ~Stack()
        {
            while (top != nullptr)
            {
                Node* node = top;
                top = top->Next;
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
            if (top == nullptr)
            {
                top = new Node{ t,nullptr };
            }
            else
            {
                Node* node = new Node{ t,top };
                top = node;
            }
            ++count;
        }

        T* Pop()
        {
            if (top == nullptr)
            {
                return nullptr;
            }
            T* t = top->Content;

            Node* node = top;
            node->Content = nullptr;
            top = top->Next;
            delete node;
            node = nullptr;

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
        Node* top;
        unsigned int count = 0;
    };
}
