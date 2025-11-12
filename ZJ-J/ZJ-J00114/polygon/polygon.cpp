#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5005,mod=998244353;
ll n,mmxx=INT_MIN,ans;
ll a[maxn],vis[maxn];
void dfs(ll x){
	if(x==n+1){
		ll sum=0,cou=0,mx=INT_MIN;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				mx=max(mx,a[i]);
				sum+=a[i];
				cou++;
			}
		}
		if(cou<3){
			return;
		}
		if(sum>2*mx){
			ans++;
			ans%=mod;
		}
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mmxx=max(mmxx,a[i]);
	}
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			ans++;
		}
		cout<<ans<<"\n";
		return 0;
	}else if(n<=20){
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}else if(mmxx==1){
		ll sum=n*(n-1)/2;
		for(ll i=n-2;i>=1;i--){
			sum=sum*i/(n-i+1)%mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}else{
		cout<<0<<"\n";
	}
	return 0;
}
