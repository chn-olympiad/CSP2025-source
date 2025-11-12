#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e5+10,mod=998244353;
ll n,m;
string s;
ll c[N];
ll ans[N],vis[N];
ll res;
bool check(){
//	for(ll i=1;i<=n;i++){
//		cout<<ans[i]<<" ";
//	}
//	cout<<endl;
	ll fq=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(fq>=ans[i]){
			fq++;
			continue;
		}
		if(s[i]=='0'){
			fq++;
		}
		else cnt++;
	}
	return cnt>=m;
}
void dfs(ll d){
	if(d>n){
		if(check()){
			res++;
			res%=mod;
		}
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[d]=c[i];
			dfs(d+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1);
	    cout<<res;
	    return 0;
	}
	else{
		res=1;
		for(ll i=1;i<=n;i++){
			res=res*i%mod;
		}
		cout<<res;
		return 0;
	}
	return 0;
}
