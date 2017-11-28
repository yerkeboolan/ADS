#include <iostream>
#include <queue>
#include <utility>

	using namespace std;
	int n = 8
	int m = 8;
	char a[10000][10000];
	queue<pair <int, int> > myQueue;
	map<pair<int, int>, int> level;
	int k = 0;
	void bfs(int i, int j){
	a[i][j] = 1;
	int l = level[make_pair(i, j);
	if (j > 1 && i < n - 1 && a[i + 1][j - 2] == 0 ){
		a[i+1][j - 2] = 1;
		myQueue.push(make_pair(i + 1, j - 2));
		level[make_pair(i + 1, j - 2)] = l + 1;
	}
	if (j < n - 2 && i < n - 1 && a[i + 1][j + 2] == 0 ){
		a[i+1][j + 2] = 1;
		myQueue.push(make_pair(i + 1, j + 2));
	}
if (j < n - 2 && i > 1 && a[i - 1][j + 2] == 0 ){
		a[i+1][j + 2] = 1;
		myQueue.push(make_pair(i - 1, j + 2));
	}
if (j > 2 && i > 1 && a[i - 1][j - 2] == 0 ){
		a[i - 1][j - 2] = 1;
		myQueue.push(make_pair(i - 1, j - 2));
	}

if (j > 0 && i < n - 2 && a[i + 2][j - 1] == 0 ){
		a[i+2][j - 1] = 1;
		myQueue.push(make_pair(i + 2, j - 1));
	}
	if (j < n - 1 && i < n - 2 && a[i + 2][j + 1] == 0 ){
		a[i+2][j + 1] = 1;
		myQueue.push(make_pair(i + 2, j + 1));
	}
if (j  > 0 && i > 1 && a[i - 2][j - 1] == 0 ){
		a[i - 2][j - 1] = 1;
		myQueue.push(make_pair(i - 2, j - 1));
	}
if (j < n - 1 && i > 1 && a[i - 2][j  + 1] == 0 ){
		a[i - 2][j + 1] = 1;
		myQueue.push(make_pair(i - 2, j + 1));
	}

	}

int main(){
	freopen("a.txt", "r", stdin);
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			a[i][j] = 0;
		}
	}
	int a1, b1;
	cin >> a1 >> b1;
	int a2, b2;
	cin >> a2 >> b2;
	int comp = 0;
	myQueue.push(make_pair(a1, b1));
	level< make_pair(a1, b1) > = 0;
	while (!myQueue.empty()){
		pair<int, int> temp = myQueue.front();
		myQueue.pop();
		bfs(temp.first, temp.second);
	}
cout << comp << endl;
	return 0;
}

