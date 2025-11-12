//write begin: 14:41
//travel beginning
#include  <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const int N = 1e5 + 5;
struct node{
	pii a, b, c;
	int Max;
}s[N];
int sum[4];
int n; 
bool cmp(node x, node y) { return x.a.fi + y.b.fi > y.a.fi + x.b.fi; }
void solve() {
	cin >> n; sum[1] = 0, sum[2] = 0, sum[3] = 0;
	for(int i = 1; i <= n; i ++) {
		int x, y, z; cin >> x >> y >> z;
		s[i].a = {x, 1}, s[i].b = {y, 2}, s[i].c = {z, 3};
		if(s[i].a < s[i].b) swap(s[i].a, s[i].b);
		if(s[i].a < s[i].c) swap(s[i].a, s[i].c);
		if(s[i].b < s[i].c) swap(s[i].b, s[i].c);
	}
	ll ans = 0;
	sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i ++) {
		if(sum[s[i].a.se] == n / 2) {
			ans += s[i].b.fi;
			sum[s[i].b.se] ++;
		} else sum[s[i].a.se] ++, ans += s[i].a.fi;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T; while(T --) solve();
	return 0;
}
//14:46 100pts
// CSP-S 2025 RP++!!!
