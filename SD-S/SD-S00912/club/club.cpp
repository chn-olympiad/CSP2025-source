#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N][3], cho[N];
priority_queue <int, vector <int>, greater <int> > q;

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
void wrt(int x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
void solve() {
	int c0 = 0, c1 = 0, c2 = 0;
	rd(n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		rd(a[i][0]), rd(a[i][1]), rd(a[i][2]);
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) c0++, cho[i] = 0;
		else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) c1++, cho[i] = 1;
		else c2++, cho[i] = 2;
		ans += max(max(a[i][0], a[i][1]), a[i][2]);
	}
	if (c1 * 2 > n) {
		for (int i = 1; i <= n; i++) {
			swap(a[i][0], a[i][1]);
			if (cho[i] != 2) cho[i] ^= 1;
		}
		swap(c0, c1);
	}
	if (c2 * 2 > n) {
		for (int i = 1; i <= n; i++) {
			swap(a[i][0], a[i][2]);
			if (cho[i] != 1) cho[i] ^= 2;
		}
		swap(c0, c2);
	}
	while (q.size()) q.pop();
	for (int i = 1; i <= n; i++) {
		if (cho[i] == 0) q.push(a[i][0] - max(a[i][1], a[i][2]));
	}
	while (c0 * 2 > n) {
		int x = q.top(); q.pop();
		ans -= x;
		c0--;
	}
	wrt(ans), putchar(10);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; rd(T);
	while (T--) solve(); 
	return 0;
}

