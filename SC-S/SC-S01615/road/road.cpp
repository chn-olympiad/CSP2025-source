#include<bits/stdc++.h>
using namespace std;
struct node {
	long long from, to, w;
};
long long n, m, k, u, v, weight, vis[100010], num = 0;
vector<node> ans;
bool cmp(node a, node b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> weight;
		ans.push_back(node{u, v, weight});
	}
	sort(ans.begin(), ans.end(), cmp);
	for (auto c : ans) {
		bool flag = 1;
		if (!vis[c.from] || !vis[c.to]) num += c.w, vis[c.from] = 1, vis[c.to] = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				flag = 0;
				break;
			}
		if (flag) {
			cout << num;
			break;
		}
	}
	return 0;
}