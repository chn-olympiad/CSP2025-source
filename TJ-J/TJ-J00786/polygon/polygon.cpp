#include <bits/stdc++.h> 
using namespace std;

#define mod 998244353

int A(int m, int n){
	int t = 1;
	for(int i = m; i >= m - n + 1; i--)
		t *= i;
	return t;
}

int C(int m, int n){
	return A(m, n) / A(n, n);
}

int main(){
	freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, a[5010], dp[5010], tp = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	tp = max(tp, a[i]);
	}
	if(n == 3){
		if(a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3]))){
			cout << "1";
			return 0;
		}else{
			cout << "0";
			return 0;
		}
	}
	if(tp == 1){
		int ans = 0;
		for(int i = 3; i <= n; i++)
			ans = (ans + C(n, i)) % mod;
		cout << ans % mod;
		return 0;
	}
	return 0;
}
