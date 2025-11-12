#include <bits/stdc++.h>
using namespace std;

#define il inline
#define ri register int
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<ll,int>
il ll read();

const int N = 100005;

int t, n;
struct node {
	ll a, b, c;
} z[N];
priority_queue <pii, vector<pii>, greater<pii> > a, b, c;
ll ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		while (!a.empty()) a.pop();
		while (!b.empty()) b.pop();
		while (!c.empty()) c.pop();
		ans = 0;
		cin >> n;
		for (ri i=1; i<=n; i++) {
			z[i].a = read();
			z[i].b = read();
			z[i].c = read();
			if (z[i].a >= z[i].b && z[i].a >= z[i].c) {
				ans += z[i].a;
				if (z[i].b >= z[i].c) {
					a.push({z[i].a - z[i].b, i});
				} else {
					a.push({z[i].a - z[i].c, i});
				}
			} else if (z[i].b >= z[i].c) {
				ans += z[i].b;
				if (z[i].a >= z[i].c) {
					b.push({z[i].b - z[i].a, i});
				} else {
					b.push({z[i].b - z[i].c, i});
				}
			} else {
				ans += z[i].c;
				if (z[i].a >= z[i].b) {
					c.push({z[i].c - z[i].a, i});
				} else {
					c.push({z[i].c - z[i].b, i});
				}
			}
		}
		while (a.size() > n / 2 || b.size() > n / 2 || c.size() > n / 2) {
			while (a.size() > n / 2) {
				ans -= a.top().first;
				int now = a.top().second;
				a.pop();
				if (z[now].b >= z[now].a) {
					c.push({inf, now});
				} else if (z[now].c >= z[now].a) {
					b.push({inf, now});
				} else if (z[now].b >= z[now].c) {
					b.push({z[now].b - z[now].c, now});
				} else {
					c.push({z[now].c - z[now].b, now});
				}
			}
			while (b.size() > n / 2) {
				ans -= b.top().first;
				int now = b.top().second;
				b.pop();
				if (z[now].a >= z[now].b) {
					c.push({inf, now});
				} else if (z[now].c >= z[now].b) {
					a.push({inf, now});
				} else if (z[now].a >= z[now].c) {
					a.push({z[now].a - z[now].c, now});
				} else {
					c.push({z[now].c - z[now].a, now});
				}
			}
			while (c.size() > n / 2) {
				ans -= c.top().first;
				int now = c.top().second;
				c.pop();
				if (z[now].a >= z[now].c) {
					b.push({inf, now});
				} else if (z[now].b >= z[now].c) {
					a.push({inf, now});
				} else if (z[now].a >= z[now].b) {
					a.push({z[now].a - z[now].b, now});
				} else {
					b.push({z[now].b - z[now].a, now});
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
il ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
