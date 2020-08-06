#include <iostream>

struct Node {
	int value;
	struct Node* next;
};

struct Node* pHead = NULL;

bool is_empty(){
	if (pHead == NULL){
		return true;
	} else {
		return false;
	}
}

void insert_in_the_end(int value){
	struct Node* new_node = NULL;
	struct Node* current_node = NULL;
	
	new_node = new Node();
	new_node->value = value;

	if (is_empty()==true){
		pHead = new_node;
	} else {
		current_node = pHead;
		while(current_node->next != NULL) {
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	new_node->next = NULL;
}

void print() {
	struct Node* current_node = NULL;

	current_node = pHead;
	while(current_node != NULL){
		std::cout << "value: " << current_node->value << "\n";
		current_node = current_node->next;
	}
}

bool find_a_loop(){
	struct Node* slow_ptr = NULL;
	struct Node* fast_ptr = NULL;

	if (is_empty()==true){
		return false;
	} else {
		slow_ptr = pHead;
		fast_ptr = pHead;
		while(slow_ptr && fast_ptr && (fast_ptr->next)) {
			slow_ptr = slow_ptr->next;
			fast_ptr = (fast_ptr->next)->next;
			if (slow_ptr == fast_ptr){
				return true;
			}
		}

		return false;
	}
}

int main(){

	print();
	insert_in_the_end(1);
	print();
	insert_in_the_end(3);
	insert_in_the_end(4);
	print();
	insert_in_the_end(5);
	insert_in_the_end(6);
	insert_in_the_end(8);
	print();
	return 0;
}
