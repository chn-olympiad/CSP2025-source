#include<bits/stdc++.h>
using namespace std;
char a[17];
int b[17],nx[17],vis[17],n,m,ans;
void dfs(int c,int u,int tt){
	if(vis[u]!=0)
		return;
	vis[u]=1;
	for(int i=1;i<=n;i++){
		if(tt>=nx[u]||b[c]==0){
			dfs(c+1,i,tt+1);
		}else{
			dfs(c+1,i,tt);
		}
	}
	vis[u]=0;
	if(c==n){
		if((n-tt==m&&!(tt>=nx[u]||b[c]==0))||n-tt>m){
			ans++;
		}
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m; 
	cin>>a;
	for(int i=1;i<=n;i++){
		b[i]=a[i-1]-'0';
		cin>>nx[i];
	}
	for(int i=1;i<=n;i++)
		dfs(1,i,0);
	cout<<ans<<endl;
	return 0;
}