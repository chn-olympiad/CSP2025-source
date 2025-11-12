#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5000+10;
const int mod=998244353;
ll n,a[N],ans;
void dfs(ll x,ll sum,ll maxn,ll cnt){
	if(x>n){
		if(cnt>2&&sum>maxn*2) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,sum,maxn,cnt);
	dfs(x+1,sum+a[x],a[x],cnt+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=350)dfs(1,0,0,0);
	else{
		ll temp=2;
		for(ll i=2;i<n;i++){
			ll t=1;temp*=(i+1);
			for(ll j=n-i;j<=n;j++)
				t=(t*j)%mod;
			ans=(ans+t/temp)%mod;
		}
	}
	cout<<ans;
    return 0;
}


