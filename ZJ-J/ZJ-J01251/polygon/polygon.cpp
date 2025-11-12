/*
2025/11/1
luogu:Zhangletian
daociyiyou
hahaha
MC KKCraft
ping jia:
A:hong
B:hong
C:huang
D:shangweilv~xiaweilan (tai nan da bao li le)
mubiao score:370+
shiji yugu:364
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int a[5010];
int sum[5010];
int C(int x, int y) {
	int f_x = 1;
	for(int i = 2; i <= x; i++) f_x *= i;
	int f_y = 1;
	for(int i = 2; i <= y; i++) f_y *= i;
	for(int i = 2; i <= (x - y); i++) f_y *= i;
	return f_x / f_y;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[a[i]]++;
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1];
	}
	if(n <= 25) {
		int res = 0;
		int jl = 1 << n;
		for(int i = 5; i <= jl; i++) {
			int must = 0, id = n/*muqian*/, sum_a = 0, mx = 0;
//			cout << i << ' ' << jl << endl;
			int I = i;
			while(I > 0) {
				if(I & 1) {
					must++;
					sum_a += a[id];
					mx = max(mx, a[id]);
				}
				I >>= 1;
				id--;
			}
			if(must >= 3 && sum_a > mx * 2) {
				res++;
			}
		}
		cout << res << endl;
	} else {
		int gong = C(n, 3);
		n -= 3;
		int w = 1;
		for(int i = 1; i <= n; i++) {
			gong += C(n, i);
		}
		cout << gong << endl;
	}
	return 0;
}