#include <iostream>
#include <vector>

using namespace std;

	bool ifound = false;
	       
	int s, t;
	int used[1111];
	int n;
	vector<int> path;	
	int a[100][100];


	void DFS(int v) {
	used[v] = 1;
	path.push_back(v);
	for (int i = 1; i <= n; ++i) {
	if (ifound) return;
		if (a[i][v] && !used[i]) {
			if (i == t) {
				ifound = true;
				path.push_back(i);
				used[t] = 1;
				return;
			}
			DFS(i);
			if (!ifound) path.push_back(v);
		}
	}
}


	int main() {

		cin >> n;
		for(int i = 1; i <= n; i++) {
			used[i] = 0;
			for(int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}

		
		cin >>  s>> t;
		DFS(s);
		if(used[t] == 1) {
		
		cout<<"POLTOS"<<endl;
		for(int i = 0; i < path.size(); i++) {
			cout << path[i] << " ";
			}
		}
		else cout <<"DAUREN";
		return 0;
	}
