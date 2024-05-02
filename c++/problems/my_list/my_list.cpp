#include "my_list.h"

// Use template
// simple iterator use

my_list::my_list() {
    cout << "my_list constructor" << endl;
    phead = NULL;
}

my_list::~my_list() {
    cout << "my_list destructor" << endl;
}

bool my_list::is_empty() {
    if (phead == NULL) {
        cout << "list is empty!" << endl;
        return true;
    } else {
        return false;
    }
}

void my_list::insert_in_the_end(int data) {
    Node* temp_node = new Node();
    temp_node->data = data;
    temp_node->next = NULL;

    if (is_empty() == true) {
        cout << "list is empty, updating phead" << endl;
        phead = temp_node;
    } else {
        Node* itr = phead;
        while(itr->next != NULL) {
            itr = itr->next;
        }

        itr->next = temp_node;
    }
}

int my_list::remove_from_end() {
    Node* itr = phead;
    Node* prev_node = NULL;
    int data = 0;

    if (is_empty() == true) {
        return 0;
    }

    while (itr->next != NULL) {
        prev_node = itr;
        itr = itr->next;
    }

    data = itr->data;
    if (prev_node == NULL){
        phead = NULL;
    } else {
        prev_node->next = NULL;
    }
    delete(itr);

    return data;
}

void my_list::print_list() {
    Node* itr = phead;

    while(itr != NULL) {
        cout << "list data: " << itr->data << endl;
        itr = itr->next;
    }
}

my_list::iterator my_list::begin() {
    my_list::iterator obj;
    obj.itr = phead;
    return obj;
}

my_list::iterator my_list::end() {
    // Add a while loop to make itr pointing to the end Node.
}

int main () {
    my_list hello_list;
    my_list::iterator pitr;

    pitr = hello_list.begin();

    hello_list.insert_in_the_end(1);
    hello_list.insert_in_the_end(2);
    hello_list.insert_in_the_end(3);
    hello_list.insert_in_the_end(4);
    hello_list.insert_in_the_end(5);

    hello_list.print_list();

    hello_list.remove_from_end();
    hello_list.print_list();
    hello_list.remove_from_end();
    hello_list.print_list();
    hello_list.remove_from_end();
    hello_list.print_list();
    hello_list.remove_from_end();
    hello_list.print_list();
    hello_list.remove_from_end();
    hello_list.print_list();

    return 0;
}