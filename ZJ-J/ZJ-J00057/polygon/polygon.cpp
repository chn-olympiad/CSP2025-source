#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000008];
ll jiecheng(ll n){
	ll ans = 1;
	while(n > 1){
		ans *= n;
		n --;
		ans %= 998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ll n , s , ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	if(a[n] == 1){
		for(int i = 3; i <= n; i ++){
			ans += jiecheng(n) / jiecheng(n - i) / jiecheng(i);
			ans %= 998244353;
		}
	} else if(n <= 10){
		if(n <= 3){
			if(a[1] + a[2] > a[3]){
				ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
