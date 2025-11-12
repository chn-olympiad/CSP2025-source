#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
int c[N];
int dp[N][N];
int n,m;
int ans=0;
string nd;
bool mark[N];
int	jiecheng[N];
void dfs(int dep,int cnt){
	if(cnt>=m){
		ans=1LL*ans+jiecheng[n-dep];
		return;
	}
	for(int i=1;i<=n;i++)if(!mark[i]){
		mark[i]=true;
		dfs(dep+1,cnt+(c[i]>dep-cnt&&nd[dep+1]=='1'));
		mark[i]=false;
	}
	return;
}
void solve(){
	cin>>n>>m>>nd;
	nd=" "+nd;
	jiecheng[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		jiecheng[i]=1LL*jiecheng[i-1]*i%MOD;
	}
	dfs(0,0);
	cout<<ans;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
