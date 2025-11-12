#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;

ll n,m;
string s;
ll a[550];
ll vis[550];
ll x=0;
ll dfs(ll step,ll t){
	if(n-t<m)return 0;
	if(step==n+1){
		x++;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(t>=a[i]||s[step-1]=='0')dfs(step+1,t+1);
		else dfs(step+1,t);
		vis[i]=0;
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll t=1000;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				t=i;
				break;
			}
		}
		ll cnt=0,ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]>t)cnt++;
		}
		for(int i=1;i<=n-1;i++){
			ans=ans*i%mod;
		}
		ans=ans*cnt%mod;
		cout<<ans;
		return 0;
	}else if(m==n){
		ll flag=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0')flag=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0)flag=1;
		}
		if(flag){
			cout<<0;
			return 0;
		}else{
			ll ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
			cout<<ans;
			return 0;
		}
	}
	ll flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')flag=1;
	}
	if(!flag){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<x;
	return 0;
}
