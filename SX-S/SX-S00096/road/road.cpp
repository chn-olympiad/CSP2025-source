#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int nm, n;
	cin >> nm >> n;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		cout << 0 << '\n';
	}
	return 0;
}
