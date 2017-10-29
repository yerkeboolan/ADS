#include <iostream>
using namespace std;

int visited[100000];
int a[10000][10000];
void dfs( int n, int k){
	visited[k] = 1;
	for (int i = 1; i <=n; i++){
	if (i == k){
		continue;
}
if (a[k][i] == 1 && visited[i] == 0){
	
	dfs(n, i);
}
}
return;
} 

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		visited[i] = 0;
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	int v, u;
	cin>>v>>u;
	dfs(n, v);
	if(visited[u]==1){
		cout<<"POLTOS";
	}
	else cout<<"DAUREN";
	return 0;
}
