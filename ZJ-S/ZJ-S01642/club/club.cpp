#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e5;
int n;
int a[N+5][4],b[N+5];
ll dp[2][1000][1000],ans;
void solve(){
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			dp[0][i][j]=dp[1][i][j]=0;
	for(int i=1;i<=n;i++){
		for(int x=0;x<=n/2;x++)
			for(int y=0;y<=n/2;y++)
				dp[i&1][x][y]=0;
		for(int x=0;x<=n/2&&x<i;x++)
			for(int y=min(n/2,i-1-x);y>=0;y--){
				int z=i-1-x-y;
				if(z>n/2) break;
				if(x<n/2){
					dp[i&1][x+1][y]=max(dp[i&1][x+1][y],
						dp[(i-1)&1][x][y]+a[i][1]);
					ans=max(ans,dp[i&1][x+1][y]);
				}
				if(y<n/2){
					dp[i&1][x][y+1]=max(dp[i&1][x][y+1],
						dp[(i-1)&1][x][y]+a[i][2]);
					ans=max(ans,dp[i&1][x][y+1]);
				}
				if(z<n/2){
					dp[i&1][x][y]=max(dp[(i-1)&1][x][y]+a[i][3],
						dp[i&1][x][y]);
					ans=max(ans,dp[i&1][x][y]);
				}
			}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,flag=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) flag=0;
		}
		ans=0;
		if(flag){
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2;i--)
				ans+=b[i];
		}
		else solve();
		printf("%lld\n",ans);
	}
	
	return 0;
}
