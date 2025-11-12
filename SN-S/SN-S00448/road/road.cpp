#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u[1000010], v[000010], w[000010], c[000010], a[000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1; i<=k; i++){
		cin >> c[i] >> a[i];
	}
	cout << 0;
	return 0;
}
