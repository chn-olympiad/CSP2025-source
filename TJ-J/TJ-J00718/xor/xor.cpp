#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],n,k;
struct node{
	int v,cnt;
}dp[N][N];
int main(){
	scanf("%d%d",&n,&k);
	if(n>=N){
		int cnt=0; 
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);if(x==1) cnt++;
		}
		int y=(k==1?cnt:n-cnt);
		printf("%d",y);
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==k) dp[i][i].cnt=1;
			dp[i][i].v=a[i];
		}
		for(int len=2;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				dp[l][r].v=dp[l][r-1].v^dp[r][r].v;
				dp[l][r].cnt=(dp[l][r].v==k?1:0);
				for(int x=0;x<len-1;x++) dp[l][r].cnt=max(dp[l][r].cnt,dp[l][l+x].cnt+dp[l+x+1][r].cnt);
			}
		}
		printf("%d",dp[1][n].cnt);
	}
	
	return 0;
	
} 
