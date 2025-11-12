#include<bits/stdc++.h>
using namespace std;
long long n,m,c[600],ans,mod=998244353,vis[600];
string s;
void dfs(long long l,long long ot){
	if(l>n){
		ans=(ans+1)%mod;
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			if(ot>=c[i]||!(s[l]-'0')){
				if(n-ot-1<m) return ;
				vis[i]=1;
				dfs(l+1,ot+1);
				vis[i]=0;
			}
			else{
				vis[i]=1;
				dfs(l+1,ot);
				vis[i]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(long long i=1;i<=n;i++) cin>>c[i];
	bool f=1;
	for(long long i=1;i<=n;i++){
		if(!(s[i]-'0')){
			f=0;
			break;
		}
	}
	if(f){
		ans=1;
		for(long long i=n;i>1;i--){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
