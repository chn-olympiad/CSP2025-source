#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],b,c,d,dp[100005][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;w++){
		cin>>n;
		int x=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=3;j++){
				if(a[i][j]>0)dp[i][j]=max(dp[i-1][j-1],dp[i-1][j+3]+a[i][j]);
				else dp[i][j]=a[i][j];
			}
		}
		cout<<dp[n][3];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
