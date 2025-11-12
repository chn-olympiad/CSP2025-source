#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, m, k;
int u[N], v[N], w[N]; 
int a[N][N], c[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1;j <= k;j++){
		cin >> c[j];
		for (int i = 1;i <= n;i++){
			cin >> a[j][i];
		}
	}
	//嘟哒哒嘟嘟哒~
	//kkksc03, chen_zhe~
	cout << n * m - k;
	return 0;
}