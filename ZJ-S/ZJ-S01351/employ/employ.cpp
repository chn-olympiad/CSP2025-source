#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,ans,vis[20],c[20],b[20];
char s[20];
void dfs(int t,int pas){
	if(t>n){
		if(pas>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		b[t]=i;
		dfs(t+1,pas+((s[t]-'0')&&((t-1-pas)<c[i])));
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>s+1;
	for(i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
