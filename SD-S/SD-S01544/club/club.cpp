#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010],b[100010],c[100010],cha[100010];
long long dp[410][410][410];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	srand(time(0));
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		int fl2=0,fl3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			fl2=max(fl2,b[i]),fl3=max(fl3,c[i]);
		}
		if(n>200&&fl2==0&&fl3==0){
			sort(a+1,a+n+1);
			long long ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n>200&&fl3==0){
			long long ans=0;
			for(int i=1;i<=n;i++){
				int k=min(a[i],b[i]);
				cha[i]=a[i]-b[i];
				ans+=k;
			}
			sort(cha+1,cha+n+1);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=-cha[i];
				}
				else{
					ans+=cha[i];
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=0;i<=n/2;i++){//a
			for(int j=0;j<=n/2;j++){//b
				for(int k=0;k<=n/2;k++){//c
					if(i+j+k>n) break;
					if(i!=0) dp[i][j][k]=dp[i-1][j][k]+a[i+j+k];
					if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[i+j+k]);
					if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+c[i+j+k]);
				}
			}
		}
		long long ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(i+j<n/2) continue;
				ans=max(ans,dp[i][j][n-i-j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//70pts
