#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long u[N], v[N], w[N];
long long c[15], a[15][10005], b[15];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k;
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i ++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (long long i = 1; i <= k; i ++) {
		cin >> c[i];
		b[i] = c[i];
		for (long long j = 1; j <= n; j ++) {
			cin >> a[i][j];
			b[i] += a[i][j];
		}
	}
	long long sum = 0;
	for (long long i = 1; i <= m; i ++) {
		sum += w[i];
	}
	if (k == 0) {
		cout << sum << '\n';
		return 0;
	}
	else {
		for (long long i =1; i <= k; i ++) {
			sum = min(sum, b[i]);
		} 
		cout << sum << '\n';
	}
	return 0;
}