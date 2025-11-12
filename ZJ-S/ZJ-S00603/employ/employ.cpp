#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
char a[1010];
int p[1010];
int vis[1010];
int ans,md=998244353;
void dfs(int x,int y){
//	cout<<x<<" "<<y<<endl;
//	if(x-y>m){
//		return ;
//	}
	if(x==n&&(x-y)>=m){
		ans++;
		ans%=md;
	}
	if(x==n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(a[x]=='1'&&y<p[i]){
			dfs(x+1,y);
		}
		else{
			dfs(x+1,y+1);
		}
		vis[i]=0;
	}
	return ;
}//x表示到第几个人了，y表示放弃或拒绝了几人 
void dfs1(int x,int y){
//	cout<<x<<" "<<y<<endl;
//	if(x-y>m){
//		return ;
//	}
	if(y>=1) return ;
	if(x==n&&(x-y)>=m){
		ans++;
		ans%=md;
	}
	if(x==n){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(a[x]=='1'&&y<p[i]){
			dfs(x+1,y);
		}
		vis[i]=0;
	}
	return ;
}//x表示到第几个人了，y表示放弃或拒绝了几人
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	if(m==n){
		dfs1(0,0);	
	}
	else{
		dfs(0,0);
	}
	cout<<ans;
	return 0;
}
