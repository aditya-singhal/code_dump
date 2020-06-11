#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
public:
    vector<vector<int> > a;

    Matrix operator +(Matrix x2) {
        Matrix result;

        int total_rows_x1 = this->a.size();
        int total_columns_x1 = this->a[0].size();
        int total_rows_x2 = x2.a.size();
        int total_columns_x2 = x2.a[0].size();

        result.a.resize(total_rows_x1);
        for (int i=0; i<total_rows_x2; i++) {
            for (int j=0; j<total_columns_x2; j++) {
                result.a[i].push_back( this->a[i][j] + x2.a[i][j] );
            }
        }
        return result;
    }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
