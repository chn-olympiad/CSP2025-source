#include<bits/stdc++.h>
using namespace std;
#define maxn 514
#define mod 998244353
string s;
int n,m,c[maxn];
int vis[maxn];
int ans=0;
void dfs(int k,int tot,int non){
	if(k>n){
		if(tot>=m)ans++,ans%=mod;
		return;
	}
	if(n-k+1<m-tot)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(non>=c[i]||s[k-1]=='0'){
			dfs(k+1,tot,non+1);
		}else{
			dfs(k+1,tot+1,non);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
