#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define mp make_pair
using namespace std;
const ll N=1e5+10;
const ll INF=1e9;
const ll mod=998244353;
ll n,m,sum,num,ans,s[N],c[N],v[N];
ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-48;
		ch=getchar();
	}
	return ret*f;
}
ll t(ll b){
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	return ans%mod;
}
void dfs(ll sa,ll sb){
	if(n-sa<m-sb)return;
	if(sa==n){
		if(sb>=m)ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		if(sa-sb>=c[i]||s[sa+1]==0)dfs(sa+1,sb);
		else dfs(sa+1,sb+1);
		v[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char ch;
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-48;
		sum+=s[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)num++;
	}
	if(m==n){
		if(num!=0||sum!=n)cout<<0;
		else cout<<t(n);
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0; 
}
