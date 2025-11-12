#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n , k , maxx = -99999999 , d[100005] , ans , a[100005] ;
void dg(int x){
	if(x == n + 1){
		ll num = 0 , maxx = -999999999 , skdfhailkj;
		for(int i = 1 ; i <= n ; i ++){
			if(d[i] == 1){
				if(d[i - 1] == 0) skdfhailkj ++ ;
				num ^= a[i] ;
			}else{
				maxx = max(maxx , num) ;
			}
		}
		if(maxx <= k){
			ans = max(ans , skdfhailkj) ;
		}
		return ;
	}else{
		for(d[x] = 0 ; d[x] <= 1 ; d[x] ++){
			dg(x + 1) ;
		}
	}
}
int main(){
	freopen("xor.in" , "r" , stdin) ;
	freopen("xor.out" , "w" , stdout) ;
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i] ;
	}
	dg(1) ;
	cout << ans ;
}
