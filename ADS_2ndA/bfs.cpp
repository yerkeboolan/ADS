#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n, m;
char a[10000][10000];
queue<pair <int, int> > myQueue;

void bfs(int i, int j){
	a[i][j] = '@';
	if (j > 0 && a[i][j - 1] == '#' ){
		a[i][j - 1] = '@';
		myQueue.push(make_pair(i, j - 1));
	}
	if (i > 0  && a[i - 1][j] == '#' ){
		a[i - 1][j] = '@';
		myQueue.push(make_pair(i - 1, j ));
	}
	if (j < m - 1 && a[i][j + 1] == '#'){
		a[i][j + 1] = '@';
		myQueue.push(make_pair(i, j  + 1));
	}
	if (i < n - 1 && a[i + 1][j] == '#'){
		a[i + 1][j] = '@';
		myQueue.push(make_pair(i + 1, j));
	}
}

int main(){
	freopen("a.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			cout << a[i][j] << " ";
		}
		cout<< endl;
	}
	int comp = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '#'){
				comp++;
				myQueue.push(make_pair(i, j));
				cout << i << " " << j << endl;
				while (!myQueue.empty()){
					pair<int, int> temp = myQueue.front();
					myQueue.pop();
					bfs(temp.first, temp.second);
				}
			}
		}
	}
	cout << comp << endl;
	return 0;
}


