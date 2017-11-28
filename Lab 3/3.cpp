#include <iostream>
#include <vector>
     
using namespace std;
  
	int n, s, b;
	const int inf = 1000000000;
	int a[111][111];
	int d[111], used[111], p[111];
int main() {  
    cin >> n >> s >> b;
    for(int i = 1; i <= n; i++)
    d[i] = inf;
    d[s] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    for(int it = 0; it < n; it++){
        int v = -1;
        for(int i = 1; i <= n; i++)
            if(!used[i] && (v == -1 || d[v] > d[i]))
                v = i;
        used[v] = 1;
        if(d[v] == inf) break;
        for(int i = 1; i <= n; i++)
            if(a[v][i] != -1 && d[v] + a[v][i] < d[i]){
                d[i] = d[v] + a[v][i];
                p[i] = v;
            }
    }
    vector<int> ans;
 
    if(d[b] == inf){
        cout << -1 << endl;
        return 0;
    }
    cout << d[b] << endl;
 
    return 0;
}