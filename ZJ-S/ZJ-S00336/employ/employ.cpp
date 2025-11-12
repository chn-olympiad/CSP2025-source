#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mod=998244353,ans,cs[111111],vis[1111],eo=0;
string s;
void dfs(int x,int u,int c){
	if(x==n){
		if(u>=m)ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='0'){
				dfs(x+1,u,c+1);
			}
			else{
				if(c<cs[i])dfs(x+1,u+1,c);
				else dfs(x+1,u,c+1);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>cs[i];
	for(int i=0;i<n;i++)eo+=(s[i]=='1');
	if(n<=10){
		dfs(0,0,0);
		cout<<ans;
	}
	else if(eo==n){
		ans=1;
		int fi=0,iu=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1')fi=0;
		}
		for(int i=1;i<=n;i++)if(cs[i]>=fi)iu++;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}
