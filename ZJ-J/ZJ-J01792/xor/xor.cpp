#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,j,dp[2][(1<<20)][2],ma,a[500010],ans;
void calc0(){cout<<n/2;}
void calc1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)ans++;
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	if(k==0){calc0();return 0;}
	if(k==1){calc1();return 0;}
	ma=k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for(int j=0;j<=ma*2;j++)dp[1][j][0]=dp[1][j][1]=-2e9;
	dp[1][a[1]][0]=0;
	dp[1][0][0]=0;
	if(a[1]==k)dp[1][k][1]=1;
	for(int i=2;i<=n;i++){
		int now=i&1;
		for(int j=0;j<=max(k*2,ma);j++)
			dp[now][j][0]=dp[now][j][1]=-2e9;
		for(int j=0;j<=max(k*2,ma);j++)dp[now][0][0]=max(dp[now][0][0],max(dp[now^1][k][1],dp[now^1][j][0]));
		dp[now][a[i]][0]=max(dp[now][a[i]][0],dp[now^1][k][1]);
		if(a[i]==k)dp[now][k][1]=max(dp[now][k][1],dp[now^1][k][1]+1);
		for(int j=0;j<=max(k*2,ma);j++){
			dp[now][j^a[i]][0]=max(dp[now][j^a[i]][0],dp[now^1][j][0]);
			if((j^a[i])==k){
				dp[now][k][1]=max(dp[now][k][1],dp[now^1][j][0]+1);
			}
		}
	}
	for(int i=0;i<=max(k*2,ma)*2;i++)ans=max(ans,dp[n%2][i][0]),ans=max(ans,dp[n%2][i][1]*(i==k));
	cout<<ans;
}