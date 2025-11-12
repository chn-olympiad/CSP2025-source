#include <bits/stdc++.h>
#define ll long long
const int N = 1e5+10;
using namespace std;

struct dian {
	int w, v, id;
};

struct bian {
	int l, r, va;
} b[N];

bool cmd(bian x, bian y) {
	return x.va < y.va;
}
vector<dian > ed[N];
long long dis[N], rd[N], c[N];
bool vis[N];
ll n, m, k, ans;

bool check(int nn) {
	for (int i = 1; i <= nn; i++)
		if (rd[i] == 0)
			return 0;
	return 1;
}

void j(int nn) {
	ans = 0;
	for (int i = 1; i <= nn ; i++) {
		int x = b[i].l, y = b[i].r;
		rd[x]++, rd[y]++;
		ans += b[i].va ;
		if (check(nn)) {
			break;
		}
	}
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		b[i].l = x, b[i].r = y, b[i].va = z;
//		rd[x]++, rd[y]++;
//		ans += z;
	}
	sort(b + 1, b + m + 1, cmd);
	ll sum = 1e9;
	int f = 1;
	j(n);
	sum = min(ans, sum);
	for (int i = 1; i <= k; i++) {
		memset(rd, 0, sizeof(0));
		cin >> c[i];
		if (c[i] != 0)
			f = 0;
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x != 0)
				f = 0;
		}


	}
	if (f && k > 0)
		cout << 0;
	else
		cout << sum;
	return 0;
}

