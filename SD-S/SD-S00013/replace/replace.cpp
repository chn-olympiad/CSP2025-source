#include <iostream>

#define int long long
const int N = 2e5 + 5;
int n, q;
std::string s[N][3];
std::string t1, t2;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 10) write(x / 10);
	putchar(x % 10 + '0');
}

signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for (int i = 1; i <= n; i++) 
		std::cin >> s[i][1] >> s[i][2];
	while (q--) {
		int ans = 0;
		std::cin >> t1 >> t2;
		int len = t1.length();
		for (int i = 1; i <= n; i++) {
			for (int l = 0; l + s[i][1].length() - 1 < len; l++) {
				std::string t = t1;
				bool ok = true;
				for (int r = l, p = 0; r <= l + s[i][1].length() - 1 && p < s[i][1].length() && r < len; r++, p++) {
					t[r] = s[i][2][p];
					if (t1[r] != s[i][1][p]) {
						ok = false;
						break;
					}
				}
				if (!ok) continue;
				if (t == t2) ans++;
			} 
		} 
		write(ans);
		putchar('\n');
	} 
	fclose(stdin);
	fclose(stdout);
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
