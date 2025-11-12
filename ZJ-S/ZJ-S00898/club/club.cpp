#include <bits/stdc++.h>

#define int long long

#define all(A) A.begin(), A.end()

#define pb push_back

#define rep(A, B, C) for (int A = B; A <= C; ++A)

#define rep2(A, B, C, D) for (int A = B; A <= C; A += D)

using namespace std;

inline int read() {
	int x = 0, f = 1;
	
	char ch = getchar();
	
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		
		ch = getchar();
	}
	
	while (isdigit(ch))
		x = x * 10 + (ch - '0'), ch = getchar();
		
	return x * f;
}

typedef pair<int, int> PII;

const int N = 1e5 + 5;

int tt, n, ans, cnt, idx;

int a[N][5];

vector<int> A, B, C, v;

void clr() {
	v.clear(), A.clear(), B.clear(), C.clear();
		
	cnt = idx = ans = 0;
}

signed main() {
	freopen("club.in", "r", stdin);
	
	freopen("club.out", "w", stdout);
	
	tt = read();
	
	while (tt --) {
		n = read();
	
		rep(i, 1, n) rep(j, 1, 3) a[i][j] = read();
	
		rep(i, 1, n)
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) A.pb(i), ans += a[i][1];
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) B.pb(i), ans += a[i][2];
			else C.pb(i), ans += a[i][3];
	
		n >>= 1;
	
		if (A.size() <= n && B.size() <= n && C.size() <= n) {
			printf("%lld\n", ans);
			
			clr();
		
			continue;
		}
	
		if (A.size() > n) {
			cnt = A.size();
		
			for (auto x : A)
				v.pb(min(a[x][1] - a[x][2], a[x][1] - a[x][3]));
		} else if (B.size() > n) {
			cnt = B.size();
		
			for (auto x : B)
				v.pb(min(a[x][2] - a[x][1], a[x][2] - a[x][3]));
		} else {
			cnt = C.size();
		
			for (auto x : C)
				v.pb(min(a[x][3] - a[x][1], a[x][3] - a[x][2]));
		}
	
		sort(all(v));	
			
		while (cnt > n) ans -= v[idx], idx ++, cnt --;
		
		printf("%lld\n", ans);
		
		clr();
	}
	
	return 0;
}
