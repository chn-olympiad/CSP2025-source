#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], g[5], d[100005], z1, z2, z3, ans;

struct node {
	int z, w;
} mx[100005];
vector<int>b[5][5];

bool cmp(int x, int y) {
	return a[x][z1] - a[x][z2] > a[y][z1] - a[y][z2];
}

bool cmp2(int x, int y) {
	return a[x][z1] - a[x][z3] > a[y][z1] - a[y][z3];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= max(a[i][2], a[i][3])) {
				mx[i] = node{a[i][1], 1};
				g[1]++;
				d[i] = 1;
			} else if (a[i][2] >= max(a[i][1], a[i][3])) {
				mx[i] = node{a[i][2], 2};
				g[2]++;
				d[i] = 2;
			} else {
				mx[i] = node{a[i][3], 3};
				g[3]++;
				d[i] = 3;
			}
			ans += mx[i].z;
		}
		if (g[1] > n / 2) {
			z1 = 1;
			z2 = 2;
			z3 = 3;
		} else if (g[2] > n / 2) {
			z1 = 2;
			z2 = 1;
			z3 = 3;
		} else {
			z1 = 3;
			z2 = 1;
			z3 = 2;
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == z1) {
				b[z1][z2].push_back(i);
				b[z1][z3].push_back(i);
			}
		}
		sort(b[z1][z2].begin(), b[z1][z2].end(), cmp);
		sort(b[z1][z3].begin(), b[z1][z3].end(), cmp2);
		while (g[z1] > n / 2) {
			while (d[b[z1][z2][b[z1][z2].size() - 1]] != z1)
				b[z1][z2].pop_back();
			while (d[b[z1][z3][b[z1][z3].size() - 1]] != z1)
				b[z1][z3].pop_back();
			if (a[b[z1][z2][b[z1][z2].size() - 1]][z1] - a[b[z1][z2][b[z1][z2].size() - 1]][z2] < a[b[z1][z3][b[z1][z3].size() -
			        1]][z1] - a[b[z1][z3][b[z1][z3].size() - 1]][z3]) {
				d[b[z1][z2][b[z1][z2].size() - 1]] = z2;
				g[z1]--;
				ans -= a[b[z1][z2][b[z1][z2].size() - 1]][z1] - a[b[z1][z2][b[z1][z2].size() - 1]][z2];
			} else {
				d[b[z1][z3][b[z1][z3].size() - 1]] = z3;
				g[z1]--;
				ans -= a[b[z1][z3][b[z1][z3].size() - 1]][z1] - a[b[z1][z3][b[z1][z3].size() - 1]][z3];
			}
		}
		cout << ans << '\n';
		g[1] = g[2] = g[3] = ans = 0;
		while (!b[z1][z2].empty())
			b[z1][z2].pop_back();
		while (!b[z1][z3].empty())
			b[z1][z3].pop_back();
	}
	return 0;
}
