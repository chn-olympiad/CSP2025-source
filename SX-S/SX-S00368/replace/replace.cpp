#include <bits/stdc++.h>
using namespace std;
long long n, m, d, xi;
int k[5000005], ma;

struct node {
	string a, b;
} ss[200005];


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ss[i].a >> ss[i].b;
		k[ss[i].a.size()]++;
		int c = ss[i].a.size();
		ma = max(ma, c);
		xi = i;
	}
	while (m--) {
		string g, h;
		int s = 0, w = 0;
		cin >> g >> h;
		if (g.size() != h.size() || g == h) {
			cout << 0 << endl;
			continue;
		}
		int r = h.size();
		for (int j = 0; j < r; j++) {
			if (g[j] != h[j]) {
				s = j;
				break;
			}
		}
		for (int i = r - 1; i >= 0; i--) {
			if (g[i] != h[i]) {
				w = i;
				break;
			}
		}
		int y = w - s + 1;
		if (y > ma) {
			cout << 0 << endl;
			continue;
		}
	}
	return 0;
}