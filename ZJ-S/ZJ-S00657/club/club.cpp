#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
#define Sz(v) ((int)(v).size())
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, a[N][3];
vector<int> vc[3]; 
void Clear() {
	FL(i, 0, 2) {
		vc[i].clear();
	}
}
void Solve() {
	scanf("%d", &n);
	FL(i, 1, n) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	ll ans = 0;
	FL(i, 1, n) {
		int m = max({a[i][0], a[i][1], a[i][2]});
		ans += m;
		if (a[i][0] == m) {
			vc[0].emplace_back(i);
		} else if (a[i][1] == m) {
			vc[1].emplace_back(i);
		} else {
			vc[2].emplace_back(i);
		}
	}
	FL(c, 0, 2) {
		if (Sz(vc[c]) <= n / 2) continue;
		int y, z;
		if (c == 0) {
			y = 1, z = 2;
		} else if (c == 1) {
			y = 0, z = 2;
		} else {
			y = 0, z = 1;
		}
		vector<int> w;
		for (int x: vc[c]) {
			w.emplace_back(a[x][c] - max(a[x][y], a[x][z]));
		}
		sort(w.begin(), w.end(), greater<int>());
		while (Sz(w) > n / 2) {
			ans -= w.back();
			w.pop_back();
		}
		break;
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		Solve();
		Clear();
	}
	return 0;
}
