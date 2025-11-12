#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int M=2e2+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int t;
int n;
int a[5][N];
ll dp[M][M][M];
int b[N];
ll ans;
void solve(){
	ans=-INF;
	bool flag=false;
	scanf("%d",&n);
	for(int x=0;x<=n/2;x++){
		for(int y=0;y<=n/2;y++){
			for(int z=0;z<=n/2;z++){
				dp[x][y][z]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
		if(a[2][i]!=0||a[3][i]!=0) flag=true;
	}
	if(!flag){
		sort(a[1]+1,a[1]+n+1);
		ans=0;
		for(int i=n;i>n/2;i--) ans+=a[1][i];
		printf("%lld\n",ans);
		return; 
	}
	for(int i=1;i<=n;i++){
		for(int x=0;x<=n/2;x++){
			for(int y=0;y<=n/2;y++){
				int z=i-x-y;
				if(z<0||z>n/2) continue;
				if(x>0) dp[x][y][z]=max(dp[x][y][z],dp[x-1][y][z]+a[1][i]);
				if(y>0) dp[x][y][z]=max(dp[x][y][z],dp[x][y-1][z]+a[2][i]);
				if(z>0) dp[x][y][z]=max(dp[x][y][z],dp[x][y][z-1]+a[3][i]);
				if(i==n) ans=max(ans,dp[x][y][z]);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
