#include <iostream>

	using namespace std;
	int used[1001];
	
	int n;
	int a[1001][1001];
	int parent[1001];
	int cnt = 0;


	void isBipartite(int v, int i) {
		while(v > 0 && v != i) {
			cnt++;
			v = parent[v];
		}
	}


	void dfs(int v) {
		used[v] = 1;
		for(int i = 1; i <= n; i++) {
			if(i == parent[v])
				continue;
			if(used[i] == 0 && a[v][i] == 1) {
				parent[i] = v;
				dfs(i);
			}

			else if(a[v][i] == 1 && used[i] == 1) {
				isBipartite(v, i);
				break;
			}

		}


		return;
	}


	int main() {
	  	cin >> n;
	  	for(int i = 1; i <= n; i++)  {
	  		used[i] = 0;
	  		for(int j = 1; j <= n; j++) {
	  			cin >> a[i][j];
	  		}
	  	}
	dfs(1);
	if(cnt % 2 == 0) 	cout<< "BIPARTITE";
	else cout <<"NOPARTITE";

	return 0;
	}


	