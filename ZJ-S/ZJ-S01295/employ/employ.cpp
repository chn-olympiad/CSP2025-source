#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N = 500+10;
int n,m,ans,c[N];
string s;
int vis[N];
void dfs(int x,int pass,int cnt){
	if(pass>=m){
		ans++;
		ans%=mod;
	}
	if(pass+cnt==n)	return ;
	for(int i = 1;i <= n;i ++){
		if(vis[i])	continue;
		vis[i]=1;
		if(c[i]<=cnt || s[cnt+pass]=='0'){
			dfs(i,pass,cnt+1);
		}else{
			dfs(i,pass+1,cnt);
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i ++)	cin >> c[i];
	s=" "+s;
	vis[1]=1;
	if(c[1]==0 || s[1]=='0'){
		dfs(1,0,1);
	}else{
		dfs(1,1,0);
	}
//	for(int i = 1;i <= n;i ++){
//		vis[i]=1;
//		if(c[i]==0 || s[1]=='0'){
//			dfs(i,0,1);
//		}else{
//			dfs(i,1,0);
//		}
//		vis[i]=0;
//	}
	cout << ans;
	return 0;
}