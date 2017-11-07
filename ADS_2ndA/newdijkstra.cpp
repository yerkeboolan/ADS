#include <iostream>
#include <vector>

	using namespace std;

	void Dijkstra(int st) {
		vector<vector<int> > w;
		w.resize(n);
		for(int i = 0; i < n; i++) 
			w[i].resize(n);

	   	bool visited[n];
	   	int D[n];
	   	for(int i = 0; i < n; i++) {
	   		D[i] = w[st][i];
	   		visited[i] = false;
	   	}


	   	D[st] = 0;
	   	int index = 0, u = 0;

	   	for(int i = 0; i < n; i++) {
	   		int mini = INT_MAX;
	   		for(int j = 0; j < n; j++) {
	   			if(!visited[j] &&  D[j] < min) {
	   				min = D[j];
	   				index = j;
	   			}
	   		}
	   		u = index;
	   		visited[u] = true;
	   		for(int j = 0; j < n; j++) {
	   			if(!visited[j] && w[u][j] != INT_MAX && D[u] != INT_MAX && (D[u] + w[u][j] < D[j])) {
	   				D[j] = D[u] + w[u][j];
	   			}
	   		}
	   	}

	cout << "Cost: \t\n";
	for(int i = 0; i < n; i++) {
		if(D[i] != INT_MAX)
			cout << st<<" ->"<<i<<" = "<<D[i]<<endl;
		else
			cout<< st<<" -> "<<i<<" = "<<"no path"<<endl;
	}
	}


    


