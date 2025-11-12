#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0,  f = 1;
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
int n, k, a[1000005], pre[2000005], g[2000005], f[2000005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(); k = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	for(int i = 0; i <= 2000000; ++i) {
		pre[i] = -1;
	}
	pre[0] = 0;
	int now = 0;
	for(int i = 1; i <= n; ++i) {
		now ^= a[i];
		if(pre[now ^ k] != -1) {
			g[i] = pre[now ^ k];
		}
		else	g[i] = -1;
		pre[now] = i;
	}
	f[0] = 0;
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
		if(g[i] != -1) {
			f[i] = max(f[i], f[g[i]] + 1);
		}
	}
	cout<<f[n];
	return 0;
}
