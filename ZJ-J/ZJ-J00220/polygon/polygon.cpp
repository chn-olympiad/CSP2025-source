#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[10000];
ll md=998244353;
ll dp[50010];
ll pw(ll x,ll y){
	ll ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
		ans%=md;
	}
	return ans;
}
ll as=0;
void dfs(int dep,ll mx,ll sum,int c){
	if(dep>n){
		if(c>=3){
			if(2*mx<sum){
				as++;
			}
		}
		return ;
	}
	dfs(dep+1,max(mx,a[dep]),sum+a[dep],c+1);
	dfs(dep+1,mx,sum,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
		return 0;
	}else if(mx==1){
		ll tem=pw(2,n);
		ll x=1;
		ll y=n;
		ll z=n*(n-1)/2;
		cout<<(((tem-1+md)%md-y+md)%md-z+md)%md<<'\n';
		return 0;
	}else if(n<=20){
		dfs(1,0,0,0);
		cout<<as<<'\n';
		return 0;
	}else if(n<=500){
		ll ans=0;
		sort(a+1,a+1+n);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=50000;j>=a[i];j--){
				dp[j]=(dp[j]+dp[j-a[i]]%md)%md;
				if(j>=a[i]*2+1&&dp[j-a[i]]!=0&&i>=3){
					ans=(ans+dp[j])%md;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
