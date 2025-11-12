#include <cstdio>
#include <algorithm> 
using namespace std;

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar(); 
	}
	return num;
}

int n, a[100000][3], b[100000];

void init() {
	n = read();
	for (int i = 0; i < n; i ++) {
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
	}
	return;
}

void calculate() {
	int ans = 0, cnt[3] = {0, 0, 0};
	for (int i = 0; i < n; i ++) {
		if (a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
			ans += a[i][0], cnt[0] ++;
		} else if (a[i][1] > a[i][2]) {
			ans += a[i][1], cnt[1] ++;
		} else {
			ans += a[i][2], cnt[2] ++; 
		}
	}
	if (cnt[0] > (n >> 1) || cnt[1] > (n >> 1) || cnt[2] > (n >> 1)) {
		ans = 0;
	}
	for (int d = 0; d < 3; d ++) {
		int sm = 0;
		for (int i = 0; i < n; i ++) {
			sm += a[i][d];
			if (a[i][(d + 1) % 3] > a[i][(d + 2) % 3]) {
				b[i] = a[i][(d + 1) % 3] - a[i][d];
			} else {
				b[i] = a[i][(d + 2) % 3] - a[i][d];
			}
		}
		sort(b, b + n);
		for (int i = n >> 1; i < n; i ++) {
			sm += b[i];
		}
		if (sm > ans) {
			ans = sm;
		}
	}
	printf("%d\n", ans);
	return;
}

void solve() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T --) {
		init(), calculate(); 
	}
	return;
}

int main() {
	solve();
	return 0;
}