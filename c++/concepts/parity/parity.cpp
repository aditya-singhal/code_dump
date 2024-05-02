#include <iostream>

using namespace std;


// The number has “odd parity” if it contains an odd number of 1-bits and is “even parity” if it contains an even number of 1-bits. 

// returns 1: for even parity
// returns 0: for odd parity

int get_parity(uint32_t num) {
    int count = 0 ;

    for(int i = 0; i<32; i++) {
        if ((num & 0x01) == 0x01) {
            count++;
        }
        num = num >> 1;
    }

    return ((count % 2) == 0) ? 1 : 0;
}

int main() {
    cout<<"Parity of no "<< 7 <<" = "<< (get_parity(7) ? "even": "odd") << endl;
    cout<<"Parity of no "<< 13 <<" = "<<(get_parity(13)? "even": "odd") << endl;
    cout<<"Parity of no "<< 12 <<" = "<<(get_parity(12)? "even": "odd") << endl;
    cout<<"Parity of no "<< 8 <<" = "<<(get_parity(8)? "even": "odd") << endl;
    cout<<"Parity of no "<< 0 <<" = "<<(get_parity(0)? "even": "odd") << endl;
     
    return 0;
}