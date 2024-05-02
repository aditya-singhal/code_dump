#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class my_list {
private:
    Node* phead;

public:
    class impl_class;
    // std::unique_ptr <impl_class> impl;

    class iterator;
    my_list();
    ~my_list();

    bool is_empty();
    void insert_in_the_end(int data);
    int remove_from_end();
    void print_list();

    my_list::iterator begin();
    my_list::iterator end();
};

class my_list::iterator {
private:

public:
    Node *itr;
};