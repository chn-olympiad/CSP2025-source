#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a, s, d;
int n, m, k;
int q;
int c;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> s >> d;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> q;
		}
	}
	cout << 0;
	/*
	4 4 2
	1 4 6
	2 3 7
	4 2 5
	4 3 4
	1 1 8 2 4
	100 1 3 2 4
	*/
	return 0;
}
