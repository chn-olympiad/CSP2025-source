#include<bits/stdc++.h>
using namespace std;

struct node {
	int l, r;
};

int n;
long long a[500005], k, f[500005];
vector<node> could;

bool cmp(node x, node y) {
	if (x.l != y.l) return x.l < y.l;
	return x.r < y.r;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((f[j] ^ f[i - 1]) == k) {
				could.push_back({i, j});
			}
		}
	}
	sort(could.begin(), could.end(), cmp);
	int ans = 0;
	for (int j = 0; j < could.size() - ans; j++) {
		node now = could[j];
		int i = j + 1, sum = 1;
		while (now.r <= n) {
			while (i < could.size() && could[i].l <= now.r) {
				i++;
			}
			if (i >= could.size()) {
				break;
			}
			now = could[i++];
			sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}