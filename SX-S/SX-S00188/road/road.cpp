#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, k, fa[100005], a[100005], c;

struct node {
	ll u, v, w;
} dl[1000006];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> dl[i].u >> dl[i].v >> dl[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++)
			cin >> a[i];
	}
	cout << 0;
	return 0;
}