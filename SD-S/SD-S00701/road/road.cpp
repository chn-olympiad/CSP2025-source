#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4+5;
int n, m, k;
ll ans;

int f[N];
int findRt(int u) {return f[u]?f[u]=findRt(f[u]):u;}
int unionS(int x, int y) {
	x = findRt(x), y = findRt(y);
	f[x] = y;
}

struct lin {
	int u, v, d;
};
struct cmp {
	bool operator () (lin a, lin b) {
		return a.d>b.d;
	}
};
priority_queue<lin, vector<lin>, cmp> sel;

void input() {
	cin >> n >> m >> k;
	if (k) {
		cout << 0;
		return;
	}
	for (int i=1;i<=m;i++) {
		int u, v, d;
		cin >> u >> v >> d;
		sel.push({u, v, d});
	}
}

void kusal() {
	while (!sel.empty()) {
		int u=sel.top().u, v=sel.top().v, d=sel.top().d;
		sel.pop();
		if (findRt(u) == findRt(v)) continue;
		ans += d;
		unionS(u, v);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	input();
	if (k) return 0;
	kusal();
	cout << ans;
	return 0;
}
