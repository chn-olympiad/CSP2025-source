#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n;

struct node {
	int a, b, c;
} a[N];
int sum[4], book[N];
int res;

struct edge {
	int val, idx, type, ans;
} f[N * 3];
int tot;

bool cmp(edge a, edge b) {
	return a.val > b.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		//sum[1] = sum[2] = sum[3] = 0;
		res = 0;
		cin >> n;
		tot = 0;
		sum[1] = sum[2] = sum[3] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			book[i] = 0;
			f[++tot] = {a[i].a - max(a[i].b, a[i].c), i, 1, a[i].a};
			f[++tot] = {a[i].b - max(a[i].a, a[i].c), i, 2, a[i].b};
			f[++tot] = {a[i].c - max(a[i].a, a[i].b), i, 3, a[i].c};
		}
		sort(f + 1, f + 1 + tot, cmp);
		for (int i = 1; i <= tot; i++) {

			if (book[f[i].idx])
				continue;
			if (sum[f[i].type] >= n / 2)
				continue;
			//cout << f[i].val << " " << f[i].idx << " " << f[i].type << " " << f[i].ans << endl;
			res += f[i].ans;
			sum[f[i].type]++;
			book[f[i].idx] = 1;
		}
		cout << res << '\n';
	}
	return 0;
}