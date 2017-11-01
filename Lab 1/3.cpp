#include <iostream>

	using namespace std;

	int a[111][111];
	int used[111];
	
	void DFS(int n, int t) {
		used[t] = 1;
		for(int i = 1; i <= n; i++) {
			if(i == t) continue;
			if(a[t][i] == 1 && used[i] == 0) {
				DFS(n, i);
			}
			}
	 return;
	}
	

	int main() {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			used[i] = 0;
			for(int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		int v, u;
		cin >> v >> u;
		DFS(n, v);
		if(used[u] == 1)  cout<<"POLTOS";
		else cout <<"DAUREN";
		



   	return 0;
   	}








			
	
	





	
		
		