#include <iostream>

struct Node {
	int value;
	struct Node* next;
};

struct Node *phead = NULL;

bool is_empty() {
	if (phead == NULL) {
		return true;
	} else {
		return false;
	}
}

void insert_in_the_end(int value) {
	struct Node *pcur = NULL;

	if (is_empty() == true) {
		std::cout << "List is empty\n";
		pcur = (Node*) malloc(sizeof(Node));
		pcur->value = value;
		pcur->next = NULL;
		phead = pcur;
	} else {
		struct Node *temp = NULL;
		temp = (Node*) malloc(sizeof(Node));
		temp->value = value;
		temp->next = NULL;
		
		pcur = phead;
		while(pcur->next != NULL) {
			pcur = pcur->next;
		}
		pcur->next = temp;
	}
}

void print_list() {
	struct Node *pcur = NULL;

	pcur = phead;
	while(pcur != NULL) {
		std::cout << pcur->value;
		pcur = pcur->next;
	}
	std::cout << "\n";
}

void delete_in_the_middle_value_based(int value) {
	struct Node *pcur = NULL;
	struct Node *prev = NULL;
	
	pcur = phead;
	while ( pcur != NULL ) {
		if (pcur->value == value) {
			if (prev != NULL) {
				prev->next = pcur->next;
			} else {
				phead = pcur->next;
			}
			free(pcur);
			break;
		} else {
			prev = pcur;
			pcur = pcur->next;
		}
	}
}

void delete_in_the_middle_location_based(int key) {
	struct Node *pcur = NULL;
	struct Node *prev = NULL;
	int count = 0;

	pcur = phead;
	while (pcur != NULL) {
		if (count == key) {
			if (prev != NULL) {
				prev->next = pcur->next;
			} else {
				phead = pcur->next;
			}
			free(pcur);
			break;
		} else {
			prev = pcur;
			pcur = pcur->next;
		}
		count++;
	}
}

void reverse_list() {
	struct Node *pcur = NULL;
	struct Node *prev = NULL;
	struct Node *next = NULL;
	
	pcur = phead;
	while (pcur != NULL) {
		next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	phead = prev;
}

int main() {
	insert_in_the_end(1);
	insert_in_the_end(2);
	insert_in_the_end(3);
	insert_in_the_end(4);
	insert_in_the_end(5);
	print_list();
	reverse_list();
	print_list();

	delete_in_the_middle_value_based(4);
	insert_in_the_end(6);
	print_list();
	delete_in_the_middle_location_based(2);
	print_list();
	delete_in_the_middle_location_based(3);
	print_list();
	delete_in_the_middle_value_based(5);
	print_list();
	delete_in_the_middle_value_based(1);
	print_list();
	delete_in_the_middle_location_based(0);
	print_list();

	return 0;
}
