#include <iostream>
#include <deque> 
using namespace std;

//arr: array data
//n: number of elements in the array
//k: number of elements to group

void printKMax(int arr[], int n, int k) {
	deque<int> max_deque;
    int index = 0;
    int max_value = 1;
    int front_value = 1;
    deque<int>::iterator itr;
    
    while(index <= (n-k)) {
        if (index == 0) {
            for( int count=0; count < k; count++ ) {
                max_deque.push_back(arr[count]);
            }
        } else {
            max_deque.push_back(arr[index+k-1]);
        }
        //find max value in the queue
        //Checking if the front value was the maximum
        //value, then recalculate the max value.
        if ( front_value == max_value) {
            max_value = 1;
            for (itr = max_deque.begin(); itr != max_deque.end(); ++itr) {
                if (*itr > max_value) {
                    max_value = *itr;
                }
            }
        } else {
            if (max_value <= max_deque.back() ){
                max_value = max_deque.back();
            }
        }

        cout << max_value << " ";
        front_value = max_deque.front();
        max_deque.pop_front();
        index++;
    }
    cout << "\n";
}

int main() {
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++) {
            cin >> arr[i];
        }
    
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}