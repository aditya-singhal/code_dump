#include <iostream>

using namespace std;

// Seg fault is coming right now, correct this

template <typename T>
class my_shared_ptr {
private:
    T* ptr;
    int* resource_count;

public:
    my_shared_ptr(T* temp_ptr = nullptr) {
        cout << "constructor invoked" << endl;
        ptr = temp_ptr;
        resource_count = new int();
        resource_count++;
    }
    ~my_shared_ptr() {
        if (*resource_count == 0) {
            cout << "destroying allocated memory" << endl;
            free(ptr);
        } else {
            cout << "decreasing resource count" << endl;
            (*resource_count)--;
        }
    }

    T operator* () {
        return *(this->ptr);
    }

    // This will be used to call any member class function of the object class
    T* operator-> () {
        return (this->ptr);
    }

    // copy constructor
    my_shared_ptr(const my_shared_ptr &temp_ptr) {
        this->ptr = temp_ptr.ptr;
        this->resource_count = temp_ptr.resource_count;
        (*resource_count)++;
    }

    // assignement operator overload
    my_shared_ptr& operator= (const my_shared_ptr &temp_ptr) {
        if (this != &temp_ptr) {
            this->ptr = temp_ptr.ptr;
            this->resource_count = temp_ptr.resource_count;
            (*resource_count)++;
        }
        return *this;
    }

    void print_count() {
        cout << "resource_count: " << *resource_count << endl;
    }

    // move constructor
    my_shared_ptr(my_shared_ptr &&sp) {
        // don't increase usage count 
        this->ptr = sp.ptr;
        this->resource_count = sp.resource_count;
        sp.ptr = nullptr;
        sp.resource_count = nullptr;
    }

    my_shared_ptr& operator= (my_shared_ptr &&sp) {
        // don't increase usage count 
        this->ptr = sp.ptr;
        this->resource_count = sp.resource_count;
        sp.ptr = nullptr;
        sp.resource_count = nullptr;
        return *this;
    }
};

int main() {
    my_shared_ptr<int> u1(new int(5));
    my_shared_ptr<int> u2 = u1;
    my_shared_ptr<int> u3;
    u3 = u1;

    cout << *u1 << endl;
    cout << *u2 << endl;
    cout << *u3 << endl;
    u3.print_count();

    my_shared_ptr<int> u4(new int(6));

    cout << *u4 << endl;
    u4.print_count();

    u4 = move(u3);

    return 0;
}