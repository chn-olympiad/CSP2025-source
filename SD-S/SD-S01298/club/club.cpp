#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr signed N=1e5+10;
struct node{
	int x,y,z;
}a[N];
signed t,n,vis[N],ans,dp[205][105][105][105];
int dp2[205][105][105];
inline void dfs(signed x){
	if (x==n+1){
		signed one=0,two=0,thr=0;
		for (signed i=1; i<=n; i++){
			if (vis[i]==0) one++;
			else if (vis[i]==1) two++;
			else thr++;
		}
		if (one>n/2||two>n/2||thr>n/2){
			return;
		}
		signed sum=0;
		for (signed i=1; i<=n; i++){
			if (vis[i]==0) sum+=a[i].x;
			else if (vis[i]==1) sum+=a[i].y;
			else sum+=a[i].z;
		}
		ans=max(ans,sum);
		return;
	}
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	vis[x]=2;
	dfs(x+1);
	vis[x]=0;
}
signed v[N];
inline bool cmp(signed x,signed y){
	return x>y;
}
inline void solve(){
	cin>>n;
	memset(vis,0,sizeof(vis));
	signed flag=0,flag2=0;
	for (signed i=1; i<=n; i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if (a[i].y||a[i].z) flag=1;
		if (a[i].z) flag2=1;
	}
	ans=0;
	if (!flag){
		signed tot=0;
		for (signed i=1; i<=n; i++){
			v[++tot]=a[i].x;
		}
		sort(v+1,v+tot+1,cmp);
		for (signed i=1; i<=n/2; i++){
			ans+=v[i];
		}
		cout<<ans<<'\n';
		return;
	}
	if (!flag2&&n<=200){
		memset(dp2,0,sizeof(dp2));
		dp2[1][0][1]=a[1].y,dp2[1][1][0]=a[1].x;
		for (int i=2; i<=n; i++){
			for (int j=0; j<=i&&j<=n/2; j++){
				for (int k=0; k<=i&&k<=n/2; k++){
					if (j+1<=n/2){
						dp2[i][j+1][k]=max(dp2[i][j+1][k],dp2[i-1][j][k]+a[i].x);
					}
					if (k+1<=n/2){
						dp2[i][j][k+1]=max(dp2[i][j][k+1],dp2[i-1][j][k]+a[i].y);
					}
				}
			}
		}
		ans=0;
		for (int j=0; j<=n/2; j++){
			for (int k=0; k<=n/2; k++){
				ans=max(ans,dp2[n][j][k]);
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if (n<=16){
		dfs(1);
		cout<<ans<<'\n';
		return;
	}
	if (n<=100){
		memset(dp,0,sizeof(dp));
		dp[1][0][0][1]=a[1].z,dp[1][0][1][0]=a[1].y,dp[1][1][0][0]=a[1].x;
		for (signed i=2; i<=n; i++){
			for (signed j=0; j<=i&&j<=n/2; j++){
				for (signed k=0; k<=i&&k<=n/2&&j+k<=n; k++){
					for (signed l=0; l<=i&&l<=n/2; l++){
						if (j+k+l>n) continue;
						if (j+1<=n/2){
							dp[i][j+1][k][l]=max(dp[i][j+1][k][l],dp[i-1][j][k][l]+a[i].x); 
						}
						if (k+1<=n/2){
							dp[i][j][k+1][l]=max(dp[i][j][k+1][l],dp[i-1][j][k][l]+a[i].y);
						}
						if (l+1<=n/2){
							dp[i][j][k][l+1]=max(dp[i][j][k][l+1],dp[i-1][j][k][l]+a[i].z);
						}
					}
				}
			}
		}
		ans=0;
		for (signed j=0; j<=n/2; j++){
			for (signed k=0; k<=n/2; k++){
				for (signed l=0; l<=n/2; l++){
					ans=max(ans,dp[n][j][k][l]);
				//	cout<<dp[n][j][k][l]<<" "<<j<<" "<<k<<" "<<l<<"\n";
				}
			}
		}
		cout<<ans<<'\n';
		return;
	} 
	ll sum=0;
	for (int i=1; i<=n; i++){
		sum+=max({a[i].x,a[i].y,a[i].z});
	}
	cout<<sum<<'\n';
	return;
}
signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
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
6
1 9 0
8 10 0
7 8 0
9 11 0
3 4 0
5 7 0

*/

