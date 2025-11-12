#include <bits/stdc++.h>
using namespace std;

inline int read();
void write(int);
void writeln(int);

const int N = 1e5 + 5;
int n, a[N][5], b[5], ans, c[N];
priority_queue <int> q[4];

void Clear() {
	ans = 0;
	for(int i = 1; i <= 3; i++) {
		c[i] = 0;
		while(!q[i].empty()) q[i].pop();
	}
	return ;
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T = read();
	while(T--) {
		Clear();
		n = read();
		for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) a[i][j] = read();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) b[j] = j;
			sort(b + 1, b + 4, [&](int x, int y) { return a[i][x] > a[i][y]; });
			c[b[1]]++, ans += a[i][b[1]], q[b[1]].push(a[i][b[2]] - a[i][b[1]]);
			for(int j = 1; j <= 3; j++) while(c[j] > n / 2) c[j]--, ans += q[j].top(), q[j].pop();
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}

inline int read() {
	int res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}
