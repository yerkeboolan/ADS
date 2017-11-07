#include <iostream>


using namespace std;

	int n, m;
	bool used[200][200];
	char c[200][200];


	void dfs(int x, int y) {
		if(x < 0 || y < 0 || x >= n || y >= m) 
			return;
		if(c[x][y] == '.') 
			return;
		if(used[x][y]) 
			return;

	   	used[x][y] = true;
	   	dfs(x + 1, y);
	   	dfs(x, y + 1);
	   	dfs(x - 1, y);
	   	dfs(x, y - 1);
   	}


   	int main() { 
   		cin >> n >> m;

   		for(int i = 0; i < n; i++) {
   			for(int j = 0; j < m; j++) {
   				cin >> c[i][j];
   			}
   		}


   		int cnt = 0;

   		for(int i = 0; i < n; i++) {
   			for(int j = 0; j < m; j++) {
   				if(!used[i][j] && c[i][j] == '#') {
   					dfs(i, j);
   					cnt++;
   				}
   			}
   		}

   		cout << cnt;

   		return 0;

}


