// Ãÿ ‚–‘÷ AB QWQ 
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

const int MAXN = 500005;
int n;
struct club {
	long long a, b, c, tmp;
} a[MAXN];

bool cmp(club x, club y) {
	return x.tmp > y.tmp;
}

void solve() {
	n = read();
	for (int i = 1; i <= n; i ++) {
		a[i].a = read(), a[i].b = read(), a[i].c = read();
		a[i].tmp = a[i].b - a[i].a;
	}
	int cnt1 = 0, cnt2 = 0;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (cnt1 <= n / 2 && a[i].tmp > 0) {
			cnt1 ++;
			ans += a[i].b;
		}
		else if (cnt2 <= n / 2){
			cnt2 ++;
			ans += a[i].a;
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T --) solve();
	return 0;
}

