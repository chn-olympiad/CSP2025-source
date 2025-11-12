#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
int n, m, r, a[400], x, y, t;
bool cmp(int a, int b) { return a > b; }
signed main() {
	iosfst;
	File("seat");
	cin >> n >> m;
	rep (i, 1, n * m) cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	x = 0, y = 1, t = 1;
	rep (i, 1, n * m) {
		x += t;
		if (x > n || x < 1) {
			t = -t;
			y++;
			if (x > n) x = n;
			else x = 1;
		}
		if (a[i] == r) break;
	}
	cout << y << ' ' << x;
	return 0;
}
