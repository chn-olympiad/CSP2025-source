#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int _,n;
ll dp[222][111][111],a[N][3],b[N];
bool xingzhi(){
	for(int i=1;i<=n;i++){
		if(a[i][1]||a[i][2]) return 0;
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	if(n<=200){
		memset(dp,-0x3f,sizeof dp);
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int x=0;x<=i&&x<=n/2;x++){
				for(int y=0;y<=i&&y<=n/2;y++){
					int z=i-x-y;
					if(z<0) break;
					if(z>n/2) continue;
					if(x){
						dp[i][x][y]=max(dp[i][x][y],dp[i-1][x-1][y]+a[i][0]);
					}if(y){
						dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+a[i][1]);
					}if(z){
						dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y]+a[i][2]);
					}
					//printf("!%d %d %d %d\n",i,x,y,dp[i][x][y]);
				}
			}
		}
		ll ans=0;
		for(int x=0;x<=n/2;x++){
			for(int y=0;y<=n/2;y++){
				if(n-x-y>n/2) continue;
				ans=max(ans,dp[n][x][y]);
			}
		}
		printf("%lld\n",ans);
	}else{
		if(xingzhi()){
			//printf("!\n");
			for(int i=1;i<=n;i++){
				b[i]=a[i][0];
			}
			sort(b+1,b+n+1);
			ll ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			printf("%lld\n",ans);
		}else printf("0\n");
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&_);
	while(_--){
		solve();
	}
	return 0;
}
