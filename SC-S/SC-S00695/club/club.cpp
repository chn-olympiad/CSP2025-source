#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=1e5+11;
int t;
int n;
int a[MAXN][4],dp[MAXN];
int ans=0,links=0,mit=0,rechts=0;

bool cmp(int ni,int ko){
	return ni>ko;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) dp[i]=0;
		ans=links=mit=rechts=0;
		for(int i=1;i<=n;i++){ 
			for(int j=1;j<=3;j++) scanf("%lld",&a[i][j]);
			mit+=a[i][2];
			links+=a[i][1];
			rechts+=a[i][3];
		}
		if(!links && !rechts){
			for(int i=1;i<=n;i++) dp[i]=a[i][2];
			sort(dp+1,dp+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=dp[i];
		}
		else if(!mit && !rechts){
			for(int i=1;i<=n;i++) dp[i]=a[i][1];
			sort(dp+1,dp+1+n,cmp);
			for(int i=1;i<=n/2;i++)	ans+=dp[i];
		}
		else{
			for(int i=1;i<n;i+=2){
				dp[i]=max(max(max(a[i][1]+a[i+1][2],a[i][1]+a[i+1][3]),max(a[i][2]+a[i+1][1],a[i][2]+a[i+1][3])),max(a[i][3]+a[i+1][1],a[i+1][3]+a[i+1][2]));
				dp[i+1]=dp[i];
				ans+=dp[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}