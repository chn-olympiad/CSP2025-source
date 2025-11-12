#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	} if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
}
const int N = 2e5 + 10, B = 131, M = 25e5 + 10, MOD = 1e9 + 7;
int n, q, tot1, tot2, has1[M], has2[M], l[N], r[N], siz[N], has[N][2], tot, bit[M], tt1, tt2;
char s1[M], s2[M];
unordered_map<int, int>mp;
void getch() {
	tot1 = tot2 = 0;
	char c = getchar();
	while(c < 'a' || c > 'z')c = getchar();
	while(c >= 'a' && c <= 'z') {
		s1[++tot1] = c;
		c = getchar();
	}
	while(c < 'a' || c > 'z')c = getchar();
	while(c >= 'a' && c <= 'z') {
		s2[++tot2] = c;
		c = getchar();
	}
}
void calc_has() {
	for(int i = 1; i <= tot1; i++) {
		has1[i] = (1ll * has1[i - 1] * B + s1[i]) % MOD;
		has2[i] = (1ll * has2[i - 1] * B + s2[i]) % MOD;
	}
}
void get_has(int L, int R) {
	if(L > R || L < 1 || R > tot1)tt1 = tt2 = 0;
	else {
		tt1 = (has1[R] - 1ll * has1[L - 1] * bit[R - L + 1]) % MOD;
		tt2 = (has2[R] - 1ll * has2[L - 1] * bit[R - L + 1]) % MOD;
		if(tt1 < 0)tt1 += MOD;
		if(tt2 < 0)tt2 += MOD;
	}
}
vector<int>vec[M];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	bit[0] = 1;
	for(int i = 1; i <= 25e5; i++)bit[i] = (1ll * bit[i - 1] * B) % MOD;
	for(int i = 1; i <= n; i++) {
		getch();
		calc_has();
		siz[i] = tot1;
		has[i][0] = has1[tot1], has[i][1] = has2[tot2];
		l[i] = 1, r[i] = tot1;
		while(l[i] <= tot1 && s1[l[i]] == s2[l[i]])l[i]++;
		while(r[i] >= 1 && s1[r[i]] == s2[r[i]])r[i]--;
		get_has(l[i], r[i]);
		if(!mp[(127ll * tt1 + tt2) % MOD])mp[(127ll * tt1 + tt2) % MOD] = ++tot;
		vec[mp[(127ll * tt1 + tt2) % MOD]].push_back(i);
	}
	while(q--) {
		getch();
		int ans = 0;
		if(tot1 != tot2)putchar('0');
		else {
			calc_has();
			int L = 1, R = tot1;
			while(L <= tot1 && s1[L] == s2[L])L++;
			while(R >= 1 && s1[R] == s2[R])R--;
			get_has(L, R);
			int gi = mp[(127ll * tt1 + tt2) % MOD];
			if(gi) {
				for(int i = 0; i < vec[gi].size(); i++) {
					int j = vec[gi][i];
					get_has(L - l[j] + 1, R + siz[j] - r[j]);
					if(tt1 == has[j][0] && tt2 == has[j][1])ans++;
				}
			}
			write(ans);
		}
		putchar('\n');
	}
	return 0;
}