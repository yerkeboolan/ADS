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
			
		