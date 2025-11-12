#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=998244353;
int n,m,p=1,a[N],t;
long long ans;
long long dp[1<<N][N];
string sx;
long long dfs(int s,int t){
	if(t<0)return 0;
	if(!s){
		if(t)return 0;
		else return 1;
	}
	if(dp[s][t]!=-1)return dp[s][t];
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s&(1<<(i-1)))cnt++;
	if(t>cnt)return dp[s][t]=0;
	dp[s][t]=0;
	for(int i=1;i<=n;i++)
		if(s&(1<<(i-1))){
			//ta被录
			if(cnt-t<a[i]&&sx[cnt]=='1')
				dp[s][t]+=dfs((s^(1<<(i-1))),t-1);
			if(cnt-1-t>=a[i]||sx[cnt]=='0')
			dp[s][t]+=dfs((s^(1<<(i-1))),t);
			dp[s][t]%=mod;
		}
	return dp[s][t];
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>sx;
	sx=" "+sx;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=(1<<n);j++)
			dp[j][i]=-1;
	for(int i=m;i<=n;i++)
		ans+=dfs((1<<n)-1,i),ans%=mod;
	cout<<ans;
	return 0;
}
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
