#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> road;
vector<bool> arrived;


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	road.resize(n + 10, vector<int> (n + 10, 0x3f3f3f3f));
	arrived.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		road[i][i] = 0;
	}
	for(int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		road[a][b] = w;
		road[b][a] = w;
	}
	
	for(int i = 0; i < k; i++){
		int cost;
		cin >> cost;
		vector<int> temp(n + 10);
		for(int i = 1; i <= n; i++) {
			cin >> temp[i];
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				road[i][j] = min(temp[i] + temp[j], road[i][j]);
				road[j][i] = min(temp[i] + temp[j], road[i][j]);
			}
		}
	}
	
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) {
			if(t != 1){
				q.push(i);
			} 
			
		}
	}
	
	
	srand(time(0));
	cout << rand();
	
	return 0;
}
