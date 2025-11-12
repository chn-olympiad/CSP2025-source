// SD-S01603

#include <bits/stdc++.h>

using namespace std;

inline int read () {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}

	return x * f;
}

int n, q;

signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	n = read(); q = read();
	
	while (q --) {
		printf("0\n");
	}
	
	return 0;
}









