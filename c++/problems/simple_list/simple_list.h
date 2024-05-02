#ifndef __SIMPLE_LIST_H__
#define __SIMPLE_LIST_H__

#include <iostream>
#include <stdint.h>

template < typename T >
struct Node {
    Node();
    ~Node();
    T value;
    struct Node *next;
};

template < typename T >
class simple_list {
private:
    struct Node<T> *head;
    
public:
    class simple_iterator;
    simple_list();
    ~simple_list();
    bool is_empty();
    uint32_t size();
    simple_list<T>::simple_iterator begin();
    simple_list<T>::simple_iterator end();
    simple_list<T>::simple_iterator insert_after( simple_iterator iterator_pos, T value );
    simple_list<T>::simple_iterator erase_after( simple_iterator iterator_pos );
    T front();
    void push_front( T value );
    void push_end(T value);
    void print_list();
};

template < typename T >
class simple_list<T>::simple_iterator {
public:
    struct Node<T> *itr_node;
    simple_iterator();
    ~simple_iterator();
    void operator++();      //pre
    void operator++(int);   //post
    void operator+=(int);
    bool operator!=( simple_iterator itr );
    T operator*();
};

#endif
