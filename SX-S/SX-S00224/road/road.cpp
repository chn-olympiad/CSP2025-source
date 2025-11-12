#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int c1[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k, a, c, b, s = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		s = s + c;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c1[i];
	}
	cout << s;
	return 0;
}