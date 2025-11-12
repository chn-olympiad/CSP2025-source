#include <bits/stdc++.h>
using namespace std;
long long sum[5005], a[5005], n;
int max(int n, int m){
	long long max = -1;
	for(long long i = n;i <= m;i ++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i + 2;j <= n;j ++){
			long long num = sum[j] - sum[i - 1];
			long long maxn = max(i, j);
			if(num > 2 * maxn){
				ans ++;
				ans = ans % 998244353;
			}
		}
	}
	cout << ans % 998244353;	
	return 0;
}
