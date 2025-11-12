#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x*f;
}
int T;
int a[MAXN][4], m[4];
struct Node {
	int v, l;
} cf[4][MAXN], f[MAXN], f1[MAXN];
int cnt[MAXN];
bool cmp(Node x, Node y) {
	return x.v > y.v;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		memset(m, 0, sizeof(m));
		memset(f1, 0, sizeof(f1));
		memset(f, 0, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		memset(cf, 0, sizeof(cf));
		long long ans = 0;
		int n = read();
		for (int i = 1; i <= n; i++) {
			int t = -1, pos;
			for (int j = 1; j <= 3; j++) {
				a[i][j] = read();
				if (a[i][j] > t)t = a[i][j], pos = j;
			}
			ans += t, m[pos]++;
			cf[pos][++cnt[pos]].v = t, cf[pos][cnt[pos]].l = i;
		}
		int tmp = ans;
		for (int i = 1; i <= 3; i++) {
			if (m[i] > (n / 2)) {
				int tot =  m[i] - (n / 2), temp = tmp;
				for (int j = 1; j <= cnt[i]; j++) {
					int t = cf[i][j].l, nul = -1, del, nul1 = -1, del1;
					for (int k = 1; k <= 3; k++) {
						if (k == i) continue;
						if (a[t][k] > nul )nul = a[t][k], del = k;
					}
					for (int k = 1; k <= 3; k++) {
						if (k == i) continue;
						if (a[t][k] > nul1  && a[t][k] != nul)nul1 = a[t][k], del1 = k;
					}
					f[j].v = nul - cf[i][j].v;
					f[j].l = del;
					f1[j].v = nul1 - cf[i][j].v, f1[j].l = del1;
				}
				sort(f + 1, f + cnt[i] + 1, cmp);
				sort(f1 + 1, f1 + cnt[i] + 1, cmp);
				int cnttot = 0;
				for (int j = 1; j <= cnt[i]; j++) {
					if (m[f[j].l] + 1 <= (n / 2))ans += f[j].v, m[f[j].l]++, cnttot++;
					else if (m[f1[j].l] + 1 <= (n / 2))ans += f1[j].v, m[f1[j].l]++, cnttot++;
					if (cnttot == tot)break;
				}
				m[i] -= tot;
			}
		}
		cout << ans << endl;

	}
	return 0;
}
