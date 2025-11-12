#include<bits/stdc++.h>
using namespace std;
int n;
int g = -1;
long long s = 0;
int dp[5005];
int vis[5005];
void dfs(int x,int y,int z,int g,int t){
	if(x == z){
		s++;
		return ;
	}
	for(int i=t+1;i<=n;i++){
		if(n-i < z-x-1) return ;
		g = max(dp[i],g);
		if(z == x+1 && y+dp[i] <= g*2){
			return ;
		}
		dfs(x+1,y+dp[i],z,g,i);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i];
	}
	sort(dp+1,dp+1+n);
	for(int i=3;i<=n;i++){
		dfs(0,0,i,0,0);
	}
	cout<<s % 998244353;
	return 0;
}

