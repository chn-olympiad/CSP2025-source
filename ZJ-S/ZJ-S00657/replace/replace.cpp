#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef unsigned long long ull;
const int N = 2010;
const int M = 5e6 + 10;
const ull base = 233;
int n, q, tot;
char s1[N], s2[N];
ull pw[M], h[M];
map<pair<ull, ull>, int> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	pw[0] = 1;
	FL(i, 1, M - 1) {
		pw[i] = pw[i - 1] * base;
	}
	scanf("%d %d", &n, &q);
	FL(i, 1, n) {
		scanf("%s %s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		ull h1 = 0, h2 = 0;
		FL(j, 1, len) {
			h1 = h1 * base + s1[j];
			h2 = h2 * base + s2[j];
			h[++tot] = h1 * pw[len] + h2;
		}
		++mp[{h1, h2}];
//		cout << " " << h1 << ' ' << h2 << endl;
	}
	sort(h + 1, h + tot + 1);
	while (q--) {
		scanf("%s %s", s1 + 1, s2 + 1);
		int len1 = strlen(s1 + 1);
		int len2 = strlen(s2 + 1);
		int ans = 0;
		if (len1 != len2) {
			puts("0");
			continue;
		}
		int l = len1 + 1, r = 0;
		FL(i, 1, len1) {
			if (s1[i] != s2[i]) {
				l = min(l, i);
				r = max(r, i);
			}
		}
		FR(i, l, 1) {
			ull h1 = 0, h2 = 0;
			FL(j, i, len1) {
				h1 = h1 * base + s1[j];
				h2 = h2 * base + s2[j];
//				cout << "i:" << i << ' ' << j << ' ' << h1 << ' ' << h2 << endl;
				if (j >= r) {
					ans += mp[{h1, h2}];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
