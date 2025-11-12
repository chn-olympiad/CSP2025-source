#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define reg(i, x, y, step) for (int i = x; i <= y; i += step)
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e2 + 10;
int n, m, a[N];
int val;
signed main() {
	File("seat");
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	val = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	int cur = 0;
	for (int i = 1; i <= m; i++) {
		if (i & 1) {
			for (int j = 1; j <= n; j++)
				if (a[++cur] == val) {
					cout << i << " " << j;
					return 0;
				}
		} else {
			for (int j = n; j >= 1; j--)
				if (a[++cur] == val) {
					cout << i << " " << j;
					return 0;
				}
		}
	}
	return 0;
}
