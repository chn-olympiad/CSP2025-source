#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
int father[N], w[20][N], l = 0;
long long n, m, k, ans = 0;

struct ask {
	long long data, t, f, m;
	bool operator<(const ask &A) const {
		return data > A.data;
	}
} a;
priority_queue<ask, vector<ask>> q;

int f(int son) {
	if (father[son] != son)
		father[son] = f(father[son]);
	return father[son];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	a.m = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &a.f, &a.t, &a.data);
		q.push(a);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	}
	while (!q.empty() && l < n - 1) {
		a = q.top();
		q.pop();
		if (f(a.f) != f(a.t)) {
			ans += a.data;
			father[father[a.f]] = father[a.t];
			l++;
		}
	}
	printf("%lld", ans);

	return 0;
}
