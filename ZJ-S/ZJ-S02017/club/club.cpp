#include<bits/stdc++.h>
using namespace std;
const int N=210,M=1e5+10;
int t,n,a[M],b[M],c[M],dp[N][N][N];
struct dif{
	int val,idx;
}x[M];
bool cmp(dif o,dif p){
	return o.val>p.val;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(n<=200){
			memset(dp,0,sizeof(dp));
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=min(i,n/2);j++)
					for(int k=0;k<=min(i,n/2);k++){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
						if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
					}
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++){
					if(i+j<n/2)continue;
					ans=max(ans,dp[n][i][j]);
				}
			printf("%d\n",ans);
			continue;
		}if(b[1]==c[1]&&b[1]==0){
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=n/2+1;i<=n;i++)ans+=a[i];
			printf("%d\n",ans);
			continue;
		}for(int i=1;i<=n;i++)x[i].val=a[i]-b[i],x[i].idx=i;
		sort(x+1,x+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[x[i].idx];
		for(int i=n/2+1;i<=n;i++)ans+=b[x[i].idx];
		printf("%d\n",ans);
	}return 0;
}
