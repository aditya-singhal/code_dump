#include <iostream>

struct Node {
	int value;
	Node* next; 
};

struct Node* phead = NULL;

bool is_empty() {
	if(phead == NULL) {
		return true;
	} else {
		return false;
	}
}

void print_list() {
	struct Node* cur_node = NULL;
	cur_node = phead;
	std::cout << "\nList values:\n";
	while(cur_node != NULL){
		std::cout << cur_node->value << "\t";
		cur_node = cur_node->next;
	}
}

void insert_in_the_end(int value) {
	struct Node* new_node = new Node();
	struct Node* cur_node = NULL;
	
	new_node->value = value;
	new_node->next = NULL;
	if(is_empty() == true){
		phead = new_node;
	} else {
		cur_node = phead;
		while(cur_node->next != NULL) {
			cur_node = cur_node->next;
		}
		cur_node->next = new_node;
	}
}

void insert_in_the_middle(int value, int index_value) {
	struct Node* new_node = new Node();
	struct Node* cur_node = NULL;
	
	new_node->value = value;
	if(is_empty() == true){
		phead = new_node;
	} else {
		cur_node = phead;
		while(cur_node != NULL) {
			cur_node = cur_node->next;
			if(cur_node->value == index_value) {
				if(cur_node->next == NULL){
					new_node->next = NULL;
				} else {
					new_node->next = cur_node->next;
				}
				cur_node->next = new_node;
				break;
			}
		}
	}
}

void delete_from_middle_value_based(int value){
	struct Node* cur_node = NULL;
	struct Node* prev_node = NULL;
	
	if(is_empty() == true){
		return;
	} else {
		cur_node = phead;
		while(cur_node != NULL){
			if(cur_node-> value == value){
				if (prev_node != NULL) {
					prev_node->next = cur_node->next;
				} else {
					phead = cur_node->next;
				}
				break;
			}
			prev_node = cur_node;
			cur_node = cur_node->next;
		}
	}
}

void find_a_loop(){


}

void reverse_list(){
	struct Node* cur_node = NULL;
	struct Node* prev_node = NULL;
	struct Node* next_node = NULL;

	cur_node = phead;
	while(cur_node != NULL) {
		next_node = cur_node->next;
		cur_node->next = prev_node;
		prev_node = cur_node;
		cur_node = next_node;
	}
	phead = prev_node;
}

int main() {
	insert_in_the_end(10);
	insert_in_the_end(8);
	insert_in_the_end(11);
	insert_in_the_middle(12,8);
	print_list();
	reverse_list();
	print_list();
	delete_from_middle_value_based(10);
	print_list();
	return 0;
}