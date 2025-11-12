#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> PII;

#define mp make_pair
#define ep emplace
#define eb emplace_back
#define fir first
#define sec second

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}

const int N = 200010, M = 5000010;
const int base[] = {13331, 2009107};
const int mod[] = {998244853, 1000000009};

int n, q, len[N], pw[2][M];
PII sh1[N], sh2[N];
int hsh0[2][M], hsh1[2][M];
char s1[N], s2[N];

PII get_hsh(int h0[], int h1[], int l, int r) {
	int n0 = (h0[r] - h0[l - 1] * pw[0][r - l + 1] % mod[0] + mod[0]) % mod[0];
	int n1 = (h1[r] - h1[l - 1] * pw[1][r - l + 1] % mod[1] + mod[1]) % mod[1]; 
	return mp(n0, n1);
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read(), pw[0][0] = pw[1][0] = 1;
	for (int i = 1; i < M; i ++ ) {
		pw[0][i] = pw[0][i - 1] * base[0] % mod[0];
		pw[1][i] = pw[1][i - 1] * base[1] % mod[1];
	}
	for (int i = 1; i <= n; i ++ ) {
		scanf("%s%s", s1 + 1, s2 + 1);
		len[i] = strlen(s1 + 1);
		int h0 = 0, h1 = 0;
		for (int j = 1; j <= len[i]; j ++ ) {
			h0 = (h0 * base[0] % mod[0] + s1[j]) % mod[0];
			h1 = (h1 * base[1] % mod[1] + s1[j]) % mod[1];
		}
		sh1[i] = mp(h0, h1);
		h0 = 0, h1 = 0;
		for (int j = 1; j <= len[i]; j ++ ) {
			h0 = (h0 * base[0] % mod[0] + s2[j]) % mod[0];
			h1 = (h1 * base[1] % mod[1] + s2[j]) % mod[1];
		}
		sh2[i] = mp(h0, h1);
	}
	while (q -- ) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int l1 = strlen(s1 + 1);
		int l2 = strlen(s2 + 1);
		if (l1 != l2) {
			puts("0");
			continue;
		}
		for (int i = 1; i <= l1; i ++ ) {
			hsh0[0][i] = (hsh0[0][i - 1] * base[0] % mod[0] + s1[i]) % mod[0];
			hsh0[1][i] = (hsh0[1][i - 1] * base[1] % mod[1] + s1[i]) % mod[1];
		}
		for (int i = 1; i <= l1; i ++ ) {
			hsh1[0][i] = (hsh1[0][i - 1] * base[0] % mod[0] + s2[i]) % mod[0];
			hsh1[1][i] = (hsh1[1][i - 1] * base[1] % mod[1] + s2[i]) % mod[1];
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= l1 - len[i] + 1; j ++ ) {
				if (get_hsh(hsh0[0], hsh0[1], j, j + len[i] - 1) == sh1[i]) {
					if (get_hsh(hsh1[0], hsh1[1], j, j + len[i] - 1) == sh2[i]) {
						if (get_hsh(hsh0[0], hsh0[1], 1, j - 1) == get_hsh(hsh1[0], hsh1[1], 1, j - 1)) {
							if (get_hsh(hsh0[0], hsh0[1], j + len[i], l1) == get_hsh(hsh1[0], hsh1[1], j + len[i], l1)) ans ++ ;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
