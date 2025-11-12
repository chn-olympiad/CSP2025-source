#include<bits/stdc++.h>
using namespace std;
int t, n;
const int N = 1e5 + 5;
struct st {
	int a, b, c;
} s[N];
int b[N];
int ans, cnt;
int cmp1(st a, st b) {
	return a.a > b.a;
}
int cmp2(st a, st b) {
	return abs(a.a - a.b) > abs(b.a - b.b);
}
int na, nb, nc;
void dfs(int d, int i) {
	if(d > n) {
		ans = max(ans, cnt);
		return ;
	}
	if(i == 1) {
		cnt += s[d].a;
		if(d != 0) na++;
		if(na == n / 2) {
			dfs(d + 1, 2);
			dfs(d + 1, 3);
		} else {
			dfs(d + 1, 1);
			dfs(d + 1, 2);
			dfs(d + 1, 3);
		}
		if(d != 0) na--;
		cnt -= s[d].a;
	} else if(i == 2) {
		cnt += s[d].b;
		if(d != 0) nb++;
		if(nb == n / 2) {
			dfs(d + 1, 1);
			dfs(d + 1, 3);
		} else {
			dfs(d + 1, 1);
			dfs(d + 1, 2);
			dfs(d + 1, 3);
		}
		if(d != 0) nb--;
		cnt -= s[d].b;
	} else if(i == 3) {
		cnt += s[d].c;
		if(d != 0) nc++;
		if(nc == n / 2) {
			dfs(d + 1, 1);
			dfs(d + 1, 2);
		} else {
			dfs(d + 1, 1);
			dfs(d + 1, 2);
			dfs(d + 1, 3);
		}
		if(d != 0) nc--;
		cnt -= s[d].c;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		bool bb = 0, bc = 0;
		for(int i = 1; i <= n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			if(s[i].c) bc = 1;
			if(s[i].b) bb = 1;
		}
		if(!bb && !bc) {
			sort(s + 1, s + n + 1, cmp1);
			ans = 0;
			for(int i = 1; i <= n / 2; i++) {
				ans += s[i].a;
			}
			cout << ans << '\n';
			continue;
		} else if(!bc) {
			ans = 0;
			sort(s + 1, s + n + 1, cmp2);
			int t1 = 0, t2 = 0;
			for(int i = 1; i <= n; i++) {
				if(s[i].a > s[i].b && t1 < n / 2) {
					t1++;
					ans += s[i].a;
				} else if(s[i].a < s[i].b && t2 < n / 2) {
					t2++;
					ans += s[i].b;
				} else if(t1 == n / 2) {
					ans += s[i].b;
				} else {
					ans += s[i].a;
				}
			}
			cout << ans << '\n';
		} else if(n == 2) {
			ans = 0;
			for(int i = 1; i <= 3; i++) {
				for(int j = 1; j <= 3; j++) {
					int cnt = 0;
					if(i != j) {
						if(i == 1) {
							cnt += s[1].a;
						}
						if(i == 2) {
							cnt += s[1].b;
						}
						if(i == 3) {
							cnt += s[1].c;
						}
						if(j == 1) {
							cnt += s[2].a;
						}
						if(j == 2) {
							cnt += s[2].b;
						}
						if(j == 3) {
							cnt += s[2].c;
						}
					}
					ans = max(ans, cnt);
				}
			}
			cout << ans << '\n';
		} else {
			ans = 0;
			na = nb = nc = cnt = 0;
			dfs(0, 1);
			cout << ans << '\n';
		}
		for(int i = 1; i <= n; i++) {
			s[i].a = s[i].b = s[i].c = 0;
		}
	}
	return 0;
}
