/*
 * Both memcpy() and memmove() are producing the same outputs. I think in memcpy implementation they have 
 * taken care od address overlapping. Even though this is not mentioned in the man page.
 */

#include <iostream>
#include <cstring>
 
int main() {
    char str[] = "1234567890";
    std::cout << str << '\n';
    std::memcpy(str + 4, str + 3, 3); // copies from [4, 5, 6] to [5, 6, 7]
    std::cout << str << '\n';
}
