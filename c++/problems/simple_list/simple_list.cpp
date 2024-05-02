#include "simple_list.h"

template < typename T >
Node<T>::Node(): value(0), next(nullptr) {
	//std::cout << "Node constructor called\t" << this << "\n";
}

template < typename T >
Node<T>::~Node() {
	//std::cout << "Node destructor called\t" << this << "\n";
}

/**************************************************
Function name: simple_iterator()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
template <typename T>
simple_list<T>::simple_iterator::simple_iterator(): itr_node(NULL) {
	//std::cout << "simple_iterator constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~simple_iterator()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
template <typename T>
simple_list<T>::simple_iterator::~simple_iterator() {
	//std::cout << "simple_iterator destructor called\t" << this << "\n";
}

/**************************************************
Function name: operator++()
Description: Pre-increment operator overloading
Parameters: None
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::simple_iterator::operator++( ) {
	if ( this->itr_node != NULL ) {
		this->itr_node = this->itr_node->next;
	} else {
		throw "List ends\n";
	}
}

/**************************************************
Function name: operator++(int)
Description: Post-increment operator overloading
Parameters: None
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::simple_iterator::operator++(int) {
	if ( this->itr_node != NULL ) {
		this->itr_node = this->itr_node->next;
	} else {
		throw "List ends\n";
	}
}

/**************************************************
Function name: operator+=(int)
Description: plus equal to operator overloading
Parameters: None
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::simple_iterator::operator+=(int param) {
	for (int i=0; i< param;i++){
		if ( this->itr_node != NULL ) {
			this->itr_node = this->itr_node->next;
		} else {
			throw "List ends\n";
			break;
		}		
	}
}

/**************************************************
Function name: operator*()
Description: Dereference operator overloading
Parameters: None
Return type: Value at the iterator node
**************************************************/
template <typename T>
T simple_list<T>::simple_iterator::operator*( ) {
	if ( this->itr_node != NULL ) {
		return this->itr_node->value;
	} else {
		return (T)0;
	}
}

/**************************************************
Function name: operator!=()
Description: Not equal to operator overloading
Parameters: iterator object
Return type: bool, equal or not
**************************************************/
template <typename T>
bool simple_list<T>::simple_iterator::operator!= ( simple_iterator itr ) {
	if ( this->itr_node != itr.itr_node ) {
		return true;
	} else {
		return false;
	}
}

/**************************************************
Function name: simple_list()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
template <typename T>
simple_list<T>::simple_list() : head(NULL) {
	//std::cout << "simple list constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~simple_list()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
template <typename T>
simple_list<T>::~simple_list() {
	//std::cout << "simple list destructor called\t" << this << "\n";
	struct Node<T> *current_node = NULL;
	struct Node<T> *prev_node = NULL;
	current_node = head;

	while( current_node != NULL ) {
		prev_node = current_node;
		current_node = current_node->next;
		delete(prev_node);
	}
}

/**************************************************
Function name: is_empty()
Description: To check if list is empty or not
Parameters: None
Return type: bool 
**************************************************/
template <typename T>
bool simple_list<T>::is_empty() {
	if ( head == NULL ) {
		return true;
	} else {
		return false;
	}
}

/**************************************************
Function name: size()
Description: size of the list 
Parameters: None
Return type: list size
**************************************************/
template <typename T>
uint32_t simple_list<T>::size() {
	if (is_empty() != true) {
		struct Node<T> *itr_node = NULL;
		uint32_t count = 0;
		
		itr_node = head;
		while( itr_node != NULL ) {
			itr_node = itr_node->next;
			count++;
		}
		return count;
	} else {
		return 0;
	}
}

/**************************************************
Function name: front( )
Description: Returns value of the front node
Parameters: None
Return type: front node value
**************************************************/
template <typename T>
T simple_list<T>::front( )
{
	if (is_empty() != true)
	{
		return head->value;
	}
	else
	{
		return 0;
	}
}

/**************************************************
Function name: begin( )
Description: Returns an iterator to the beginning 
Parameters: None
Return type: Iterator object
**************************************************/
template <typename T>
typename simple_list<T>::simple_iterator simple_list<T>::begin( ) {
	simple_list<T>::simple_iterator itr;
	itr.itr_node = head;
	return itr;
}

/**************************************************
Function name: end( )
Description: Returns an iterator to the end 
Parameters: None
Return type: Iterator object
**************************************************/
template <typename T>
typename simple_list<T>::simple_iterator simple_list<T>::end( ) {
	simple_list<T>::simple_iterator itr;
	itr.itr_node = NULL;
	return itr;
}

/**************************************************
Function name: push_front()
Description: Inserts an element to the beginning
Parameters: Value
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::push_front( T value ) {
	struct Node<T> *temp = NULL;
	struct Node<T> *new_element = new Node<T>();
	new_element->value = value;

	if ( is_empty() != true ) {
		temp = head;
		head = new_element;
		head->next = temp;
	} else { //list is empty
		head = new_element;
		new_element->next = NULL;
	}
}

/**************************************************
Function name: push_end()
Description: Inserts an element to the end
Parameters: Value
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::push_end( T value )
{
	struct Node<T> *new_element = new Node<T>();
	struct Node<T> *itr_node = NULL;
	new_element->value = value;
	new_element->next = NULL;
	itr_node = head;

	if ( is_empty() != true )
	{
		while( itr_node->next != NULL )
		{
			itr_node = itr_node->next;
		}
		itr_node->next = new_element;
	}
	else
	{
		head = new_element;
	}
}

/**************************************************
Function name: erase_after()
Description: Erases element after an iterator postion
Parameters:  iterator object
Return type: iterator object
**************************************************/
template <typename T>
typename simple_list<T>::simple_iterator simple_list<T>::erase_after( simple_iterator iterator_pos ) {
	simple_list<T>::simple_iterator itr;
	struct Node<T> *current_node = NULL;
	struct Node<T> *prev_node = NULL;
	//To check if iterator is not pointing on the NULL
	if( iterator_pos != this->end() ) {
		if ( iterator_pos.itr_node->next != NULL ) {
			current_node = this->head;
			while ( current_node != iterator_pos.itr_node->next ) {
				prev_node = current_node;
				current_node = current_node->next;
			}
			prev_node->next = current_node->next;
			delete (current_node);
			itr.itr_node = prev_node->next;
			return itr;
		} else {
			return this->end();
		}
	} else {
		return iterator_pos;
	}
}

/**************************************************
Function name: insert_after()
Description: Insert element after an iterator postion
Parameters: iterator object, value
Return type: iterator object
**************************************************/
template <typename T>
typename simple_list<T>::simple_iterator simple_list<T>::insert_after( simple_iterator iterator_pos, T value )
{
	simple_list<T>::simple_iterator itr;
	struct Node<T> *new_element = new Node<T>();
	new_element->value = value;
	
	struct Node<T> *current_node = NULL;
	//To check if iterator is not pointing on the NULL
	if( iterator_pos != this->end() )
	{
		current_node = this->head;
		while ( current_node != iterator_pos.itr_node )
		{
			current_node = current_node->next;
		}

		if (current_node->next == NULL)
		{
			current_node->next = new_element;
			new_element->next = NULL;
			return this->end();
		}
		else
		{
			new_element->next = current_node->next;
			current_node->next = new_element;
			itr.itr_node = new_element->next;
			return itr;
		}
	}
	else
	{
		return iterator_pos;
	}
}

/**************************************************
Function name: print_list()
Description: Print the list
Parameters: None
Return type: None
**************************************************/
template <typename T>
void simple_list<T>::print_list( void )
{
	struct Node<T> *current_node = NULL;
	current_node = head;

	while( current_node != NULL )
	{
		std::cout << current_node->value << "  ";
		current_node = current_node->next;
	}
}

// Without this line I am getting a linking error and I have to define all the functions
// in simple_list.h file
// In order for the compiler to generate the code, it must see both the template definition
// (not just declaration) and the specific types/whatever used to "fill in" the template. 
// For example, if you're trying to use a Foo<int>, the compiler must see both the Foo template
// and the fact that you're trying to make a specific Foo<int>.
// The compiler probably doesn't remember the details of one .cpp file while it is compiling
// another .cpp file. It could, but most do not.
// This is called the "separate compilation model."
template class simple_list<char>;
