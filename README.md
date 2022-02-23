# LinkedList
用链表实现一些STL中常用的容器。当容器被释放时可自动释放未取出元素占用的内存空间。

## Queue

基于链表的队列。

[查看定义](https://github.com/zou-z/LinkedList/blob/main/LinkedList/Queue.h)

### 成员函数

> void Push(T*);

向链表尾部添加T*

> T* Pop();

返回链表头部的T*，下一个节点变成新的头部。当链表为空时，返回`nullptr`

>  unsigned int Size();

返回链表存储的T*个数

## Stack

基于链表的栈。

[查看定义](https://github.com/zou-z/LinkedList/blob/main/LinkedList/Stack.h)

### 成员函数

> void Push(T*);

向链表顶部添加T*

> T* Pop();

返回链表顶部的T*，下一个节点变成新的顶部。当链表为空时，返回`nullptr`

>  unsigned int Size();

返回链表存储的T*个数

