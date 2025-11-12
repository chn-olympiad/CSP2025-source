#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n, m, k, a, b, ma[10000][10000];
ll sum;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		cin >> a >> b >> ma[a][b];
		sum+=ma[a][b];
	}
	cout<<sum;
	return 0;
}
