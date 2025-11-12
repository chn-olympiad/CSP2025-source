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
const int N = 5e5 + 10;
int n, k, a[N], pre[N], vis[N], cnt, ans;
struct node{
	int l, r;
} v[N];
bool cmp(node a, node b) {
	return a.l < b.l;
}
signed main() {
	iosfst;
	File("xor");
	cin >> n >> k;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n) pre[i] = pre[i - 1] ^ a[i];
	rep (i, 1, n) {
		if ((pre[i] ^ k) == 0) v[++cnt].l = i, v[cnt].r = i;
		else if (vis[pre[i] ^ k]) v[++cnt].l = vis[pre[i] ^ k], v[cnt].r = i;
		vis[pre[i]] = i;
	}
	sort(v + 1, v + cnt + 1, cmp);
	rep (i, 1, n) {
		int j = i + 1;
		while (j <= n && v[i].r >= v[j].l) j++;
		i = j - 1;
		ans++;
	}
	cout << ans;
	return 0;
}
