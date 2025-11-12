#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int u[N] , v[N] , w[N] , b[15][N] , c[15];
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	long long s = 0;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		s += w[i];
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> b[i][j];
		}
	}
	cout << s;
	return 0;
}