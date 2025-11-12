#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
string s;
int a[505];
int vis[505];
int ans=0;
void dfs(int x,int y){
	if(x==n+1){
		if(y>=m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if((x-1-y)>a[i]||s[x]=='0') dfs(x+1,y);
		else dfs(x+1,y+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
}
