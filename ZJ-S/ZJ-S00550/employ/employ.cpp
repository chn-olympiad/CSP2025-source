#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7,mod=998244353;
int n,m,ans;
string s;
int a[N];
int vis[N];
void dfs(int dp,int x,int y){
	if(dp==n+1){
		if(y>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		if(x>=a[i]){
			dfs(dp+1,x+1,y);
		}else if(s[i-1]=='0'){
			dfs(dp+1,x,y+1);
		}else{
			dfs(dp+1,x+1,y);
		}
		vis[i]=0;
	}
}
signed main(){
	 freopen("employ.in","r",stdin);
	 freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
 
