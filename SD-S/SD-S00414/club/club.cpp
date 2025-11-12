#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int t,n,ans;
int a[5][100100];
int find(int i,int num1,int num2,int num3){
	if(num1>n/2||num2>n/2||num3>n/2){
		return -1e16;
	}
	if(i==n+1){
		return 0;
	}
	return max(find(i+1,num1+1,num2,num3)+a[1][i],max(find(i+1,num1,num2+1,num3)+a[2][i],find(i+1,num1,num2,num3+1)+a[3][i]));
}
int dp[150][150][150];
int fl1;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			if(a[2][i]!=0||a[3][i]!=0){
				fl1=1;
			}
		}
		if(n<=15){
			printf("%lld\n",find(1,0,0,0));
			continue;
		}
		if(fl1==0){
			ans=0;
			sort(a[1]+1,a[1]+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[1][i];
			}
			printf("%lld\n",ans);
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int x=min(n/2,i);x>=0;x--){
				for(int y=min(n/2,max(0ll,i-x));y>=0;y--){
					for(int z=min(n/2,max(0ll,i-x-y));z>=0;z--){
						if(x+y+z>n){
							break;
						}
						if(x!=0){
							dp[x][y][z]=max(dp[x][y][z],dp[x-1][y][z]+a[1][i]);
						}if(y!=0){
							dp[x][y][z]=max(dp[x][y][z],dp[x][y-1][z]+a[2][i]);
						}if(z!=0){
							dp[x][y][z]=max(dp[x][y][z],dp[x][y][z-1]+a[3][i]);
						}
					}
				}
			}
		}
		ans=0;
		for(int x=1;x<=n/2;x++){
			for(int y=1;y<=n/2;y++){
				int z=n-x-y;
				if(z>n/2)continue;
				ans=max(ans,dp[x][y][z]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
