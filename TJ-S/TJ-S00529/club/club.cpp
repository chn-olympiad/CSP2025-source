#include <bits/stdc++.h>

using namespace std;

int T, n;
long long last_ans;
struct Info {
	int v, pos;
} q1[100001], q2[100001], q3[100001];
int yi_qv[4];
int c[100001];

inline void dfs(int i) {
	if (i == n + 1) {
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += c[i];
		}
		last_ans = max(last_ans, ans);
		return; 
	}
	int r[4];
	r[1] = q1[i].v, r[2] = q2[i].v, r[3] = q3[i].v;
	for (int j = 1; j <= 3; j++) {
		if (yi_qv[j] + 1 <= n / 2) {
			c[i] = r[j];
			yi_qv[j]++;
			dfs(i + 1);
			yi_qv[j]--;
		} else {
			continue;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= 100000; i++)
			q1[i].v = q2[i].v = q3[i].v = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			q1[i].v = a;
			q2[i].v = b;
			q3[i].v = c;
			q1[i].pos = i;
			q2[i].pos = i;
			q3[i].pos = i;
		}
		int ma = n / 2;
		dfs(1);
		printf("%lld\n", last_ans);
		for (int i = 1; i <= 3; i++) {
			yi_qv[i] = 0;
		}
		last_ans = 0;
	}
	return 0;
} 
