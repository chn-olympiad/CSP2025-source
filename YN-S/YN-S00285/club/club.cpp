#include <bits/stdc++.h>
using namespace std;
int a[300000];
int b[300000];
int c[300000];

struct S {
	int from;
	int v;
	bool operator<(const S &o)const {
		return v > o.v;
	}
};
bool vis[300000];

void solve() {
	memset(vis, 0, sizeof(vis));
	int n;
	cin >> n;
	long long ans = 0;
	vector<int> cl1, cl2, cl3;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= b[i] && a[i] >= c[i]) {
			cl1.push_back(i);
			ans += a[i];
		}
		if (b[i] > a[i] && b[i] >= c[i]) {
			cl2.push_back(i);
			ans += b[i];
		}
		if (c[i] > a[i] && c[i] > b[i]) {
			cl3.push_back(i);
			ans += c[i];
		}
	}
	priority_queue<S> p;
	if (cl1.size() > n / 2) {
		int ch = cl1.size() - n / 2;
		for (int i = 0; i < cl1.size(); i++) {
			p.push({cl1[i], a[cl1[i]] - b[cl1[i]]});
			p.push({cl1[i], a[cl1[i]] - c[cl1[i]]});
		}
		for (int i = 1; i <= ch; i++) {
			S t;
			do {
				t = p.top();
				p.pop();
			} while (vis[t.from]);
			ans -= t.v;
			vis[t.from] = true;
		}
	}
	if (cl2.size() > n / 2) {
		int ch = cl2.size() - n / 2;
		for (int i = 0; i < cl2.size(); i++) {
			p.push({cl2[i], b[cl2[i]] - a[cl2[i]]});
			p.push({cl2[i], b[cl2[i]] - c[cl2[i]]});
		}
		for (int i = 1; i <= ch; i++) {
			S t;
			do {
				t = p.top();
				p.pop();
			} while (vis[t.from]);
			ans -= t.v;
			vis[t.from] = true;
		}
	}
	if (cl3.size() > n / 2) {
		int ch = cl3.size() - n / 2;
		for (int i = 0; i < cl3.size(); i++) {
			p.push({cl3[i], c[cl3[i]] - a[cl3[i]]});
			p.push({cl3[i], c[cl3[i]] - b[cl3[i]]});
		}
		for (int i = 1; i <= ch; i++) {
			S t;
			do {
				t = p.top();
				p.pop();
			} while (vis[t.from]);
			ans -= t.v;
			vis[t.from] = true;
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}