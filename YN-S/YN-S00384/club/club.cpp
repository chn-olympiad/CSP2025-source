#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define ll long long
ll n, s[N][5], m;

struct node {
	ll a, b, c, v;
} f[N][5];

void updata(int x, int j, int u) {
	if (f[x][j].v < f[x + 1][u].v) {
		f[x][j] = f[x + 1][u];
		if (j == 1)
			f[x][j].a++;
		else if (j == 2)
			f[x][j].b++;
		else if (j == 3)
			f[x][j].c++;
	}
}

void dfs(int x, int j) {
	if (x == n) {
		f[x][j].v = s[x][j];
		if (j == 1)
			f[x][j].a = 1;
		else if (j == 2)
			f[x][j].b = 1;
		else if (j == 3)
			f[x][j].c = 1;
		return ;
	}
	if (!f[x + 1][1].v)
		dfs(x + 1, 1);
	if (!f[x + 1][2].v)
		dfs(x + 1, 2);
	if (!f[x + 1][3].v)
		dfs(x + 1, 3);
	for (int u = 1; u <= 3; u++) {
		ll va = f[x + 1][u].a + 1;
		if (va  <= m ) {
			updata(x, j, u);
			if (m == 1)
				cout << f[x ][j].a  << "\n";
		}
		if (f[x + 1][u].b + 1 <= m)
			updata(x, j, u);
		if (f[x + 1][u].c + 1 <= m)
			updata(x, j, u);
	}
	f[x][j].v += s[x][j];
}

void slove() {
	cin >> n;
	memset(s, 0, sizeof(s));
	memset(f, 0, sizeof(f));

	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2] >> s[i][3];
	}
	m = n / 2;
	dfs(0, 0);
	int ans = max(f[1][1].v, max(f[1][2].v, f[1][3].v));
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 0;
	cin >> t;
	while (t--) {
		slove();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}