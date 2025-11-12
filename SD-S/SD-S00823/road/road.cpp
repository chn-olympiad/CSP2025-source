#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, k;
const int N = 1e5 + 10;
const int M = 1e6 + 10; 
int a[N], b[N], c[N];
int ans;
signed main(){
freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i ++ ){
		int u, v ,w;
		u = read(), v = read(), w = read();
		ans += w;
	}
	for(int i = 1; i <= k; i ++ ){
		c[i] = read(), b[i] = read();
	}
	cout << ans;
	return 0;
}
