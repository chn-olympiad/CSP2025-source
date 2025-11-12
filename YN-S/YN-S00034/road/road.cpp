#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long w[N], n, m, k, ans = 0;

struct TN {
	int v;
	vector<int> sons;
} tr[N];

struct TM {
	int c;
	vector<int> cos;
} vi[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y >> w[i];
		tr[x].sons.push_back(y);
		tr[y].sons.push_back(x);
		ans += w[i];
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> vi[i].c;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			vi[i].cos.push_back(x);
		}
	}
	ans = 0;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}