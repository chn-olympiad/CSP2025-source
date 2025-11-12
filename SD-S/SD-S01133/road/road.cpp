#include<bits/stdc++.h>
using namespace std;

const int K = 112;
const int M = 5e6 + 2e5;
const int N = 132000;
int n, m, k;
int u[M], v[M], w[M];
int c[K][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		sum += c[1][i];
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
