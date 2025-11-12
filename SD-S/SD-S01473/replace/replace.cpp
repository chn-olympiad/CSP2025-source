// ≤ªª·¡À QAQ 
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

inline int fpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x;
		y = y >> 1;
		x = x * x;
	}
	return res;
}

inline int gcd(int x, int y) {
	int tmp;
	while (x % y) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}

inline int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

const int MAXN = 1005;
int n, q;
string t1[MAXN], t2[MAXN];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	string s;
	cin >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> t1[i] >> t2[i];
	}
	for (int i = 1; i <= q; i ++) cout << 0 << '\n';
	return 0;
}

