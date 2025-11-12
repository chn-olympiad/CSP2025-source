#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rg register int
int t;
const int maxn=100050;
int n,a[maxn][10];
ll dp[500][500][500],ans;
int d[10];
void dfs(int i,ll tmp){
	if(i==n+1){
		ans=max(ans,tmp);
		return ;
	}
	if(dp[i][d[1]][d[2]]>tmp)	return ;
	for(int j=1;j<=3;j++){
		if(d[j]<n/2){
			d[j]++;
			dfs(i+1,tmp+a[i][j]);
			d[j]--;
		}
	}
	dp[i][d[1]][d[2]]=tmp;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d ",&t);
	while(t--){
		ans=0;
		memset(d,0,sizeof(d));
		memset(dp,0,sizeof(dp));
		scanf("%d ",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		dfs(1,0);
//		dp[0][0][0]=0;
//		for(int i=1;i<=n;i++){
//			for(int w1=0;w1<=min(n/2,i);w1++){
//				for(int w2=0;w2<=min(n/2,i-w1);w2++){
//					if(!w1)	dp[i-1][w1-1][w2]=0;
//					if(!w2)	dp[i-1][w1][w2-1]=0;
//					dp[i][w1][w2]=max(dp[i-1][w1][w2]+a[i][3],max(dp[i-1][w1-1][w2]+a[i][1],dp[i-1][w1][w2-1]+a[i][2]));
//				}
//			}
//		}
//		for(int w1=0;w1<=n/2;w1++){
//			for(int w2=0;w2=n/2;w2++){
//				ans=max(dp[n][w1][w1],ans);
//			}
//		}
		printf("%lld\n",ans);
	}
	return 0;
}