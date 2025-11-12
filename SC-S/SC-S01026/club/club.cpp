#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100050];
int ans=0,n;
void dfs(int d,int s1,int s2,int s3,int sum){
	if(s1>n/2||s2>n/2||s3>n/2) return;
	if(d==n+1){
		ans=max(ans,sum);
		return;
	}
	dfs(d+1,s1+1,s2,s3,sum+a[d].x);
	dfs(d+1,s1,s2+1,s3,sum+a[d].y);
	dfs(d+1,s1,s2,s3+1,sum+a[d].z);
}
int dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		int f1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y||a[i].z) f1=0;
		}
		if(f1){
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i].x;
			}
			cout<<ans<<'\n';
		}
		else if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		else{
			memset(dp,-0x3f,sizeof dp);
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){//总人数
				for(int j=0;j<=min(i,n/2);j++){//选1的
					for(int k=0;k<=min(i,n/2);k++){//选2的
						if(k+j>i) break;
						if(j>=1)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i].x);
						if(k>=1)dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+a[i].y);
						if(i-j-k<=n/2&&i-j-k>=1) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+a[i].z);
					}
				}
			}
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(n-j-k>n/2) continue;
					ans=max(ans,dp[j][k][n-j-k]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}//25