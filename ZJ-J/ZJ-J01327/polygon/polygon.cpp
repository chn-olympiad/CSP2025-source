#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,MOD=998244353;
ll n,a[N],ans;
void f(ll d,ll maxn,ll sum,ll last){
	if(d>3) if(maxn*2<sum) ans=(ans+1)%MOD;
	if(d>n) return;
	for(ll i=last+1;i<=n;i++){
		f(d+1,max(maxn,a[i]),sum+a[i],i);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(1,0,0,0);
	cout<<ans%MOD<<"\n";
	return 0;
}
