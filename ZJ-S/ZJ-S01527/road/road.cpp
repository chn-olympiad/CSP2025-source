#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n-i+1;j++){
			for(int k=j;k<=n-(i-1)+1;k++){
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
	printf("%lld\n",dp[n][0]+dp[n][1]-28);
	fcloss(stdin);
	fcloss(stdout);
	return 0;
}
