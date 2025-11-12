#include<bits/stdc++.h>
using namespace std;
int n,t,ans,a[100005][4],b[100005];
int dp[2][202][202][202];
void work(){
	memset(dp,0,sizeof(dp));
	int mx=0;
	bool f=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]!=0||a[i][3]!=0)
		  f=1;else
		  b[i]=a[i][1];
	}
	if(f==1){
		sort(b+1,b+1+n);
		for(int i=n;i>=n/2+1;i--){
			ans+=b[i];
		}
		cout<<ans;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			for(int k=0;k<=min(i-j,n/2);k++){
				for(int l=0;l<=min(i-j-k,n/2);l++){
					if(j>0) 
				  	  dp[i%2][j][k][l]=max(dp[(i-1)%2][j-1][k][l]+a[i][1],dp[i%2][j][k][l]);
					if(k>0)
				  	  dp[i%2][j][k][l]=max(dp[(i-1)%2][j][k-1][l]+a[i][2],dp[i%2][j][k][l]);
					if(l>0)
				  	  dp[i%2][j][k][l]=max(dp[(i-1)%2][j][k][l-1]+a[i][3],dp[i%2][j][k][l]);
					mx=max(mx,dp[i%2][j][k][l]);
				}
				
			}
		}
	}
	cout<<mx<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		work();
	}
}
