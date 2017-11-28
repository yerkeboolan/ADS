#include <iostream>
#include <algorithm>
     
using namespace std;
 
   
int n, m;
int a[111][111];
const int inf = 1000000000;
int main() {  
    cin >> n;
         
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[k][j] + a[i][k]);
    int maxi = -inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            if(a[i][j] != inf)
                maxi = max(maxi, a[i][j]);
    }
    cout << maxi << endl;
    return 0;
}