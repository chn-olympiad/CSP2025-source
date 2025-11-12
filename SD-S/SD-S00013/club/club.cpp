#include <iostream>
#include <queue>
#define int long long
const int N = 1e5 + 5;
int T;
int n;
int ans;
int cnt[5];
int to[N];
int a[N][5];
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 10) write(x / 10);
	putchar(x % 10 + '0');
}

void solve(int t) {
	std::priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		int val = -1e9;
		if (to[i] != t) continue;
		for (int j = 1; j <= 3; j++) 
			if (j != t) val = std::max(val, a[i][j] - a[i][t]);
		q.push(val);
	} 
	while (q.size() && cnt[t] > (n >> 1)) {
		cnt[t]--;
		ans += q.top();
		q.pop();
	}
}

signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--) {
		ans = 0;
		n = read();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) 
				a[i][j] = read();	
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) ans += a[i][1], cnt[1]++, to[i] = 1;
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) ans += a[i][2], cnt[2]++, to[i] = 2;
			else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) ans += a[i][3], cnt[3]++, to[i] = 3;
		}
		if (cnt[1] > (n >> 1)) 
			solve(1);
		else if (cnt[2] > (n >> 1)) 
			solve(2);
		else if (cnt[3] > (n >> 1)) 
			solve(3);
		write(ans);
		putchar('\n');
		
		for (int i = 1; i <= n; i++) 
			to[i] = 0;
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
