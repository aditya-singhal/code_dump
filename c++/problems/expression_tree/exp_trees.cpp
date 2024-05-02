#include "exp_trees.h"
#include <typeinfo>

/**************************************************
Function name: Node()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
Node::Node() {
	//std::cout << "Node constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~Node()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
Node::~Node(){
	//std::cout << "Node destructor called\t" << this << "\n";
}

/**************************************************
Function name: Num()
Description: Constructor
Parameters: number
Return type: None
**************************************************/
Num::Num( int number ) {
	//std::cout << "Num constructor called\t" << this->number << "\n";
	this->number = number;
}

/**************************************************
Function name: ~Num()
Description: Destructor
Parameters: None
Return type: 
**************************************************/
Num::~Num() {
	//std::cout << "Num destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: print number
Parameters: None
Return type: 
**************************************************/
void Num::print() {
	std::cout << this->number;
}

/**************************************************
Function name: is_operator()
Description: is operator or not
Parameters: None
Return type: bool
**************************************************/
bool Num::is_operator() {
	return false;
}

/**************************************************
Function name: get_value()
Description: get value
Parameters: None
Return type: value
**************************************************/
int Num::get_value() {
	return this->number;
}

/**************************************************
Function name: set_value()
Description: set value
Parameters: value
Return type: None
**************************************************/
void Num::set_value( int value) {
	this->number = value;
}

/**************************************************
Function name: is_literal_number()
Description: is literal number or not
Parameters: None
Return type: bool
**************************************************/
bool Num::is_literal_number() {
	return true;
}

/**************************************************
Function name: Variable()
Description: Constructor
Parameters: variable
Return type: None
**************************************************/
Variable::Variable( std::string variable ) {
	//std::cout << "Variable constructor called\t" << this << "\n";
	this->variable = variable;
}

/**************************************************
Function name: ~Variable()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
Variable::~Variable() {
	//std::cout << "Variable destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: Print the value
Parameters: None
Return type: None
**************************************************/
void Variable::print() {
	std::cout << this->variable;
}

/**************************************************
Function name: is_operator()
Description: is operator or not
Parameters: None
Return type: bool
**************************************************/
bool Variable::is_operator() {
	return false;
}

/**************************************************
Function name: OpPlus()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
OpPlus::OpPlus() {
	//std::cout << "OpPlus constructor called\t" << this << "+" <<"\n";
}

/**************************************************
Function name: ~OpPlus()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
OpPlus::~OpPlus() {
	//std::cout << "OpPlus destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: print
Parameters: None
Return type: None
**************************************************/
void OpPlus::print() {
	std::cout << '+';
}

/**************************************************
Function name: is_operator()
Description: 
Parameters: None
Return type: bool
**************************************************/
bool OpPlus::is_operator() {
	return true;
}

/**************************************************
Function name: evaluate_operator()
Description: evaluate 
Parameters: None
Return type: result
**************************************************/
int OpPlus::evaluate_operator( int param1, int param2 ) {
	return param1 + param2;
}

/**************************************************
Function name: OpMinus()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
OpMinus::OpMinus() {
	//std::cout << "OpMinus constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~OpMinus()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
OpMinus::~OpMinus() {
	//std::cout << "OpMinus destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: print
Parameters: None
Return type: None
**************************************************/
void OpMinus::print() {
	std::cout << '-';
}

/**************************************************
Function name: is_operator()
Description: 
Parameters: None
Return type: bool
**************************************************/
bool OpMinus::is_operator() {
	return true;
}

/**************************************************
Function name: evaluate_operator()
Description: evaluate
Parameters: None
Return type: result
**************************************************/
int OpMinus::evaluate_operator( int param1, int param2 ) {
	return param1 - param2;
}

/**************************************************
Function name: OpMultiply()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
OpMultiply::OpMultiply() {
	//std::cout << "OpMultiply constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~OpMultiply()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
OpMultiply::~OpMultiply() {
	//std::cout << "OpMultiply destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: 
Parameters: None
Return type: None
**************************************************/
void OpMultiply::print() {
	std::cout << '*';
}

/**************************************************
Function name: is_operator()
Description: 
Parameters: None
Return type: bool
**************************************************/
bool OpMultiply::is_operator() {
	return true;
}

/**************************************************
Function name: evaluate_operator()
Description: evaluate
Parameters: None
Return type: result
**************************************************/
int OpMultiply::evaluate_operator( int param1, int param2 ) {
	return param1 * param2;
}

/**************************************************
Function name: OpDivide()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
OpDivide::OpDivide() {
	//std::cout << "OpDivide constructor called\t" << this << "\n";
}

/**************************************************
Function name: ~OpDivide()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
OpDivide::~OpDivide() {
	//std::cout << "OpDivide destructor called\t" << this << "\n";
}

/**************************************************
Function name: print()
Description: 
Parameters: None
Return type: None
**************************************************/
void OpDivide::print() {
	std::cout << '/';
}

/**************************************************
Function name: is_operator()
Description: 
Parameters: None
Return type: bool
**************************************************/
bool OpDivide::is_operator() {
	return true;
}

/**************************************************
Function name: evaluate_operator()
Description: evaluate
Parameters: None
Return type: result
**************************************************/
int OpDivide::evaluate_operator( int param1, int param2 ) {
	return param1 / param2;
}

/**************************************************
Function name: is_empty()
Description: 
Parameters: None
Return type: bool
**************************************************/
bool Tree::is_empty() {
	if ( this->root_node == NULL ) {
		return true;
	} else {
		return false;
	}
}

/**************************************************
Function name: Tree()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
Tree::Tree( Node *current, Tree *left, Tree *right ) {
	//std::cout << "Tree constructor called\t" << this << "\n";
	this->root_node = current;
	this->left_tree = left;
	this->right_tree = right;
}

/**************************************************
Function name: Tree()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
Tree::Tree( std::vector<Node *> prefix_expr ) {
	//std::cout << "Tree vector constructor called\t" << this << "\n";
	std::stack<Tree*> tree_stack;

	Node* current_node = NULL;
	Tree* operand1= NULL;
	Tree* operand2 = NULL;

	while (prefix_expr.empty() != true) {
		current_node = prefix_expr.back();
		prefix_expr.pop_back();

		if (current_node->is_operator() != true) {
			Tree* current_tree = new Tree(current_node);
			tree_stack.push(current_tree);
		} else {
			if (tree_stack.size() != 0) {
				operand1 = tree_stack.top();
				tree_stack.pop();
			}
			if (tree_stack.size() != 0){
				operand2 = tree_stack.top();
				tree_stack.pop();
			}
			//This is done because final node in stack and this node were pointing to the same tree,
			//and hence there was a memory leak.
			if ((prefix_expr.size()) == 0) {
				this->root_node = current_node;
				this->left_tree = operand1;
				this->right_tree = operand2;
			} else {
				Tree* new_tree = new Tree(current_node, operand1, operand2);
				tree_stack.push(new_tree);				
			}
		}
	}
}

/**************************************************
Function name: ~Tree()
Description: Destructor
Parameters: None
Return type: None
**************************************************/
Tree::~Tree() {
	//std::cout << "Tree destructor called\t" << this << "\n";	
	delete (this->root_node);
	delete (this->left_tree);
	delete (this->right_tree);
}

/**************************************************
Function name: print()
Description: print tree
Parameters: None
Return type: None
**************************************************/
//Inorder traversal is used
void Tree::print() {
    Node* current_node = NULL;
    if (this->left() != NULL ){
		if (this->right() != NULL) {
    		std::cout << '(';
		}
    	this->left_tree->print();
    }
	current_node = this->root_node;
	current_node->print();
    if (this->right() != NULL ){
    	this->right_tree->print();
		if (this->left() != NULL) {
    		std::cout << ')';
		}
    }
}

/**************************************************
Function name: left()
Description: returns left tree
Parameters: None
Return type: Pointer to left tree
**************************************************/
Tree* Tree::left(){
	return this->left_tree;
}

/**************************************************
Function name: right()
Description: returns right tree
Parameters: None
Return type: Pointer to right tree
**************************************************/
Tree* Tree::right(){
	return this->right_tree;
}

/**************************************************
Function name: evaluate()
Description: Constructor
Parameters: None
Return type: None
**************************************************/
void Tree::evaluate() {
    Node* current_node = NULL;
    int result = 0;
    
    current_node = this->root_node;
	if ( current_node->is_operator() == true ) {
		if((this->left_tree != NULL) && (this->left_tree->root_node->is_operator() == true)) {
			this->left_tree->evaluate();
		}
		if((this->right_tree != NULL) && (this->right_tree->root_node->is_operator() == true)) {
			this->right_tree->evaluate();
		}
		//check if they are literal or not
		if ((this->left_tree != NULL) && (this->right_tree != NULL) ) {
			if( (this->left_tree->root_node->is_literal_number() == true )  && 
				(this->right_tree->root_node->is_literal_number() == true ) ) {
					result = this->root_node->evaluate_operator(this->left_tree->root_node->get_value(), 
						this->right_tree->root_node->get_value()) ;

				Node* new_node = new Num(result);
				delete(this->left_tree);
				delete(this->right_tree);
				this->left_tree = NULL;
				this->right_tree = NULL;
				delete(this->root_node);
				this->root_node = new_node;
			}
		}
	} else {
		return;
	}	
}

/**************************************************
Function name: operator<<
Description: << operator overloading
Parameters: None
Return type: output stream
**************************************************/
std::ostream& operator<<( std::ostream& output, Tree& param ) {
	param.print();
	return output;
}
