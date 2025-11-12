#include<bits/stdc++.h>
using namespace std;
long long n,m,c[25],s[3000005],dp[3000005][19],vis[3000005][19],cnt,ans,Q=998244353;
string st;
void dfs(int x,int z){
	if(vis[x][z]) return ;
	vis[x][z]=1;
	if(n-z<m) return ;
	if(x==(1<<n)-1) {
		if(n-z>=m){
			dp[x][z]=1;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if((((1<<i)>>1)&x)==0){
			dfs((((1<<i)>>1)|x),z+(c[i]<=z||st[s[x]]=='0'));
			dp[x][z]+=dp[(((1<<i)>>1)|x)][z+(c[i]<=z||st[s[x]]=='0')];
			dp[x][z]%=Q;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	for(int i=1;i<(1<<n);i++) {
		s[i]=s[i& -i]+1;
	}
	dfs(0,0);
	cout<<dp[0][0];
	return 0;
}