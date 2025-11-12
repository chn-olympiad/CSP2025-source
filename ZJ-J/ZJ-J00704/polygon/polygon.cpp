#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define N 50500
#define MOD 998244353
using namespace std;

int n, a[N], ans;

int qpow(int a, int b){
	if(!b) return 1;
	int base = a, res = 1;
	while(b){
		if(b & 1) res = (res * base) % MOD;
		b >>= 1;
		base = (base * base) % MOD;
	}
	return res % MOD;
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[n] == a[1]){
		cout << (qpow(2, n) % MOD - n * (n - 1) / 2 - n - 1 + MOD) % MOD;
	}
	else{
		for(int i = 1;i < (1 << n);i ++){
			int maxn = 0, sum = 0, cnt = 0;
	//		cout << "case " << i << ":";
			for(int j = 1;j <= n;j ++){
				if(i & (1 << (j - 1))){
					maxn = max(maxn, a[j]);
					sum += a[j];
					cnt ++;
	//				cout << " " << a[j];
				}
			}
	//		cout << endl;
			if(sum > 2 * maxn && cnt >= 3) ans = (ans + 1) % MOD;
		}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
