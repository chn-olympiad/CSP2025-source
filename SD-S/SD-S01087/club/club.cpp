#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=1e5+5;
const int inf=-1e8;
int a[N][4];
ll dp[101][101][101];
int s[N][4];
ll ans;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dp[0][1][0]=a[1][2];
		dp[0][0][1]=a[1][3];
		dp[1][0][0]=a[1][1];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int x=0;x<=n/2&&x+j<=i;x++){
//					for(int y=0;y<=n/2&&x+j+y<=i;y++){
						int y=i-j-x;
						dp[j][x][y]=max({(j!=0?dp[j-1][x][y]+a[i][1]:-1),(x!=0?dp[j][x-1][y]+a[i][2]:-1),(y!=0?dp[j][x][y-1]+a[i][3]:-1)});
						ans=max(ans,dp[j][x][y]);
//						cout<<dp[j][x][y]<<' ';
//					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
























