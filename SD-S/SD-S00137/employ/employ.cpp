#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n;
	ll ans=1;
	for(ll i=2;i<=n;i++){
		ans*=i;
		ans%=m;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
17:46 本来已经放弃希望，忽然看到特殊性质A。 
(～￣▽￣)～ 
*/

/*
总结：
A题(club)可能有部分分；
B题(road)暴力都不会； 
C题(replace)暴力没调完； 
D题(employ)特殊性质A应该能过； 
应该不会爆零了。
2025.11.1
*/
