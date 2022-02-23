#include "Queue.h"
#include "QueueTest.h"
#include <stdlib.h>

namespace Test
{
    void QueueTest1()
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

        LinkedList::Queue<char> queue;
        queue.Push(ch1);
        queue.Push(ch2);

        system("pause");
        while (queue.Size() > 0)
        {
            char* ch = queue.Pop();

            delete[] ch;
            ch = nullptr;
        }
    }

    void QueueTest2()
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
        LinkedList::Queue<MyStruct> list;
        list.Push(stru1);
        list.Push(stru2);

        system("pause");
        while (list.Size() > 0)
        {
            MyStruct* stru = list.Pop();

            delete stru;
            stru = nullptr;
        }
    }
}
