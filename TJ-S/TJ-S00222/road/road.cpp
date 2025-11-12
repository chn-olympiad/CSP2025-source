#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int t[100010];
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int a, b, c, num = 0;
	cin >> a >> b >> c;
	for (int i = 1; i <= b; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		t[i] = z;
	}
	sort (t + 1, t + b + 1);
	for (int i = 1; i < a; i++) {
		num += t[i];
	}
	cout << num;
	return 0;
}

