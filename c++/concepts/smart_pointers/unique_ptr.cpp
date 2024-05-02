#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class my_unique_ptr {
private:
    T* ptr;

public:
    my_unique_ptr(T* temp_ptr) {
        cout << "constructor invoked" << endl;
        ptr = temp_ptr;
    }
    ~my_unique_ptr() {
        cout << "destructor invoked" << endl;
        free(ptr);
    }

    T& operator* () {
        return *(this->ptr);
    }

    // This will be used to call any member class function of the object class
    T* operator-> () {
        return (this->ptr);
    }

    // Deleting the default copy constructor and assignment operators so that user cannot
    // use them to create another unique_ptr pointing to same memory
    // This feature is available after c++17
    my_unique_ptr(my_unique_ptr &ptr) = delete;
    my_unique_ptr operator = (my_unique_ptr &ptr) = delete;
};

int main() {
    my_unique_ptr<int> u1(new int(5));
    cout << *u1 << endl;

    return 0;
}
