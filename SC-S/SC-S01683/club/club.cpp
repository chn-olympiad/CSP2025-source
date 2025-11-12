#include<bits/stdc++.h>
const int N=1e5+5;
int T;
int n;
int a[N][4];
int ans;
int ct[4];
int dp[N][4],cnt[N][4][4];
int max(int x,int y){
	return x>y?x:y;
}
void clear(){
	ans=0;
	memset(dp,0,sizeof dp);
	memset(cnt,0,sizeof cnt);
	return;
}
void dfs(int p,int sum){
	if(p==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(ct[i]<n/2){
			ct[i]++;
			dfs(p+1,sum+a[p][i]);
			ct[i]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		clear();
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(n<=30){
			dfs(1,0);
			printf("%d\n",ans);
			continue;
		}
		int l=n/2;
		for(int i=1;i<=n;++i){
			for(int k=1;k<=3;++k){
				for(int j=1;j<=3;++j){
					if(cnt[i-1][k][j]+1<=l){
						if(dp[i][j]<dp[i-1][k]+a[i][j]){
							dp[i][j]=dp[i-1][k]+a[i][j];
							cnt[i][j][j]=cnt[i-1][k][j]+1;
						}
					}else cnt[i][j][j]=cnt[i-1][k][j];
				}
			}
		}
		printf("%d\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
}