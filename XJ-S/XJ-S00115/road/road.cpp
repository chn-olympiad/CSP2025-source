#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int head[N], net[N * 2], to[N * 2], n, m, k, u, v, w, sum;



int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		sum += w;
	}
	cout << sum;
	
	
	
	
	
	
	
	
	return 0;
}
