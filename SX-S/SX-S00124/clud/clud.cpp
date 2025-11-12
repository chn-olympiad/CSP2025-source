#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e6+100;
const int MaxN = 1e9;
int ai = 0, bi = 0, ci = 0;
int t[4];

struct XXX {
	int min, max, mi; //min:²î×îÐ¡ mai£ºmaxi
} a[500005];

bool cmp(XXX x, XXX y) {
	return x.min < y.min;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, sum = 0;
		cin >> n;
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++) {
			int maxn = -1;
			int x, y, z;
			cin >> x >> y >> z;
			maxn = max(x, maxn);
			maxn = max(y, maxn);
			maxn = max(z, maxn);
			a[i].max = maxn;
			if (maxn == x) {
				a[i].min =  max(y, z) - maxn;
				a[i].mi = 1;
			} else if (maxn == y) {
				a[i].min =  max(x, z) - maxn;
				a[i].mi = 2;
			} else {
				a[i].min =  max(x, y) - maxn;
				a[i].mi = 3;
			}
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (t[a[i].mi] == n / 2) {
				sum += a[i].max + a[i].min;
			} else {
				sum += a[i].max;
				t[a[i].mi]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}