#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int Mod=998244353;
int n,m;
char s[N];
int c[N];
int ans;
bool vis[N];
void dfs(int t,int lu,int l){
	if(t==n+1){
		if(lu>=m){
			ans++;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(l>=c[i]){vis[i]=1;dfs(t+1,lu,l+1);vis[i]=0;}
		else if(s[t]=='1'){vis[i]=1;dfs(t+1,lu+1,l);vis[i]=0;}
		else{vis[i]=1;dfs(t+1,lu,l+1);vis[i]=0;}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	/*bool one=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1') one=0;
	}*/
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(m==1){
		cout<<n;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
18 18
111111111111111111
2 3 4 1 2 3 4 1 2 3 4 1 2 3 4 1 2 3
*/
