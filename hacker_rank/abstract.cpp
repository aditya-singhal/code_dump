#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <stdint.h>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache {
protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};

class LRUCache : public Cache {
private:
   int count;
   uint32_t size();
   bool is_empty();
   void push_front(int key,int value);
   void insert_front( Node* node );
   void pop_end();
   void erase_middle( Node* node );

public:
   LRUCache(int capacity);
   void set(int, int);
   int get(int);
};

bool LRUCache::is_empty() {
   if ( head == NULL ) {
      return true;
   } else {
      return false;
   }
}

LRUCache::LRUCache(int capacity) {
   Cache::cp = capacity;
   head = NULL;
   tail = NULL;
   count = 0;
}

void LRUCache::push_front( int key,int value ) {
   struct Node* temp = NULL;
   struct Node* new_element = new Node(key, value);

   if ( is_empty() != true ) {
      temp = head;
      head = new_element;
      head->next = temp;
      head->prev = NULL;
      if(tail->prev == NULL) {
         tail->prev = head;
      }
   } else { //list is empty
      head = new_element;
      tail = new_element;
      new_element->prev = NULL;
      new_element->next = NULL;
   }
   mp.insert(pair<int, Node*>(key, new_element));
   count++;
}

void LRUCache::insert_front( Node* node ) {
   struct Node* temp = NULL;

   temp = head;
   head = node;
   head->next = temp;
   head->prev = NULL;   
}

void LRUCache::pop_end( ) {
   struct Node* temp = NULL;

   temp = tail;
   tail = tail->prev;
   tail->next = NULL;
   delete(temp);
   count--;
}

void LRUCache::erase_middle( Node* node ) {
   struct Node* temp = NULL;

   temp = node->prev;
   if (temp != NULL) {
      temp->next = node->next;
   }
}

void LRUCache::set(int key, int value) {
   map<int, Node*>::iterator itr;
   itr = mp.find(key);
   if (itr != mp.end()) {
      mp[key]->value = value;
      erase_middle( mp[key] );
      insert_front( mp[key] );
   } else {
      if (count == cp) {
         //Delete the last key from the map
         mp.erase(tail->key);
         pop_end();
      }
      push_front(key, value);
   }
}

int LRUCache::get(int key){
   map<int,Node*>::iterator itr;
   itr = Cache::mp.find(key);
   if (itr != mp.end()) {
      //std::cout << "Found \n";
      erase_middle( Cache::mp[key] );
      insert_front( Cache::mp[key] );
      return Cache::mp[key]->value;
   } else {
     //std::cout << "Not found\n";
     return -1;
   }
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }

   return 0;
}
