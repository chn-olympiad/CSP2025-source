#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=205;
int t,n,m,a[maxn][5],ans;
bool ta=true,tb=true;
int dp[202][102][102][102];
int dp2[202][202][202];
priority_queue<int> q;
int dfs(int i,int j,int cnt,int x,int y,int z){
//	cout<<i<<" "<<j<<" "<<cnt<<endl;
	if(j==1) x++;
	else if(j==2) y++;
	else z++;
	if(x>m||y>m||z>m) return -1;
	if(i==n) return cnt+a[i][j];
	return max(dfs(i+1,1,cnt+a[i][j],x,y,z),max(dfs(i+1,2,cnt+a[i][j],x,y,z),dfs(i+1,3,cnt+a[i][j],x,y,z)));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ta=tb=true;
		memset(dp,0,sizeof(dp));
		ans=INT_MIN;
		cin>>n;m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) ta=false;
			if(a[i][3]!=0) tb=false;
		}
		if(n<=10){
			cout<<max(dfs(1,1,0,0,0,0),max(dfs(1,2,0,0,0,0),dfs(1,3,0,0,0,0)))<<endl;
			continue;
		}
		if(ta){
			ans=0;
			for(int i=1;i<=n;i++) q.push(a[i][1]);
			for(int i=1;i<=m;i++){
				ans+=q.top();q.pop();
			}
			cout<<ans<<endl;
			continue;
		}
		if(tb){
			for(int i=1;i<=n;i++){
				for(int j=m;j>=1;j--){
					dp2[i][j][i-j]=max(dp2[i-1][j-1][i-j]+dp2[i][j-1][i-j]+a[i][1],dp2[i-1][j][i-j-1]+dp2[i][j][i-j-1]+a[i][2]);
				}
			}
			for(int j=m;j>=1;j--) ans=max(ans,dp2[n][j][n-j]);
			cout<<ans<<endl;
			memset(dp2,0,sizeof(dp2));
			continue;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j) ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				for(int k=m;k>=1;k--){
					for(int l=m;l>=1;l--){
						dp[i][j][k][l]=max(dp[i-1][j-1][k][l]+a[i][1],max(dp[i-1][j][k-1][l]+a[i][2],dp[i-1][j][k][l-1]+a[i][3]));
						//dp[i][j][k][l]=max(dp[i][j][k][l],min(dp[i-1][j-1][k][l]+dp[i][j-1][k][l]+a[i][1],max(dp[i-1][j][k-1][l]+dp[i][j][k-1][l]+a[i][2],dp[i-1][j][k][l-1]+dp[i][j][k][l-1]+a[i][3])));
					}
				}
			}
		}
		for(int j=m;j>=1;j--)
			for(int k=m;k>=1;k--)
				for(int l=m;l>=1;l--)
					ans=max(ans,dp[n][j][k][l]);
//		for(int i=1;i<=n;i++){
//			for(int j=m;j>=1;j--){
//				for(int k=m;k>=1;k--){
//					for(int l=m;l>=1;l--){
//						cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
//					}
//				}
//			}
//		}
		cout<<ans<<endl;
	}
	return 0;
}/*
1 6
1 0 0
2 0 0
3 0 0
4 0 0
5 0 0
6 0 0
*/