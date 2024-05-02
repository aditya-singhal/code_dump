#include "exp_trees.h"

int main()
{
	Tree t1(new OpPlus);
	Tree t2(new OpPlus, new Tree(new Num(1)) );
	Tree t3(new Num(5), new Tree(new OpMinus) );
	Tree t4(new OpPlus, new Tree(new Num(1)), new Tree(new Num(2)) );
    Tree t5(new OpPlus, new Tree(new Num(1)),	\
    	new Tree(new OpMultiply, new Tree(new Num(2)), new Tree(new Num(3))));
	
	std::vector<Node *> expr1 = { new OpMultiply,
									 new OpMinus,
									 new Variable("A"),
									 new OpDivide,
									 new Variable("B"),
									 new Variable("C"),
									 new OpMinus,
									 new OpDivide,
									 new Variable("A"),
									 new Variable("K"),
									 new Variable("L")};

	Tree t6(expr1);
	
	std::vector<Node *> expr2 = {new OpPlus,
									new Num(1),
									new OpMultiply,
									new Variable("a"),
									new Num(3) };

	Tree t7(expr2);

	std::vector<Node *> expr3 = {new OpPlus,
									new OpPlus,
									new Num(7),
									new OpMultiply,
									new Num(6),
									new Num(2),
									new Num(6) };

	Tree t8(expr3);
  
  	std::vector<Node *> expr4 = {new OpPlus
								  , new OpPlus
								  , new OpPlus
								  , new Variable("a")
								  , new Num(1)
								  , new Num(2)
								  , new OpMinus
								  , new OpMultiply
								  , new Variable("b")
								  , new OpMultiply
								  , new Num(2)
								  , new Num(3)
								  , new Variable("a") };

	Tree t9(expr4);

    std::cout << "before: " << t1 << "\n";
    std::cout << "before: " << t2 << "\n";    
    std::cout << "before: " << t3 << "\n";
    std::cout << "before: " << t4 << "\n";
	std::cout << "before: " << t5 << "\n";
	std::cout << "before: " << t6 << "\n";
	std::cout << "before: " << t7 << "\n";
	std::cout << "before: " << t8 << "\n";
	std::cout << "before: " << t9 << "\n";
	
	t1.evaluate();
	std::cout << "after evaluate: "<< t1 << "\n";
	t2.evaluate();
	std::cout << "after evaluate: "<< t2 << "\n";
	t3.evaluate();
	std::cout << "after evaluate: "<< t3 << "\n";
	t4.evaluate();
	std::cout << "after evaluate: "<< t4 << "\n";
	t5.evaluate();
	std::cout << "after evaluate: "<< t5 << "\n";
	t6.evaluate();	
	std::cout << "after evaluate: "<< t6 << "\n";
	t7.evaluate();	
	std::cout << "after evaluate: "<< t7 << "\n";
	t8.evaluate();
	std::cout << "after evaluate: "<< t8 << "\n";
	t9.evaluate();
	std::cout << "after evaluate: "<< t9 << "\n";

	return 0;
}
