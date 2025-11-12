#include<bits/stdc++.h>
using namespace std;
long long a[500005][5];
long long n;
long long dp[505][505][505];
//long long da[]={484387,443896,473417,417649,447450};
struct ss{
	int x,y,z;
}g[500005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
//		cout<<t<<"--------------------------------------------------------------------------------------------------\n";
		cin>>n;
		bool flag2=0,flag3=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0)flag2=1;
			if(a[i][3]!=0)flag3=1;
		}
		if(flag2==0&&flag3==0){
			priority_queue<int> q;
			for(int i=1;i<=n;i++){
				q.push(a[i][1]);
			}
			int i=1,ans=0;
			while(!q.empty()&&i<=n/2){
				ans+=q.top();
				q.pop();
				i++;
			}
			cout<<ans<<'\n';
			return 0;
		}
		if(n==2){
			long long mx=0;
			for(long long i=1;i<=3;i++){
				for(long long j=1;j<=3;j++){
					if(i!=j)mx=max(mx,a[1][i]+a[2][j]);
				}
			}
			cout<<mx<<'\n';
			return 0;
		}
		for(long long j=n;j>=0;j--){
			for(long long k=n;k>=0;k--){
				for(long long l=n;l>=0;l--){
					dp[j][k][l]=0;
				}
			}
		}
//		int xx=0,yy=0,zz=0;
		for(long long i=1;i<=n;i++){
			for(long long j=n;j>=1;j--){
				for(long long k=n;k>=1;k--){
					for(long long l=n;l>=1;l--){
//						int aa=dp[j-1][k][l]+a[i][1],bb=dp[j][k-1][l]+a[i][2],cc=dp[j][k][l-1]+a[i][3],dd=dp[j][k][l];
//						if(aa>bb&&aa>cc&&aa>dd)g[i].x=j,g[i].y=k,g[i].z=l,dp[j][k][l]=aa;
//						if(bb>aa&&bb>cc&&bb>dd)g[i].x=j,g[i].y=k,g[i].z=l,dp[j][k][l]=bb;
//						if(cc>aa&&cc>bb&&cc>dd)g[i].x=j,g[i].y=k,g[i].z=l,dp[j][k][l]=cc;
						
						dp[j][k][l]=max(dp[j][k][l],max(dp[j-1][k][l]+a[i][1],max(dp[j][k-1][l]+a[i][2],dp[j][k][l-1]+a[i][3])));
					}
				}
			}
		}
//		long long mx=0;
//		cout<<t<<"***********************\n";
//		for(int j=n;j>=1;j--){
//			for(int k=n;k>=1;k--){
//				for(int l=n;l>=1;l--){
//					mx=max(mx,dp[j][k][l]);
//					if(dp[j][k][l]==da[t])cout<<j<<' '<<k<<' '<<l<<'\n';
//				}
//				cout<<'\n';
//			}
//			cout<<'\n';
//		}
//		cout<<mx<<'\n';
//		cout<<g[n].x<<' '<<g[n].y<<' '<<g[n].z<<'\n';
		cout<<dp[n/2][n/2][n/2]<<'\n';
//		if(dp[n][n][n]==da[t])cout<<"YES";
//		else cout<<"NO";
//		cout<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

