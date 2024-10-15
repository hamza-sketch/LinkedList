//
//  DoubleLinkedlistSourceCode.cpp
//  practiceWork
//
//  Created by Tauqir Hayat on 15/10/2024.
//

#include <stdio.h>

#include<iostream>
using namespace std;
template<typename X>
struct DNode
{
    X info;
    DNode<X>* next;
    DNode<X>* prev;
    DNode() :next(nullptr), prev(nullptr)
    {}
    DNode(X val) :info(val), next(nullptr), prev(nullptr)
    {}
};
template<typename T>
class LDLL
{
    DNode<T>* head;
public:
    LDLL() :head(nullptr)
    {}
    ~LDLL()
    {
        while (head)
            removeAtHead();
    }
   void removeAtHead()
{
    if (head == nullptr)
        return;
    DNode<T>* p = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete p;
}
void removeAtTail()
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    DNode<T>* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->prev->next = nullptr;
    delete p;
}
    bool insertAfter(T key, T val)
    {
        if (head == nullptr)
            return false;
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        if (p)
        {
            DNode<T>* x = new DNode<T>(val);
            x->next = p->next;
            x->prev = p;
            p->next = x;
            if (x->next != nullptr)
                x->next->prev = x;
            return true;
        }
        return false;
    }
    void insertBefore(T key, T val)
    {
        if (head == nullptr)
            return;
        if (head->info == key)
        {
            insertAtHead(val);
            return;
        }
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        if (p)
        {
            DNode<T>* x = new DNode<T>(val);
            x->next = p;
            x->prev = p->prev;
            p->prev = x;
            x->prev->next = x;
        }
    }
    void remove(T key)
    {
        if (head == nullptr)
            return;
        if (head->info == key)
        {
            DNode<T>* p = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete p;
            return;
        }
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        if (p == nullptr)
            return;
        p->prev->next = p->next;
        if (p->next != nullptr)
            p->next->prev = p->prev;
        delete p;
    }

    void removeAfter(T key)
    {
        if (head == nullptr)
            return;
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        if (p == nullptr || p->next == nullptr)
            return;
        if (p->next->next == nullptr)
        {
            delete p->next;
            p->next = nullptr;
            return;
        }
        p->next = p->next->next;
        delete p->next->prev;
        p->next->prev = p;
    }
    void removeBefore(T key)
    {
        if (head == nullptr || head->info == key || head->next == nullptr)
            return;
        if (head->next->info == key)
        {
            removeAtHead();
            return;
        }
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        if (p == nullptr)
            return;
        DNode<T>* x = p->prev;
        x->prev->next = p;
        p->prev = x->prev;
        delete x;
    }
    void printList()
    {
        DNode<T>* p = head;
        DNode<T>* tail = head;
        while (p != nullptr)
        {
            cout << p->info << " : ";
            tail = p;
            p = p->next;
        }
        cout << "\n";
        while (tail != nullptr)
        {
            cout << tail->info << " : ";
            tail = tail->prev;
        }
    }
    bool search(T key)
    {
        DNode<T>* p = head;
        while (p != nullptr && p->info != key)
        {
            p = p->next;
        }
        return (p != nullptr);
    }
};

int main()
{
    LDLL<int> myFirstList;
    myFirstList.insertAtTail(10);
    myFirstList.insertAtTail(20);
    myFirstList.insertAtTail(30);
    myFirstList.insertAtTail(40);
    myFirstList.printList();
    cout << "\n\n";
    cout << myFirstList.search(40);
    //myFirstList.printList();
    cout << "\n\n";
    return 0;
}
