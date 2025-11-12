#include<bits/stdc++.h>
using namespace std;
struct obj{
	int a,b,c;
} g[100009];
int dp[209][109][109];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int sum=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			g[i]={a,b,c};
		}
		int ans=0;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=min(n/2,i-j);k++){
					if(i-k-j>n/2)continue;
					if(j>0)dp[i][j][k]=dp[i-1][j-1][k]+g[i].a;
					if(k>0)dp[i][j][k]=max(dp[i-1][j][k-1]+g[i].b,dp[i][j][k]);
					if(i-k-j>0)dp[i][j][k]=max(dp[i-1][j][k]+g[i].c,dp[i][j][k]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
