#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m,c[505];
string s;
ll jc[505];
ll ans;
bool vis[20];
void dfs(int cur,int rej,int now){
	if(cur>n){
		if(now>=m) ans++;
		return;
	}
	if(now>=m){
		ans+=jc[n-cur+1];
		ans%=mod;
		return;
	}
	if(n-cur+1+now<m) return;
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=true;
		if(rej>=c[i]||s[cur]=='0') dfs(cur+1,rej+1,now);
		else dfs(cur+1,rej,now+1);
		vis[i]=false;
	}
}
ll qpow(ll x,int p){
	ll ans=1;
	while(p>0){
		if(p&1) ans=ans*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ans;
}
ll inv(ll x){
	return qpow(x,mod-2);
}
ll A(int n,int m){
	return jc[n]*inv(jc[n-m])%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
		
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<jc[n];
		return 0;
	}
	if(m==1){
		sort(c+1,c+n+1);
		ll ans=1;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				int l=upper_bound(c+1,c+n+1,i-1)-c;
				
				ans*=(l-i-1+tot)%mod;
				ans%=mod;
			}
			else tot++;
		}
		ans*=jc[tot];
		ans%=mod;
		ans=(jc[n]-ans+mod)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod;
	
	return 0;
}
