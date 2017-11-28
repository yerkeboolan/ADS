#include <iostream>
#include <vector>
#include <stack>
  
using namespace std;
  
  
int n, m;
vector<int> p[100110];
int col[100110];
stack<int> s;
vector<int> q;
bool ok = 0;

void dfs(int v){
	if(ok == 1) return;
	s.push(v);
	if(col[v] == 1){
		ok = 1;
		int d = s.top();
		s.pop();
		while(!s.empty() && s.top() != d){
			q.push_back(s.top());
			s.pop();
		}
		q.push_back(s.top());
		cout << "YES\n";     
		for(int i = q.size() - 1; i >= 0; i--)
			cout << q[i] << " ";
		return;
	}
	else col[v] = 1;
	for(int i = 0; i < p[v].size(); i++){
		int pt = p[v][i];
		dfs(pt);
	}
	col[v] = 2;
	if(!s.empty())s.pop();
}

int main(){
	cin >> n >> m;
	for(int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		p[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		if(ok == 1) break;
		if(col[i] == 0) dfs(i);
	}
	if(ok == 0)
		cout << "NO CYCLE\n";	
	return 0;
}           