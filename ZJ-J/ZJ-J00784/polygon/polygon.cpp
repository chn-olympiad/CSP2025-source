# include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans, cnt;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int maxn;
	for (int i = 1; i<=n; ++i){
		scanf("%d", a+i);
		maxn = max(maxn, a[i]);
		if (a[i] == 1) cnt++;
	}
	if (n == 3){
		if ((a[1] + a[2] + a[3]) > 2 * max(a[1], max(a[2], a[3]))) cout << 1;
		else cout << 0;
	}
	if (maxn = 1){
		for (int i = 3; i<=n; ++i){
			long long  t = 1;
			for(int j = 1; j<=i; ++j){
				t*= cnt-i+1;
				t /= j; 
			}
			ans += t;
			ans %= 998244353;
		}
		cout << ans << endl;
	}
	return 0;
}
