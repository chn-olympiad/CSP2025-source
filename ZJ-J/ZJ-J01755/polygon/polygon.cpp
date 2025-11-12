#include <bits/stdc++.h>

#define F freopen("polygon.in", "r", stdin);freopen("polygon.out", "w", stdout)

#define LL long long

const LL Mod = 998244353;

using namespace std;

LL qp(LL a, LL b, LL Mod) {
	LL res = 1;
	while(b) {
		if(b & 1) res = res * a % Mod;
		a = a * a % Mod;
		b >>= 1;
	}
	return res;
}

LL f(LL x) {
	LL res = 1;
	for(LL i = x; i >= 2; i--) {
		res *= i;
		res %= Mod;
	}
	return res % Mod;
}


LL a[5005];
LL n, res = 0;

int main (void) {
	
	F;
	
	cin >> n;
	
	LL maxv = 0;
	
	for(LL i = 1; i <= n; i++) {
		cin >> a[i];
		
		maxv = max(maxv, a[i]);
	}
	
	sort(a + 1, a + 1 + n);
	
	if(maxv == 1) {
		LL res = 0;
		LL k = f(n) % Mod;
		for(LL i = 3; i <= n; i++) {
			res += k / ((1ll * f(i) % Mod * f(n - i) % Mod) % Mod) % Mod;
			res %= Mod;
		}
		cout << res;
		return 0;
	} else if(n == 3) {
		sort(a + 1, a + 1 + n);
		
		if(a[1] + a[2] > a[3]) cout << 1;
		else cout << 0;
		
		return 0;
	} else if(n <= 10) {
		for(int a1 = 1; a1 <= n; a1++) {
			for(int a2 = a1 + 1; a2 <= n; a2++) {
				for(int a3 = a2 + 1; a3 <= n; a3++) {
					if(a[a1] + a[a2] + a[a3] > 2 * a[a3]) res++;
					for(int a4 = a3 + 1; a4 <= n; a4++) {
						if(a[a1] + a[a2] + a[a3] + a[a4] > 2 * a[a4]) res++;
						for(int a5 = a4 + 1; a5 <= n; a5++) {
							if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] > 2 * a[a5]) res++;
							for(int a6 = a5 + 1; a6 <= n; a6++) {
							if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] > 2 * a[a6]) res++;
								for(int a7 = a6 + 1; a7 <= n; a7++) {
									if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] > 2 * a[a7]) res++;
									for(int a8 = a7 + 1; a8 <= n; a8++) {
										if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] > 2 * a[a8]) res++;
										for(int a9 = a8 + 1; a9 <= n; a9++) {
											if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] > 2 * a[a9]) res++;
											for(int ax = a9 + 1; ax <= n; ax++) {
												if(a[a1] + a[a2] + a[a3] + a[a4] + a[a5] + a[a6] + a[a7] + a[a8] + a[a9] + a[ax] > 2 * a[ax]) res++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << res;
	}
	return 0;
}
