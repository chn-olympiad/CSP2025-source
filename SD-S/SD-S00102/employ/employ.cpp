#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const ll N=1e5+5,mod=998244353;
ll n,m,ans;
string t;
ll c[N];
ll f[N];
bool v[N];
void dfs(ll id,ll day,ll e,ll fal){
	if(day==n+1){
		if(e>=m){
			ans++;
			ans%=mod;	
		}
		return;
	}
	for(ll i=1;i<=n+1;i++){
		if(!v[i]){
			v[i]=1;
			if(c[id]<=fal){
				dfs(i,day+1,e,fal+1);
			}
			if(c[id]>fal&&t[day-1]=='1'){
				dfs(i,day+1,e+1,fal);
			}
			if(c[id]>fal&&t[day-1]!='0'){
				dfs(i,day+1,e,fal+1);
			}
			v[i]=0;
		}
	}
}
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>t;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	for(ll i=0;i<t.size();i++){
		if(t[i]!='1')flag=1;
	}
	if(!flag){
		ans=1;
		for(ll i=1;i<=n;i++){
			if(ans>=mod)ans%=mod;
			ans*=i;
		}
		ans%=mod;
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(i,1,0,0);
			v[i]=0;
		}
	}
	cout<<ans%mod;
	return 0;
}
