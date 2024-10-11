#include "deque.h"
using namespace std;

template <class T>
void Deque<T>::push_front(const T& value)
{
    if (size == 0) {
        head = new Node(value);
        tail = head;
    }
    else {
        head->prev = new Node(value, nullptr, head);
        head = head->prev;
    }
    size++;
}

template <class T>
void Deque<T>::push_back(const T& value)
{
    if (size == 0)
    {
        tail = new Node(value);
        head = tail;
    }
    else
    {
        tail->next = new Node(value, tail, nullptr);
        tail = tail->next;
    }
    size++;
}

template <class T>
void Deque<T>::pop_front()
{
    if (size == 0)
    {
        cout << "Deque is empty" << endl;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        size--;
    }
}

template <class T>
void Deque<T>::pop_back()
{
    if (size == 0)
    {
        cout << "Deque is empty" << endl;
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        size--;
    }
}

template <class T>
T Deque<T>::front() const
{
    if (size == 0)
    {
        throw "Deque is empty";
    }
    else
    {
        return head->data;
    }
}

template <class T>
T Deque<T>::back() const
{
    if (size == 0)
    {
        throw "Deque is empty";
    }
    else
    {
        return tail->data;
    }
}

template <class T>
bool Deque<T>::empty() const
{
    return size == 0;
}

template <class T>
int Deque<T>::getSize() const
{
    return size;
}

