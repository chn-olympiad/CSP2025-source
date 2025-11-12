#include<bits/stdc++.h>
using namespace std;
const int N=31,M=1e5+5;
int t;
int n;
int a[N][3];
int dp[N][N][N][N];
int f[M];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		if(n<=30){
			int tol=n/2;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i][0]>>a[i][1]>>a[i][2];	
			}
			for(int i=1;i<=n;i++){
				for(int w1=0;w1<=tol&&w1<=n;w1++){
					for(int w2=0;w2<=tol&&w1+w2<=n;w2++){
						for(int w3=0;w3<=tol&&w1+w2+w3<=n;w3++){
							if(w1){
								dp[i][w1][w2][w3]=max({dp[i-1][w1-1][w2][w3]+a[i][0],dp[i][w1][w2][w3]});
							}
							if(w2){
								dp[i][w1][w2][w3]=max({dp[i-1][w1][w2-1][w3]+a[i][1],dp[i][w1][w2][w3]});
							}
							if(w3){
								dp[i][w1][w2][w3]=max({dp[i][w1][w2][w3],dp[i-1][w1][w2][w3-1]+a[i][2]});
							}
							ans=max(ans,dp[i][w1][w2][w3]);
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			int tol=n/2;
			long long ans=0;
			for(int i=1;i<=n;i++){
				int x,y;
				cin>>f[i]>>x>>y;
			}
			sort(f+1,f+1+n);
			for(int i=n;i>=n-tol+1;i--){
				ans+=f[i];
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
 } 

