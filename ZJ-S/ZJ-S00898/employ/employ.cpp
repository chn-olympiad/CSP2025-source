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

const int N = 1e6 + 5, mod = 998244353;

int n, m;

char s[N];

int a[N];

int mp[N], b[N], c[N], ans;

int chkA() {
	rep(i, 1, n) if (a[i] == 0) return 0;
	
	return 1;
}

void solveA() {
	int res = 1, cnt = n;
	
	rep(i, 1, n) if (c[i] == 0) cnt --;
	
	rep(i, 1, cnt) res = res * i % mod;
	
	printf("%lld\n", res);
}

int chk() {
	int res = 0;
	
	rep(i, 1, n)
		if (a[i] == 0 || res >= c[b[i]])
			res ++;
		
	return n - res >= m;	
}

void dfs(int x) {
	if (x == n + 1) {
		if (chk()) ans ++;
		
		return;
	}
	
	rep(i, 1, n) if (mp[i] == 0) mp[i] = 1, b[x] = i, dfs(x + 1), b[x] = 0, mp[i] = 0;
}

void baoli() {
	dfs(1);
	
	printf("%lld\n", ans);
}

signed main() {
	freopen("employ.in", "r", stdin);

	freopen("employ.out", "w", stdout);
	
	srand(time(NULL));

	n = read(), m = read();
	
	scanf("%s", s + 1);
	
	rep(i, 1, n) a[i] = (s[i] - '0');
	
	rep(i, 1, n) c[i] = read();
	
	if (n <= 10) { baoli(); return 0; }
	
	if (chkA()) { solveA(); return 0; }

	int res = 1;
	
	rep(i, 1, n) res = res * (rand() % 514 + 114) % mod;

	return 0;
}

