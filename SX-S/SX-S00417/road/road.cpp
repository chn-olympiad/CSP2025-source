#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10, B = 1e4+10;

struct st {
	int a;
	int b;
	int c;
} x[N];
int l[B], v[15][B];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k, s = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x[i].a >> x[i].b >> x[i].c;
		s = s + x[i].c;
	}
	for (int i = 1; i <= k; i++) {
		cin >> l[i];
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	cout << s;
	return 0;
}
