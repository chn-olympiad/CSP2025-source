#include <bits/stdc++.h>
#define il inline
#define ull unsigned long long 

using namespace std;

bool Beg;
const int P = 131;
const int N = 2e5 + 10, M = 5e6 + 10;
int n, qq, len[N];
char s[M], t[M];
ull a[N], b[N], hsh1[M], hsh2[M];
ull p[M];
il ull gethsh1(int l, int r) {
	return hsh1[r] - hsh1[l - 1] * p[r - l + 1];
}
il ull gethsh2(int l, int r) {
	return hsh2[r] - hsh2[l - 1] * p[r - l + 1];
}
int c[N], d[N];
vector<int> num[M << 1];
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
il int solve1() {
	for (int i = 1; i <= n; i++) {
		cin >> (s + 1) >> (t + 1);
		len[i] = strlen(s + 1);
		for (int j = 1; j <= len[i] && !c[i]; j++) {
			if (s[j] == 'b') c[i] = j;
		}
		for (int j = 1; j <= len[i] && !d[i]; j++) {
			if (t[j] == 'b') d[i] = j;
		}
		num[c[i] - d[i] + M].push_back(i);
	}
	while (qq--) {
		cin >> (s + 1) >> (t + 1);
		int kk = strlen(s + 1);
		int id1 = 0, id2 = 0;
		for (int i = 1; i <= kk && !id1; i++) {
			if (s[i] == 'b') id1 = i;
		}
		for (int i = 1; i <= kk && !id2; i++) {
			if (t[i] == 'b') id2 = i;
		}
		int ans = 0;
		for (int i : num[id1 - id2 + M]) {
			if (len[i] <= kk && c[i] <= id1 && id1 + (len[i] - c[i] + 1) - 1 <= kk) ans++;
		}
		cout << ans << "\n";
	}
//	Usd();
	return 0;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace4.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc replace4.ans mine.out"); return 0;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> qq;
	if (n > 100 && qq > 100) return solve1();
	for (int i = 1; i <= n; i++) {
		cin >> (s + 1) >> (t + 1);
		len[i] = strlen(s + 1);
		for (int j = 1; j <= len[i]; j++) {
			a[i] = a[i] * P + s[j];
			b[i] = b[i] * P + t[j];
		}
	}
	p[0] = 1;
	for (int i = 1; i < M; i++) p[i] = p[i - 1] * P;
	while (qq--) {
		cin >> (s + 1) >> (t + 1);
		int kk = strlen(s + 1);
		for (int i = 1; i <= kk; i++) {
			hsh1[i] = hsh1[i - 1] * P + s[i];
			hsh2[i] = hsh2[i - 1] * P + t[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + len[i] - 1 <= kk; j++) {
				ull h1 = gethsh1(j, j + len[i] - 1), h2 = gethsh2(j, j + len[i] - 1);
//				cout << "! " << i << " " << j << "  " << a[i] << " " << b[i] << " " << h1 << " " << h2 << " " << hsh1[kk] << " " << hsh2[kk] << " " << hsh1[kk] + (b[i] - h1) * p[kk - (j + len[i] - 1)] << "\n";
				if (a[i] == h1 && b[i] == h2 && hsh1[kk] + (b[i] - h1) * p[kk - (j + len[i] - 1)] == hsh2[kk]) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
//	Usd();
	return 0;
}
