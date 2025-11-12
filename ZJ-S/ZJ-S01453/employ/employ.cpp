#include <bits/stdc++.h>
#define debug cout << "\n------------debug------------\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 LLL;
typedef pair <int, int> PII;
typedef pair <LL, int> PLI;
typedef pair <int, LL> PIL;
typedef pair <LL, LL> PLL;

inline LL read() {
	LL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

inline void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	return 0;
}

