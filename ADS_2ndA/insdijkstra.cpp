#include <iostream>

using namespace std;

int n, src, dest;
int a[1000][1000]; //adj matrix 

int used[1000];

int d[1000];

int main(){
	cin >> n >> src >> dest;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>> a[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		d[i] = INT_MAX;
		used[i] = 0;
	}
	d[src] = 0;
	for (int i = 0; i < n; i ++){
		int mini_d = INT_MAX;
		int u = -1;
		for (int j = 0; j < n; j++){
			if (d[j] < mini_d && used[i] == 0){
				mini_d = d[j];
				u = j;
			}
		}
		used[u] = 1;
		for (int v = 0; v < n; v++){
			if (a[u][v] > 0  && used[v] == 0 && d[u] != INT_MAX){
				if (d[u] + a[u][v] < d[v]){
					d[v] = d[u] + a[u][v];
				}
			}
		}
	}
	cout<<d[dest]<<endl;
	return 0;
}



3 2 1
0 1 1
4 0 1
2 1 0

