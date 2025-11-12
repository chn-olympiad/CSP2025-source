#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5100],s[5100],ans,u[5100];
void dfs(ll p,ll m,ll h,ll x){
	if(p>=3){
		if(h>m*2){
			ans++;
			ans%=998244353;
		}
		if(x==n+1){
			return ;
		}
	}
	for(int i=x;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			dfs(p+1,max(m,a[i]),h+a[i],i);
			u[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll ma=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1){
		ans=1;
		for(int i=1;i<=n-2;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs((ll)0,(ll)0,(ll)0,(ll)1);
	cout<<ans;
	return 0;
}
