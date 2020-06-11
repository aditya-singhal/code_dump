#include "hello.h"

int main() {
    int value = 200;

    hello h1;
    second_namespace::hello h2;

    std::cout << "h1: " << h1.value << "\n";
    std::cout << "first_namespace:: " << first_namespace::value << "\n";
    //std::cout << "second_namespace::hello: " << h2.value << '\n';  
    std::cout << "global value: " << ::value << '\n';
    std::cout << "local value: " << value << '\n';
  
    return 0; 
} 
