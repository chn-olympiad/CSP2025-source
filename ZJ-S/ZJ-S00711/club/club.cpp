#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,a[N],b[N],c[N],dp[N][4],k[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(k,0,sizeof k);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		int c1=0,c2=0,c3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				c1++,dp[i][1]=a[i]-max(b[i],c[i]);
				dp[i][2]=dp[i][3]=0x3f3f3f3f;
			}
			else if(b[i]>=c[i]){
				ans+=b[i];
				c2++,dp[i][2]=b[i]-max(a[i],c[i]);
				dp[i][1]=dp[i][3]=0x3f3f3f3f;
			}
			else{
				ans+=c[i];
				c3++,dp[i][3]=c[i]-max(a[i],b[i]);
				dp[i][1]=dp[i][2]=0x3f3f3f3f;
			}
		}
		if(c1>n/2){
			for(int i=1;i<=n;i++)
				k[i]=dp[i][1];
			sort(k+1,k+1+n);
			for(int i=1;i<=c1-n/2;i++)
				ans-=k[i];
		}
		if(c2>n/2){
			for(int i=1;i<=n;i++)
				k[i]=dp[i][2];
			sort(k+1,k+1+n);
			for(int i=1;i<=c2-n/2;i++)
				ans-=k[i];
		}
		if(c3>n/2){
			for(int i=1;i<=n;i++)
				k[i]=dp[i][3];
			sort(k+1,k+1+n);
			for(int i=1;i<=c3-n/2;i++)
				ans-=k[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
