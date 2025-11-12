#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5],tt,ans,vis[100010];
void dfs(int i,int num,int x,int y,int z){
	if(i>n){
		ans=max(ans,num);
		return;
	}
	if(x<tt && vis[i]==0)vis[i]=1,dfs(i+1,num+a[i][1],x+1,y,z),vis[i]=0;
	if(y<tt && vis[i]==0)vis[i]=1,dfs(i+1,num+a[i][2],x,y+1,z),vis[i]=0;
	if(z<tt && vis[i]==0)vis[i]=1,dfs(i+1,num+a[i][3],x,y,z+1),vis[i]=0;
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
  	cin>>n;
  	memset(vis,0,sizeof(vis)); 
  	tt=n/2;
  	ans=0;
  	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
  	dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
