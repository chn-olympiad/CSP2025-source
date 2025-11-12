#include <bits/stdc++.h>
#define N 100005
#define num first
#define id second
using namespace std;
int T,n,a[N][3],dp[205][205][205],p[N];
pair<int,int> pp[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		int fa=1,fb=1,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][1]||a[i][2]) fa=0;
			if(a[i][2]) fb=0;
		}
		if(n<=200){
			for(int x=1;x<=n;x++){
				for(int i=0;i<=x;i++){
					for(int j=0;j<=x;j++){
						int k=x-i-j;
						if(k>x||k<0) continue;
						if(i) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i-1][j]+a[x][0]);
						if(j) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j-1]+a[x][1]);
						if(k) dp[x][i][j]=max(dp[x][i][j],dp[x-1][i][j]+a[x][2]);
					}
				}
			}
			for(int i=0;i*2<=n;i++){
				for(int j=0;j*2<=n;j++){
					if(n-i-j>n/2) continue;
					ans=max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(fa){
			for(int i=1;i<=n;i++)p[i]=a[i][0];
			sort(p+1,p+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=p[i];
			cout<<ans<<"\n";
			continue;
		}
		if(fb){
			for(int i=1;i<=n;i++) pp[i]=make_pair(a[i][0]-a[i][1],i);
			sort(pp+1,pp+n+1);
			int i;
			for(i=1;i<=n/2;i++) ans+=a[pp[i].id][1];
			for(;i<=n;i++) ans+=a[pp[i].id][0];
			cout<<ans<<"\n";
		}
	}
	return 0;
}//70
