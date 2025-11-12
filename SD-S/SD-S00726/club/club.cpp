#include<bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10,P=998244353,Mod=1e9+7,M=2e2+10;
int n,a[5][N],ans,dp[M][M][M];
bool flag1,flag2,flag3;
void solve() {
	ans=0;
	flag1=0,flag2=0,flag3=0;
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[1][i]>>a[2][i]>>a[3][i],flag1=(flag1||a[1][i]),flag2=(flag2||a[2][i]),flag3=(flag3||a[3][i]);
	if(n<=200) {
		memset(dp,0,sizeof(dp));
		for(int i=2; i<=n; i+=2) {
			for(int j=0; j<=i; j++) {
				for(int k=0; k<=i-j; k++) {
					int l=i-j-k;
					if(j>1)dp[i][j][k]=max(dp[i][j][k],dp[i-2][j-2][k]+a[1][i-1]+a[1][i]);
					if(k>1)dp[i][j][k]=max(dp[i][j][k],dp[i-2][j][k-2]+a[2][i-1]+a[2][i]);
					if(l>1)dp[i][j][k]=max(dp[i][j][k],dp[i-2][j][k]+a[3][i-1]+a[3][i]);
					if(j>0&&k>0)dp[i][j][k]=max({dp[i][j][k],dp[i-2][j-1][k-1]+a[1][i-1]+a[2][i],dp[i-2][j-1][k-1]+a[2][i-1]+a[1][i]});
					if(j>0&&l>0)dp[i][j][k]=max({dp[i][j][k],dp[i-2][j-1][k]+a[1][i-1]+a[3][i],dp[i-2][j-1][k]+a[3][i-1]+a[1][i]});
					if(l>0&&k>0)dp[i][j][k]=max({dp[i][j][k],dp[i-2][j][k-1]+a[3][i-1]+a[2][i],dp[i-2][j][k-1]+a[2][i-1]+a[3][i]});
					if(i==n&&j<=i/2&&k<=i/2&&l<=i/2)ans=max(ans,dp[i][j][k]);
				}
			}
		}
	} else if(!flag2&&!flag3) {
		sort(a[1]+1,a[1]+n+1);
		for(int i=n; i>n/2; i--)ans+=a[1][i];
	}
	else
	{
		for(int i=1;i<=n;i++)ans+=max({a[1][i],a[2][i],a[3][i]});
	}
	cout<<ans<<'\n';
}
signed main() {
	FAST
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _T_;
	cin>>_T_;
	while(_T_--)solve();
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

*/
