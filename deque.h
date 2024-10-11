#pragma once
#include <iostream>
using namespace std;

template <class T>
class Deque 
{
private:
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d, Node* p = nullptr, Node* n = nullptr) : data(d), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}
    ~Deque()
    {
        Node* current = head;
        while (current!= nullptr)
        {
            delete current;
            current = current->next;
        }
    }

    void push_front(const T& value);
    void push_back(const T& value);
    template <class... Args>
    void emplace_back(Args&&... args) 
    {
        if (size == 0) {
            tail = new Node(std::forward<Args>(args)...);
            head = tail;
        }
        else {
            tail->next = new Node(std::forward<Args>(args)..., tail, nullptr);
            tail = tail->next;
        }
        size++;
    }
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    bool empty() const;
    int getSize() const;
};