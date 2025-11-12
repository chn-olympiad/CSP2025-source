#include <bits/stdc++.h>
const int N = 2e3+5;

struct give_n {
	char a1[N], a2[N];
	int len;
} g[1005];
char x1[N], x2[N], x3[N];
int len1, len2;
bool f[N];

void check1(int in, int l) {
	for (int i = 1; i <= len1; i++) {
		x3[i] = x1[i];
	}
	bool ff = 0;
	for (int i = 1; i <= len1 - l + 1; i++) {
		for (int j = 1; j <= len1; j++) {
			x3[j] = x1[j];
		}
		for (int j = i; j <= i + l - 1; j++) {
			x3[j] = g[in].a2[j - i + 1];
		}
		for (int j = 1; j <= len1; j++) {
			if (x3[j] != x2[j]) {
				ff = 1;
				break;
			}
		}
		if (!ff) {
			f[in] = 1;
		}
	}
}

void check2(int in, int l) {
	for (int i = 1; i <= len1; i++) {
		x3[i] = x2[i];
	}
	bool ff = 0;
	for (int i = 1; i <= len1 - l + 1; i++) {
		for (int j = 1; j <= len1; j++) {
			x3[j] = x2[j];
		}
		for (int j = i; j <= i + l - 1; j++) {
			x3[j] = g[in].a2[j - i + 1];
		}
		for (int j = 1; j <= len1; j++) {
			if (x3[j] != x1[j]) {
				ff = 1;
				break;
			}
		}
		if (!ff) {
			f[in] = 1;
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i].a1 + 1);
		scanf("%s", g[i].a2 + 1);
		g[i].len = strlen(g[i].a1 + 1);
	}
	while (q--) {
		scanf("%s", x1 + 1);
		scanf("%s", x2 + 1);
		memset(f, 0, sizeof f);
		len1 = strlen(x1 + 1), len2 = strlen(x2 + 1);
		if (len1 != len2) {
			puts("0");
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int l = g[i].len;
			check1(i, l), check2(i, l);
		}
		for (int i = 1; i <= n; i++) {
			if (f[i])
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/