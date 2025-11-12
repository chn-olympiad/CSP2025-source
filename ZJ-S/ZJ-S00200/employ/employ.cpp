#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N],suf[N],fac[N],ans;
bool vis[N];
void dfs(int pos,int notuse,int use){
	if(use>=m){
		ans=(ans+fac[n-pos+1])%mod;
		return;
	}
	if(suf[pos]+use<m)return;
	if(pos>n)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(notuse<c[i]&&s[pos])dfs(pos+1,notuse,use+1);
		else dfs(pos+1,notuse+1,use);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]+s[i];
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
