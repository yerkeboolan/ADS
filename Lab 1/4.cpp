#include <iostream>            
#include <utility>

	using namespace std;
		
		int a[111][111];
		int visited[111];

		void dfs(int n, int k) {
			visited[k] = 1;
			for(int i = 1; i <= n; i++) {
			if(i == k) continue;
			if(a[k][i] == 1 && visited[i] == 0) {
			dfs(n, i);
			}
			}
		return;
		}

	int main() {
		int n, m;
		cin >> n >> m;
		int arr[m][2];
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				a[i][j] = 0;
			}
		}

		for(int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}

		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
			for(int b = 1; b <= n; b++) {
				visited[b] = 0;
			}
			if(a[i][j] == 1) {
				a[i][j] = 0;
				dfs(n, i);
				a[i][j] = 1;
				for(int it = 1; it <= n; it++) {
					if(visited[it] == 0) {
						cout<< endl << i <<" "<<j;
					}

				break;
				}
			}
			}
		}

	return 0;
	}


	