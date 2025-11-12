#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > aa;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		aa[a][b] = c;
		aa[b][a] = c;
	}
	return 0;
} 
