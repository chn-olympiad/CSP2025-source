#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans;
const int mod=998244353;
int dp[21][21][348576];
string s;
int dfs(int day,int failed,int vis){
	if(day==n) return n-failed>=m;
	if(dp[day][failed][vis]!=-1) return dp[day][vis][failed];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis&(1<<(i-1))) continue;
		ans=(ans+dfs(day+1,failed+((c[i]<=failed)||(s[day]=='0')),vis|(1<<(i-1))))%mod;
	}
	return dp[day][vis][failed]=ans%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<dfs(0,0,0);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/