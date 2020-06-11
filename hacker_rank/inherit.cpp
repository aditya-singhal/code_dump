#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A constructor called\n";
        callA = 0;
    }
private:
    int callA;
    void inc() {
        callA++;
    }

protected:
    void func(int & a) {
        a = a * 2;
        inc();
    }
public:
    int getA(){
        return callA;
    }
};

class B {
public:
    B(){
        cout << "B constructor called\n";
        callB = 0;
    }
private:
    int callB;
    void inc(){
        callB++;
    }
protected:
    void func(int & a) {
        a = a * 3;
        inc();
    }
public:
    int getB() {
        return callB;
    }
};

class C {
public:
    C(){
        cout << "C constructor called\n";
        callC = 0;
    }
private:
    int callC;
    void inc(){
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC(){
        return callC;
    }
};

class D : public A, public B, public C {
int val;
public:
    //Initially val is 1
    D() {
        cout << "D constructor called\n";
        val = 1;
    }

    void update_val(int new_val) {
        int remainder = 0;
        int factor_array[3] = {2, 3, 5};
        int factor_count[3] = {0};
        int index = 0;
        
        while (index < 3) {
            remainder = 0;
            while (remainder == 0 ) {
                remainder = new_val % factor_array[index];
                if ( remainder == 0 ) {
                    new_val = new_val/factor_array[index];
                    factor_count[index]++;
                } else {
                    break;
                }
            }
            index++;
        }

        index = 0;
        while (index < 3) {
            while( factor_count[index] != 0 ) {
                switch(factor_array[index]){
                    case 2:
                    A::func(val);
                    break;
                    
                    case 3:
                    B::func(val);
                    break;
                    
                    case 5:
                    C::func(val);
                    break;
                }

                factor_count[index]--;
            }
            index++;
        }
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val) {
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main() {
    D d;
    int new_val;
    cout << " Enter value: "; 
    cin >> new_val;
    d.check(new_val);
}