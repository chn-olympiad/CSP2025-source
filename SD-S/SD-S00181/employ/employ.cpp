#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,mod=998244353,zong1;
char ch[505];
int c[505],vis[505],shu[505],viss[505];
void dfs(int xian){
	if(xian==n+1){
		int qian=0,anss=0;
		for(int i=1;i<=n;i++){
			if(ch[i]=='0') ++qian;
			else{
				if(qian>=c[vis[i]]) ++qian;
				else ++anss;
			}
		}
		if(anss==m){
			++ans;
		}
		return;
	}
	for(int i=1;i<=n;i++)
		if(viss[i]==0){
			vis[xian]=i;
			viss[i]=1;
			dfs(xian+1);
			viss[i]=0;
			vis[xian]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch[i];
		if(ch[i]=='1') zong1++;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(zong1<m){
		cout<<0;
		return 0;
	}
	if(n<=18){
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
}
