#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
string s;
ll n,m,c[505],a[505],ans,cnt,tag;
bool vis[505];
bool check(){
	ll cnt=0,sum=0;
	for(ll i=1;i<=n;i++){
		if(cnt>=c[a[i]])cnt++;
		else{
			if(s[i]=='0')cnt++;
			else sum++;
		}
	}
	return sum>=m;
}
void dfs(ll x){
	if(x==n+1){
		ans=(ans+check())%MOD;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[++cnt]=i;
			dfs(x+1);
			vis[i]=0;
			a[cnt--]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	for(ll i=1;i<s.size();i++){
		if(s[i]!='1')tag=1;
	}
	if(tag==0){
		ans=1;
		for(ll i=1;i<=n;i++)ans=ans*i%MOD;
		cout<<ans;
		return 0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
