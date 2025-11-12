#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n, m, k;
int a, b, c;

int main() {
	fast;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	int h = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		h += c;
	}
	cout << h;
	return 0;
}