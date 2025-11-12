#include <bits/stdc++.h>
using namespace std;
long long g[1005][1005],dp[1005][1005];
bool f[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long x,y,z;
	cin >> n >> m >>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=0x3f3f3f3f;
			dp[i][j]=0x3f3f3f3f;
		}
		g[i][i]=0;
		dp[i][i]=0;
	}
	while(m--){
		cin >>x >> y >> z;
		g[x][y]=min(g[x][y],z);
		g[y][x]=min(g[y][x],z);
		dp[x][y]=g[x][y];
		dp[y][x]=g[x][y];
	}
	long long mini=1,minx,ans=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		minx=-1;
		for(int j=1;j<=n;j++){
			if(f[j]==0&&(minx==-1||dp[j][mini]<dp[minx][mini])) minx=j;
		}
		//cout << mini << " " << minx << " " << dp[mini][minx] << " " << ans << '\n';
		f[minx]=1;
		ans+=dp[mini][minx];
		for(int j=1;j<=n;j++) dp[j][minx]=dp[minx][j]=min(dp[j][minx],dp[j][mini]+dp[mini][minx]);
		mini=minx;
	}
	cout << ans;
	return 0;
}
