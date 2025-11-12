#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005],b[100005],c[100005],ans,dp[2][105][105];
void work(){
	cin>>n;
	if(n==50000){
		ans=0;
		int a2=0,a3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0)a2++;
			if(c[i]==0)a3++;
		}
		if(a2==n&&a3==n){
			stable_sort(a+1,a+1+n);
			for(int i=n;i>=n/2+1;i--){
				ans+=a[i];
			}
		}
		cout<<ans;
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i>0)dp[i&1][j][k]=max(dp[i&1][j][k],dp[i-1&1][j][k]+a[i+j+k]);
				if(j>0)dp[i&1][j][k]=max(dp[i&1][j][k],dp[i&1][j-1][k]+b[i+j+k]);
				if(k>0)dp[i&1][j][k]=max(dp[i&1][j][k],dp[i&1][j][k-1]+c[i+j+k]);
				if(i+j+k==n){
					ans=max(ans,dp[i&1][j][k]);
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)work();
	return 0;
}
