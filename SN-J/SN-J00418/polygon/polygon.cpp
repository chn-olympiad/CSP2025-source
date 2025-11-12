#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], sum, maxx, ans = 1;
bool f = 1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(a[i], maxx);
		sum += a[i];
		if (a[i] != 1){
			f = 0;
		}
	}
	if (n == 3){
		if (sum > maxx * 2){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else if (f){
		for (int i = 3; i <= n; i++){
			for (int j = 1; j <= i; j++){
				ans = (ans % 998244353 * (n - i + 1) % 998244353) % 998244353;
				ans = ans % 998244353;
			}
		}
		cout << ans;
	}
	else{
		cout << 998244352;
	}
	return 0;
}
