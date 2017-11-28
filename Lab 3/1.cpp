#include <iostream>
#include <vector>
#include <map>
     
using namespace std;
    
int n, m;
int used[10000];
vector<int> p[10000];
int cnt, components, cut_points;
map<int, int> zapret;
	 void dfs(int v){
		used[v] = 1;
		for(int i = 0; i < p[v].size(); i++){
		int pt = p[v][i];
		if(!used[pt] && zapret[pt] != 1)
			 dfs(pt);
	}
}
	vector<int> ans;
	int main(){  
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!used[i]){
        	dfs(i);
        	components++;
        }
    for(int i = 1; i <= n; i++){
    	zapret[i] = 1;
    	for(int j = 1; j <= n; j++) used[j] = 0;
    	cnt = 0;
    	for(int j = 1; j <= n; j++){
    		if(!used[j] && j != i){
    			dfs(j);
    			cnt++;
    		}
    	}
    	if(cnt > components){
    		cut_points++;
    		ans.push_back(i);
    	}
    	zapret[i] = 0;
    }
    cout << cut_points << endl;
    for(int i = 0; i < ans.size(); i++) 
    	cout << ans[i] << " ";
    return 0;
}  