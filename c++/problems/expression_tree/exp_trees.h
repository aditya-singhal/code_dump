#ifndef __EXP_TREES_H__
#define __EXP_TREES_H__

// Todo: handle unary operators
// Note: right branch for unary operators is NULL

#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Node {
public:
    Node();
    virtual ~Node();
    virtual void print() = 0;
    virtual bool is_operator() { return false; };
    virtual bool is_literal_number(){ return false; };
    virtual int evaluate_operator( int param1, int param2 ){return 0;};
    virtual int get_value(){ return 0;}
    virtual void set_value(int){};
};

class Num : public Node {
private:
    int number;

public:
    Num( int number );
    ~Num();
    void print();
    int get_value();
    void set_value( int value );
    bool is_operator();
    bool is_literal_number();
};

class Variable : public Node {
private:    
    std::string variable;

public:
    Variable( std::string variable );
    ~Variable();
    void print();
    bool is_operator();
};

class OpPlus : public Node {
public: 
    OpPlus();
    ~OpPlus();
    void print();
    bool is_operator();
    int evaluate_operator( int param1, int param2 );
};

class OpMinus : public Node {
public:
    OpMinus();
    ~OpMinus();
    void print();
    bool is_operator();
    int evaluate_operator( int param1, int param2 );
};

class OpMultiply : public Node {
public:
    OpMultiply();
    ~OpMultiply();
    void print();
    bool is_operator();
    int evaluate_operator( int param1, int param2 );
};

class OpDivide : public Node {
public:
    OpDivide();
    ~OpDivide();
    void print();
    bool is_operator();
    int evaluate_operator( int param1, int param2 );
};

class Tree {
private:
    bool is_empty();
    Node* root_node;
    class Tree* left_tree;
    class Tree* right_tree;
    void print();
public:
    Tree( Node *current, Tree *left = NULL, Tree *right = NULL );
    Tree( std::vector<Node *> prefix_expr );
    ~Tree();
    Tree *left();   // Return left branch, NULL if empty
    Tree *right();  // Return right branch, NULL if empty
    void evaluate();
    friend std::ostream& operator<<( std::ostream& output, Tree& param );
};

#endif
