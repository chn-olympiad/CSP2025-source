#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , a[5001] , ans;
const int mod = 998244353;
int f(int x , int y){
	int res = 1 , cnt = 0;
	for(int i = 1;i <= y;i++){
		res = res * x;
		if(res >= mod){
			res %= mod;
			cnt++;
		}
		x--;
	}
	if(cnt % 2){
		res = (res + mod) / 2 % mod;
	}else{
		res /= 2;
	}
	return res;
}
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1 , a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i = 3;i <= n;i++){
			ans = (ans + f(n , i)) % mod;
		}
		cout<<ans;
	}
}
