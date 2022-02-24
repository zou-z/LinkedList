# LinkedList
用链表实现一些STL中常用的容器。当容器被释放时可自动释放未取出元素占用的内存空间。

## Queue

基于链表的队列。

[查看定义](https://github.com/zou-z/LinkedList/blob/main/LinkedList/Queue.h)

### 成员函数

> void Push(T*);

向链表尾部添加元素

> T* Pop();

返回链表头部的元素，下一个节点变成新的头部。当链表为空时，返回`nullptr`

>  unsigned int Size();

返回链表存储的元素个数

## Stack

基于链表的栈。

[查看定义](https://github.com/zou-z/LinkedList/blob/main/LinkedList/Stack.h)

### 成员函数

> void Push(T*);

向链表顶部添加元素

> T* Pop();

返回链表顶部的元素，下一个节点变成新的顶部。当链表为空时，返回`nullptr`

>  unsigned int Size();

返回链表存储的元素个数

## List

基于链表的列表。不适合存储很长的列表（因为单向列表查找较慢，只能从一端进行查找，而且没有缓存查找结果）。

[查看定义](https://github.com/zou-z/LinkedList/blob/main/LinkedList/List.h)

### 成员函数

> unsigned int Size();

返回链表存储的元素个数

>void Append(T* t);

向链表尾部添加元素

> bool Insert(unsigned int index, T* t);

向链表索引为index处添加元素

> bool Remove(T* t);

把链表首个内容为t的元素删除

> bool RemoveAt(unsigned int index);

把链表中索引为index的元素删除

> int IndexOf(T* t)

获取链表中首个内容为t的元素的索引，如果没有则返回-1

> T* GetAt(unsigned int index);

获取索引为index的元素的内容

> T& operator[](unsigned int index);

按下标取出或修改非指针变量

## 说明

1. 为什么这些容器要区别存储指针变量和非指针变量？

   对于结构体、类来说，如果用存储非指针变量的容器去存储的话，执行完添加函数之后，就会调用它们的结构体。对于整数、浮点数、布尔值来说，也可以用存储指针变量的容器存储，但是频繁的在堆上申请空间会产生很多内存碎片，所以需要用存储非指针变量的容器存储。

2. 存储指针变量的List怎么修改元素？

   先用RemoveAt删除原先位置的元素，再用Insert把新的元素插入到原先的位置。没有对运算符[]重载，因为无论按下标取出的是T\*还是T\*&，都不能释放原先的内存。

