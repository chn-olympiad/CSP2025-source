#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int T;
int n;
struct node {
	int a, b, c;
} s[N];
int f1[N], f2[N], f3[N];
int cnt1, cnt2, cnt3;
void clear() {
	for (int i = 0; i <= N - 5; i++) {
		f1[i] = 0;
		f2[i] = 0;
		f3[i] = 0;
		s[i].a = 0, s[i].b = 0, s[i].c = 0;
		cnt1 = 0, cnt2 = 0, cnt3 = 0;
	}
}
void solve() {
	clear();
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b >> s[i].c;
		if (s[i].a >= s[i].b && s[i].a >= s[i].c) {
			ans += s[i].a;
			f1[++cnt1] = s[i].a - max(s[i].b, s[i].c);
		} else if (s[i].b >= s[i].a && s[i].b >= s[i].c) {
			ans += s[i].b;
			f2[++cnt2] = s[i].b - max(s[i].a, s[i].c);
		} else {
			ans += s[i].c;
			f3[++cnt3] = s[i].c - max(s[i].a, s[i].b);
		}
	}
	sort(f1 + 1, f1 + cnt1 + 1);
	sort(f2 + 1, f2 + cnt2 + 1);
	sort(f3 + 1, f3 + cnt3 + 1);
	if (cnt1 > n / 2) {
		for (int i = 1; cnt1 - i >= n / 2; i++) {
			ans -= f1[i];
		}
	} else if (cnt2 > n / 2) {
		for (int i = 1; cnt2 - i >= n / 2; i++) {
			ans -= f2[i];
		}
	} else if (cnt3 > n / 2) {
		for (int i = 1; cnt3 - i >= n / 2; i++) {
			ans -= f3[i];
		}
	}
	cout << ans << '\n';
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}