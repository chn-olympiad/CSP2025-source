#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define ep emplace
#define eb emplace_back
#define fir first
#define sec second

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}

const int N = 100010;

int n, ans, a[N][4], cnt[4], p[N];

void solve() {
	memset(cnt, 0, sizeof cnt);
	n = read(), ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		p[i] = max_element(a[i], a[i] + 3) - a[i];
		cnt[p[i]] ++ , ans += a[i][p[i]];
	}
	priority_queue<int, vector<int>, greater<int>> q;
	if (cnt[0] > n / 2) {
		for (int i = 1; i <= n; i ++ ) if (p[i] == 0) q.ep(a[i][0] - max(a[i][1], a[i][2]));
		while (q.size() && cnt[0] > n / 2) ans -= q.top(), cnt[0] -- , q.pop();
	}
	else if (cnt[1] > n / 2) {
		for (int i = 1; i <= n; i ++ ) if (p[i] == 1) q.ep(a[i][1] - max(a[i][0], a[i][2]));
		while (q.size() && cnt[1] > n / 2) ans -= q.top(), cnt[1] -- , q.pop();
	}
	else if (cnt[2] > n / 2) {
		for (int i = 1; i <= n; i ++ ) if (p[i] == 2) q.ep(a[i][2] - max(a[i][0], a[i][1]));
		while (q.size() && cnt[2] > n / 2) ans -= q.top(), cnt[2] -- , q.pop();
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _ = read();
	while (_ -- ) solve(); 
	return 0;
}
/*
2:51 finish 100
*/
