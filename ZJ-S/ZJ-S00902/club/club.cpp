#include <bits/stdc++.h>
using namespace std;
int T,n,ma,i,fA,fB,dp[300][300],j;
struct no{
	int x,y,z;
}a[100010];
bool cmp(no q,no h){return q.x>h.x;}
void dfs(int t,int x,int y,int z,int s){
	if(t>n){
		ma=max(ma,s);
		return ;
	}
	if(x+1<=n/2) dfs(t+1,x+1,y,z,s+a[t].x);
	if(y+1<=n/2) dfs(t+1,x,y+1,z,s+a[t].y);
	if(z+1<=n/2) dfs(t+1,x,y,z+1,s+a[t].z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ma=0;fA=fB=1;
		for(i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y>0) fA=0;
			if(a[i].z>0) fA=fB=0;
		}
		if(fA){
			sort(a+1,a+n+1,cmp);
			for(i=1;i<=n/2;i++) ma+=a[i].x;
			cout<<ma<<"\n";
			continue;
		}
		if(fB){
			memset(dp,0,sizeof(dp));
			for(i=1;i<=n;i++){
				dp[i][0]=dp[i-1][0];
				for(j=1;j<=min(n/2,i);j++)
					dp[i][j]=max(dp[i-1][j]+a[i].y,dp[i-1][j-1]+a[i].x);
			}
			cout<<dp[n][n/2]<<"\n";
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<ma<<"\n";
	}
	return 0;
}

//50 TLE
