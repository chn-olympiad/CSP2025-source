#include<bits/stdc++.h>

#define int long long

namespace IO {
	inline int read() {
		int ret = 0, f = 1;char ch = getchar();
		while (ch < '0' || ch > '9') {
			if (ch == '-') f = -f;
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9') {
			ret = (ret << 1) + (ret << 3) + (ch ^ 48);
			ch = getchar();
		}
		return ret * f;
	}
	void write(int x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
}

using namespace IO;
using namespace std;

const int Mod = 998244353;
const int maxn = 500 + 5;

int n, m;
string s;
int c[maxn];
int p[maxn];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = read(), m = read();
	cin >> s;s = "#" + s;
	
	int cnt = 0;
	for (int i = 1;i <= n;i++) c[i] = read(), cnt += c[i] > 0;
	
	int flg = 1;
	for (int i = 1;i <= n;i++) if (s[i] == '0') flg = 0;
	
	if (flg) {
		if (cnt < m) {
			write(0), putchar(10);
			return 0;
		}
		
		int ans = 1;
		
		for (int i = 1;i <= n;i++) (ans *= i) %= Mod;
		
		write(ans), putchar(10);
		return 0;
	}
	
	iota(p + 1, p + 1 + n, 1);
	
	int ans = 0;
	do {
//		for (int i = 1;i <= n;i++) cout << p[i] << ' ';putchar(10);
		int pre = 0, Cnt = 0, now = 1;
		for (int i = 1;i <= n;i++) {
//			cout << i << ' ' << c[p[i]] << ' ' << pre << ' ' << cnt << ' ' << now << '\n';
			if (pre >= c[p[i]]) {
				pre++;
				continue;
			}
			if (s[now] == '0') pre++;
			else Cnt++;
			now++;
		}
		ans += Cnt >= m;ans %= Mod;
	} while (next_permutation(p + 1, p + 1 + n));
	
	write(ans), putchar(10);
	
	return 0;
}
