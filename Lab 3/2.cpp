#include <iostream>
#include <vector>
#include <map>
     
using namespace std;
 
 
int n, m;
int used[10000];
vector<int> p[10000];
int cnt, components, bridges;

vector<pair<int, int> > edges;
map<pair<int, int>, int> zapret;

	void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < p[v].size(); i++){
		int pt = p[v][i];
		if(!used[pt] && zapret[make_pair(v, pt)]!=1 && zapret[make_pair(pt, v)] != 1) dfs(pt);
	}
}
int main(){  
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
    	cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
        edges.push_back(make_pair(u, v));
    }
    for(int i = 1; i <= n; i++)
        if(!used[i]){
        	dfs(i);
        	components++;
        }
    for(int i = 0; i < edges.size(); i++){
    	zapret[make_pair(edges[i].first, edges[i].second)] = 1;
    	for(int j = 1; j <= n; j++) used[j] = 0;
    	cnt = 0;
    	for(int j = 1; j <= n; j++){
    		if(!used[j]){
    			dfs(j);
    			cnt++;
    		}
    	}
    	if(cnt > components) bridges++;
    	zapret[make_pair(edges[i].first, edges[i].second)] = 0;
    }
    cout << m - bridges << endl;
    return 0;
}  