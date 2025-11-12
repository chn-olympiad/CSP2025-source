#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll n,m;
ll a[100];
bool vis[100]={0};
ll A(ll n){
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
ll dfs(ll pos,ll cnt=0,ll f=0){
	if(f>=a[pos]||s[cnt]=='0'){
		f++;
	}
	if(cnt==n-1){
		return cnt+1-f>=m;
	}
	vis[pos]=1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])ans+=dfs(i,cnt+1,f);
		ans%=998244353;
	}
	vis[pos]=0;
	return ans; 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=dfs(i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

