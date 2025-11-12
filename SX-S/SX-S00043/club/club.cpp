#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, a[3][100005], cnt[3], b[100005], pos[3], op[100005];
long long ans;
void work() {
	n = read();
	cnt[0] = cnt[1] = cnt[2] = 0;
	pos[1] = 1;
	pos[0] = 0;
	pos[2] = 2;
	ans = 0;
	for(int i = 1; i <= n; ++i) {
		a[0][i] = read(); a[1][i] = read(); a[2][i] = read();
		if(a[0][i] >= a[1][i] && a[0][i] >= a[2][i]) {
			ans += a[0][i];
			++cnt[0];
			op[i] = 0;
		}
		else if(a[1][i] >= a[0][i] && a[1][i] >= a[2][i]) {
			ans += a[1][i];
			++cnt[1];
			op[i] = 1;
		}
		else {
			ans += a[2][i];
			++cnt[2];
			op[i] = 2;
		}
	}
	if(cnt[1] > cnt[0]) {
		swap(cnt[0], cnt[1]);
		swap(a[0], a[1]);
		swap(pos[0], pos[1]);
	}
	if(cnt[2] > cnt[0]) {
		swap(cnt[2], cnt[0]);
		swap(a[2], a[0]);
		swap(pos[0], pos[2]);
	}
	if(cnt[0] <= n / 2) {
		printf("%lld\n", ans);
		return;
	}
	int tmp = 0;
	for(int i = 1; i <= n; ++i) {
		if(op[i] != pos[0])	continue;
		b[++tmp] = a[0][i] - max(a[1][i], a[2][i]);
	}
	sort(b + 1, b + tmp + 1);
	for(int i = 1; i <= tmp; ++i) {
		--cnt[0];
		ans -= b[i];
		if(cnt[0] <= n / 2)	break;
	}
	printf("%lld\n", ans);
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while(T--) {
		work();
	}
	return 0;
}
