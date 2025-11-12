#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define sz size
#define fi first
#define se second
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define ull unsigned long long

using namespace std;

const int N = 2e5 + 5;
const int M = 5e6 + 5;
ull base = 131;

int n, q, len[N];
char s[3][M];
ull h1[N], h2[N], p[M], H1[M], H2[M];

ull get_H1(int l, int r) {
	if (l > r) return 0;
	return H1[r] - H1[l - 1] * p[r - l + 1];
}

ull get_H2(int l, int r) {
	if (l > r) return 0;
	return H2[r] - H2[l - 1] * p[r - l + 1];
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 5000000; i++) p[i] = p[i - 1] * base;
	for (int i = 1; i <= n; i++) {
		cin >> s[1] + 1 >> s[2] + 1;
		len[i] = strlen(s[1] + 1);
		for (int j = 1; j <= len[i]; j++) h1[i] = h1[i] * base + s[1][j], h2[i] = h2[i] * base + s[2][j];
	}
	while (q--) {
		cin >> s[1] + 1 >> s[2] + 1;
		if (strlen(s[1] + 1) != strlen(s[2] + 1)) {
			cout << "0\n";
			continue;
		}
		int l = strlen(s[1] + 1), ans = 0;
		for (int i = 1; i <= l; i++) {
			H1[i] = H1[i - 1] * base + s[1][i];
			H2[i] = H2[i - 1] * base + s[2][i];
		}
		for (int i = 1; i <= l; i++) {
			if (get_H1(1, i - 1) != get_H2(1, i - 1)) break;
			for (int j = 1; j <= n; j++) {
				if (i + len[j] - 1 <= l && get_H1(i, i + len[j] - 1) == h1[j] && get_H2(i, i + len[j] - 1) == h2[j] && get_H1(i + len[j], l) == get_H2(i + len[j], l)) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
