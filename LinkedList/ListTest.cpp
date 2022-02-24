#include "List.h"
#include "ListTest.h"
#include <stdio.h>
#include <stdlib.h>

namespace Test
{
    void ListTest1()
    {
        system("pause");
        LinkedList::List<int> list;
        int* num = nullptr;
        for (int i = 1; i <= 10; ++i)
        {
            num = new int(i);
            list.Append(num);
        }
        num = new int(11);
        list.Insert(0, num);
        num = new int(22);
        list.Insert(3, num);
        num = new int(33);
        list.Insert(4, num);
        num = new int(44);
        list.Insert(10, num);
        num = new int(55);
        list.Insert(14, num);

        system("pause");
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            int* num = list.GetAt(i);
            printf("%d\n", *num);
        }
    }

    void ListTest2()
    {
        system("pause");
        LinkedList::List<int> list;
        int* num1 = new int(1); list.Append(num1);
        int* num2 = new int(2); list.Append(num2);
        int* num3 = new int(3); list.Append(num3);
        int* num4 = new int(4); list.Append(num4);
        int* num5 = new int(5); list.Append(num5);
        int* num6 = new int(6); list.Append(num6);
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            int* num = list.GetAt(i);
            printf("%d ", *num);
        }
        printf("\n");
        printf("%d %d %d %d\n", list.IndexOf(num1), list.IndexOf(num2), list.IndexOf(num5), list.IndexOf(new int('1')));

        system("pause");
        list.Remove(num1);
        list.Remove(num3);
        list.Remove(num4);
        list.Remove(num6);
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            int* num = list.GetAt(i);
            printf("%d ", *num);
        }
        printf("\n");
        printf("%d %d %d %d\n", list.IndexOf(num1), list.IndexOf(num2), list.IndexOf(num5), list.IndexOf(new int('2')));
        printf("size = %d\n", list.Size());
        list.Remove(num2);
        list.Remove(num5);
        printf("size = %d\n", list.Size());
    }

    void ListTest3()
    {
        system("pause");
        LinkedList::List<int> list;
        for (int i = 1; i <= 10; ++i)
        {
            int* num = new int(i);
            list.Append(num);
        }
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            int* num = list.GetAt(i);
            printf("%d ", *num);
        }
        printf("\n");

        system("pause");
        list.RemoveAt(0);
        list.RemoveAt(8);
        list.RemoveAt(3);
        list.RemoveAt(4);
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            int* num = list.GetAt(i);
            printf("%d ", *num);
        }
        printf("\n");
        printf("size = %d\n", list.Size());
        list.RemoveAt(5);
        list.RemoveAt(4);
        list.RemoveAt(3);
        list.RemoveAt(2);
        list.RemoveAt(1);
        list.RemoveAt(0);
        printf("size = %d\n", list.Size());
    }

    void ListTest4()
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
        LinkedList::List<char> list;
        list.Append(ch1);
        list.Append(ch2);

        system("pause");
        while (list.Size() > 0)
        {
            char* ch = list.GetAt(0);
            list.Remove(ch);
        }
    }

    void ListTest5()
    {
        system("pause");
        LinkedList::List2<int> list;
        for (int i = 1; i <= 10; ++i)
        {
            list.Append(i);
        }
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            printf("%d ", list[i]);
        }
        printf("\n");

        list.Insert(3, 5);
        list.Insert(4, 1);
        list.Insert(0, 0);
        list.Insert(13, 7);
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            printf("%d ", list[i]);
        }
        printf("\n");

        list.RemoveAt(4);
        list.RemoveAt(4);
        list.RemoveAt(11);
        list.RemoveAt(0);
        for (unsigned int i = 0; i < list.Size(); ++i)
        {
            printf("%d ", list[i]);
        }
        printf("\n");
    }

    void ListTest6()
    {
        system("pause");
        LinkedList::List2<int> list;
        for (unsigned int i = 0; i < 1024 * 10; ++i)
        {
            list.Append(i);
        }
        for (unsigned int i = 0; i < 1024 * 10; ++i)
        {
            list[i] = list[i] + 5;
        }
        system("pause");
    }
}
