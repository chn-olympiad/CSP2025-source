#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define fi first
#define se second
#define el cout<<"\n"
#define N 100010
//#define int long long
using namespace std;
int T, n, cnta, cntb, cntc, ans;
struct Member {
	int a, b, c;
} a[N];
vector<int>cdo;
void init() {
	cdo.clear();
	cnta = cntb = cntc = ans = 0;
}
void solve() {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].b >> a[i].c;
		if (a[i].a >= max(a[i].b, a[i].c)) {
			cnta++;
			ans += a[i].a;
		} else if (a[i].b >= max(a[i].a, a[i].c)) {
			cntb++;
			ans += a[i].b;
		} else if (a[i].c >= max(a[i].a, a[i].b)) {
			cntc++;
			ans += a[i].c;
		}
	}
	if (cnta > (n >> 1)) {
		for (int i = 1; i <= n; i++)
			if (a[i].a >= max(a[i].b, a[i].c))
				cdo.push_back(a[i].a - max(a[i].b, a[i].c));
		sort(cdo.begin(), cdo.end());
		for (int i = 0; i < cnta - (n >> 1); i++)
			ans -= cdo[i];
	} else if (cntb > (n >> 1)) {
		for (int i = 1; i <= n; i++)
			if (a[i].b >= max(a[i].a, a[i].c))
				cdo.push_back(a[i].b - max(a[i].a, a[i].c));
		sort(cdo.begin(), cdo.end());
		for (int i = 0; i < cntb - (n >> 1); i++)
			ans -= cdo[i];
	} else if (cntc >= (n >> 1)) {
		for (int i = 1; i <= n; i++)
			if (a[i].c >= max(a[i].a, a[i].b))
				cdo.push_back(a[i].c - max(a[i].a, a[i].b));
		sort(cdo.begin(), cdo.end());
		for (int i = 0; i < cntc - (n >> 1); i++)
			ans -= cdo[i];
	}
	cout << ans;
	el;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)solve();
	return 0;
}