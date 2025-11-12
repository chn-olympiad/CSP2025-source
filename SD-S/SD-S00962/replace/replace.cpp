#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define GL return
#define HF 0

const int N = 2010;

int n, q, len[N][2], m;
char s[N][2][N], t[N], r[N], t2[N];
ll ans = 0ll;

void solve () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", s[i][0] + 1, s[i][1] + 1);
		len[i][0] = strlen(s[i][0] + 1);
		len[i][1] = strlen(s[i][1] + 1);
	}
	for (; q--; ) {
		scanf("%s%s", t + 1, r + 1);
		m = strlen(t + 1);
		ans = 0ll;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (i + len[j][0] - 1 <= m) {
					for (int j = 1; j <= m; j++) {
						t2[j] = t[j];
					}
					bool f = true;
					for (int k = 1; k <= len[j][0]; k++) {
						if (t[i + k - 1] != s[j][0][k]) {
							f = false;
							break;
						}
					}
					if (!f) {
						continue;
					}
					for (int k = 1; k <= len[j][0]; k++) {
						t2[i + k - 1] = s[j][1][k];
					}
					//t2, r
					bool ok = true;
					for (int i = 1; i <= m; i++) {
						if (t2[i] != r[i]) {
							ok = false;
							break;
						}
					}
					if (ok) {
						ans++;
					}
				}
			}
			if (t[i] != r[i]) {
				break;
			}
		}
		printf("%lld\n", ans);
	}
	GL;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	GL HF;
}
//key Ren5Jie4Di4Ling5%
