#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m;
char s[N];
int c[N];
int vis[N];
int ans=0;
void dfs(int k){
	if(k==n+1){
		int cnt=0,e=0;
		for(int i=1;i<=n;i++){
			if(c[vis[i]]<=e)continue;
			if(s[i]=='0')e++;
			else cnt++;
		}
		if(cnt>=m){
			ans=(ans+1)%mod;
		}	
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=k;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}