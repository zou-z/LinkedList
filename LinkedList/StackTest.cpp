#include "Stack.h"
#include "StackTest.h"
#include <stdlib.h>
#include <stdio.h>

namespace Test
{
    void StackTest1()
    {
        system("pause");
        char* ch1 = new char[] {'H', 'e', 'l', 'l', 'o', 0};
        char* ch2 = new char[] { 'W', 'o', 'r', 'l', 'd', 0 };
        char* ch3 = new char[] { 'C', '+', '+', 0 };

        LinkedList::Stack<char> stack;
        stack.Push(ch1);
        stack.Push(ch2);
        stack.Push(ch3);

        system("pause");
        while (stack.Size() > 0)
        {
            char* ch = stack.Pop();
            printf("%s\n", ch);
            delete[] ch;
            ch = nullptr;
        }
    }

    void StackTest2()
    {
        system("pause");
        size_t ch1Length = static_cast<size_t>(1024 * 1024) * 2;
        size_t ch2Length = static_cast<size_t>(1024 * 1024) * 3;
        char* ch1 = new char[ch1Length + 1]{ 0 };
        char* ch2 = new char[ch2Length + 1]{ 0 };
        for (size_t i = 0; i < ch1Length; ++i)
        {
            ch1[i] = (char)(65 + (i % 26));
            ch2[i] = (char)(97 + (i % 26));
        }
        for (size_t i = ch1Length; i < ch2Length; ++i)
        {
            ch2[i] = (char)(97 + (i % 26));
        }

        LinkedList::Stack<char> stack;
        stack.Push(ch1);
        stack.Push(ch2);

        system("pause");
        while (stack.Size() > 0)
        {
            char* ch = stack.Pop();

            delete[] ch;
            ch = nullptr;
        }
    }

    void StackTest3()
    {
        system("pause");
        struct MyStruct
        {
            char* Name;
            int Index;

            MyStruct()
            {
                Name = nullptr;
                Index = 0;
            }

            ~MyStruct()
            {
                delete[] Name;
                Name = nullptr;
            }
        };
        MyStruct* stru1 = new MyStruct();
        MyStruct* stru2 = new MyStruct();
        size_t ch1Length = static_cast<size_t>(1024 * 1024) * 1;
        size_t ch2Length = static_cast<size_t>(1024 * 1024) * 2;
        char* ch1 = new char[ch1Length + 1]{ 0 };
        char* ch2 = new char[ch2Length + 1]{ 0 };
        for (size_t i = 0; i < ch1Length; ++i)
        {
            ch1[i] = (char)(65 + (i % 26));
            ch2[i] = (char)(97 + (i % 26));
        }
        for (size_t i = ch1Length; i < ch2Length; ++i)
        {
            ch2[i] = (char)(97 + (i % 26));
        }
        stru1->Name = ch1;
        stru2->Name = ch2;
        stru1->Index = 1;
        stru2->Index = 2;
        LinkedList::Stack<MyStruct> stack;
        stack.Push(stru1);
        stack.Push(stru2);

        system("pause");
        while (stack.Size() > 0)
        {
            MyStruct* stru = stack.Pop();

            delete stru;
            stru = nullptr;
        }
    }

    void StackTest4()
    {
        system("pause");
        LinkedList::Stack2<int> stack;
        size_t length = static_cast<size_t>(1024 * 1024) * 2;
        for (size_t i = 0; i < length; ++i)
        {
            int num = i % 10;
            stack.Push(num);
        }

        system("pause");
        while (stack.Size() > 0)
        {
            int num = stack.Pop();

        }
    }
}
