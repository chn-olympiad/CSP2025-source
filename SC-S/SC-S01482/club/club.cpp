#include <bits/stdc++.h>
#define int long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs mid + 1, r
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int t, n, cnt[4], ans;

struct node{
	int mx, mmx, id;
} a[N];

bool cmp(node a, node b) {
	return a.mx - a.mmx > b.mx - b.mmx;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1;i <= n;i++) {
			int x, y, z;cin >> x >> y >> z;
			if(x >= max(y, z)) {
				a[i].mx = x;
				a[i].mmx = max(y, z);
				a[i].id = 1;
			} else if(y >= max(x, z)) {
				a[i].mx = y;
				a[i].mmx = max(x, z);
				a[i].id = 2;
			} else {
				a[i].mx = z;
				a[i].mmx = max(x, y);
				a[i].id = 3;
			}
		}
		sort(a + 1, a + n + 1, cmp);
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1;i <= n;i++) {
			if(cnt[a[i].id] == n / 2) {
				ans += a[i].mmx;
			} else {
				ans += a[i].mx;
				cnt[a[i].id]++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}