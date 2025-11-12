#include <bits/stdc++.h>

using namespace std;
int T, n;
const int N = 1e4;
int a1[N], a2[N], a3[N];
int m;
long long a;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			m = max(max(a1[i], a2[i]), a3[i]);
			a += m;

		}
		cout << " " << a;
	}

	return 0;
}
