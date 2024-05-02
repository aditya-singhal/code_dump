#include <iostream>
#include<unordered_map>
#define TOTAL_CACHE  4
using namespace std;
struct CacheNode
{
  uint32_t id;
};

struct DNode
{
  DNode() : next(nullptr), prev(nullptr) {}
  int val;
  DNode* next;
  DNode* prev;
};

class CacheManager
{
public :
    CacheManager() {}
    CacheManager(DNode* head , DNode* tail) : head(head), tail(tail) {}

    bool Read(int id) {
        if(CacheTable.find(id) != CacheTable.end())
        {
          cout << "Cache hit" << endl; 
          return 1;
        }
        else{
            cout << "cache Miss" <<endl;
          return 0;
        }
    }
  
    void Write(int id)
    {
      if(CacheTable.find(id) == CacheTable.end())
      {
        if(CacheTable.size() == TOTAL_CACHE)
        {
          // invoke lru
          // delete from DLL
          DNode* temp = tail->prev;
          tail->prev= temp->prev;
          temp->prev->next = tail;
          CacheTable.erase(temp->val);
          delete temp;
          // ADD into DLL 
          DNode* newNode = new DNode();
          newNode->val = id;
          newNode->next = head->next;
          newNode->prev = head;
          head->next = newNode;
          for(auto &x : CacheTable)
            {
              cout << x.first << " ";
            }
          cout <<"\n";
            
        }
        else{
          CacheNode *node = new CacheNode();
          node->id = id;
          CacheTable[id] = node;
          
          // add to the head of linked list
          DNode* newNode = new DNode();
          DNode* temp = head->next;
          head->next = newNode;
          newNode->prev = head;
          newNode->next = temp;
          temp->prev = newNode;
          
        }
      }
    }

private:
    std::unordered_map<int , CacheNode*> CacheTable; 
    DNode* head;
    DNode* tail;
};

int main() {
  DNode* h = new DNode();
  DNode* t = new DNode();
  h->next = t;
  t->prev = h;
  CacheManager CM(h , t);
  
  CM.Write(1);
  CM.Write(2);
  CM.Write(3);
  CM.Read(20);
  CM.Write(7);
  CM.Write(10);
  CM.Read(10);
  
}