#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		for(int k=1;k<=n;k++){
			for(int j=k;j>=1;j--){
				dp[k][j]=max(dp[k][j],dp[k][j-1]+a[j]);
			}
		}
		for(int i=3;i<n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]*2<dp[j][i])ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
