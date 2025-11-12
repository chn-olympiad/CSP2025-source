#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	} if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
}
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int t, n, a[N][3], cnt[3], sum, idx, bel[N];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while(t--) {
		n = read();
		cnt[0] = cnt[1] = cnt[2] = sum = 0;
		for(int i = 1; i <= n; i++) {
			a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2])cnt[0]++, sum += a[i][0], bel[i] = 0;
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2])cnt[1]++, sum += a[i][1], bel[i] = 1;
			else cnt[2]++, sum += a[i][2], bel[i] = 2;
		}
		if(cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
			write(sum);
			putchar('\n');
			continue;
		}
		if(cnt[0] > n / 2)idx = 0;
		if(cnt[1] > n / 2)idx = 1;
		if(cnt[2] > n / 2)idx = 2;
		priority_queue<int>q;
		for(int i = 1; i <= n; i++) {
			int cmax = 0;
			if(bel[i] == idx) {
				for(int j = 0; j <= 2; j++)if(j != idx)cmax = max(cmax, a[i][j]);
				q.push(cmax - a[i][idx]);
			}
		}
		while(q.size() > n / 2) {
			sum += q.top();
			q.pop();
		}
		write(sum);
		putchar('\n');
	}
	return 0;
}