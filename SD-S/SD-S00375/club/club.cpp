//Ren5Jie4Di4Ling5%
//次小值 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=210;
int a[N][4];
int dp[N][N][N];
//当前处理到第i个人 分配到三个部门的人数 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%lld",&T);
	while(T--){//多测记得清空 
		memset(dp,0,sizeof dp);
		scanf("%lld",&n);
		bool case1=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(j>1&&a[i][j]!=0) case1=0; 
			}
		}
		if(case1){
			priority_queue<int>q;
			for(int i=1;i<=n;i++) q.push(a[i][1]);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=q.top(); q.pop();
			}
			printf("%lld",ans);
		}
		else{
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
						if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
						if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(i+j+k!=n) continue;
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
