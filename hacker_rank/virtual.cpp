#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    std::string name;
    int age;
    virtual void getdata(){
        cin >> name;
        cin >> age;
    }
    virtual void putdata(){
        cout << name << " " << age << " ";
    }
};

class Professor : public Person {
    int publications;
    int cur_id;
    static int count;
public:
    Professor() {
        count++;
        cur_id = count;
    }
    void getdata(){
        Person::getdata();
        cin >> publications;
    }
    void putdata() {
        Person::putdata();
        cout << publications << " " << cur_id << "\n";
    }
};

class Student : public Person {
    int cur_id;
    static int count;
    std::vector<int> marks;
public:    
    Student():marks(6) {
        count++;
        cur_id = count;
    }
    void getdata() {
        Person::getdata();
        for (int i=0 ; i<6 ; i++){
            cin >> marks[i];
        }
    }
    void putdata() {
        Person::putdata();
        for (int i=1 ; i<6 ; i++){
            marks[0] += marks[i];
        }   
        cout << marks[0] << " " << cur_id << "\n";
    }
};

int Professor::count = 0;
int Student::count= 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
