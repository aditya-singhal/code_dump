#include "overloading.h"

custom_int::custom_int() {
    cout << "custom_int() called" << endl;
    this->data = 0;
}

custom_int::custom_int(int val) {
    cout << "custom_int(int) called: " << val << endl;
    this->data = val;
}

custom_int custom_int::operator+ (const custom_int& param) {
    custom_int output;
    output.data = this->data + param.data;

    return output;
}

// custom_int custom_int::operator+ (int param1, const custom_int& param2) {
//     custom_int output;
//     output.data = param1 + param2.data;

//     return output;
// }

custom_int custom_int::operator+ (int param) {
    custom_int output;
    output.data = this->data + param;

    return output;
}

custom_int& custom_int::operator= (const custom_int& param) {
    this->data = param.data;
    return *this;
}

custom_int& custom_int::operator+= (const custom_int& param) {
    this->data = this->data + param.data;
    return *this;
}

custom_int& custom_int::operator<< (const custom_int& param) {
    this->data = this->data << param.data;
    return *this;
}

void custom_int::print() {
    cout << "value: " << this->data << endl;
}

custom_int::operator int() const {
	return this->data;
}

int main() {
    custom_int a(1);
    custom_int b(2);
    custom_int c(3);
    custom_int d;

    d = a + b + c;
    d.print();  // output: 6

    d += a;
    d.print();  // output: 7

    d = c << a;
    d.print();  // output: 6

    b = 5 + a;
    b.print();  // output: 6

    return 0;
}