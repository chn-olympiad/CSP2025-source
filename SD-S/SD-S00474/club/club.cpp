#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
int dp[205][105][105][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		priority_queue<int> q;
		bool f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				q.push(a[i][j]);
				if(a[i][1]!=0){
					f=0;
				}
			}
		}
		if(f){
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<"\n";
		}
		else if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2&&j<i;j++){
					for(int k=0;k+j<i&&k<=n/2&&i-j-k<=n/2;k++){
						int l=i-j-k;
						int o=max(dp[i-1][j][k][2],dp[i-1][j][k][1]);
						o=max(o,dp[i-1][j][k][3]);
						if(l<n/2){
							dp[i][j][k][3]=o+a[i][3];
						}
						if(k<n/2){
							dp[i][j][k+1][2]=o+a[i][2];							
						}
						if(j<n/2){
							dp[i][j+1][k][1]=o+a[i][1];		
						}
						
					}
				}
			}
			int ans=-1;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2&&n-j-k<=n/2;k++){
					ans=max(dp[n][j][k][1],ans);
					ans=max(dp[n][j][k][2],ans);
					ans=max(dp[n][j][k][3],ans);
				}
			}
			cout<<ans<<"\n";
		}
	}
} 

