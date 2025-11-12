#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define N 5100
#define int long long
//pre[i]:groups(members>1)<=i num
//pcnt[i]:numbers<=i
//dp[i]:groups' sum == i
int fastpow(int a,int p){
	if(p<=0) return 1;
	int ans=1;
	while(p){
		if(p&1) ans=ans*a%p;
		a=a*a%p;
		p>>=1;
	}
	return ans;
}

int dp[N],c[N],a[N],mxv=0,n,pre[N],ans=0,pcnt[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mxv=max(mxv,a[i]);
		c[a[i]]++;
	}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=mxv;j>=a[i];--j){
			dp[j]+=dp[j-a[i]];
		}
	}
	for(int i=1;i<=mxv;++i){
		pcnt[i]=pcnt[i-1]+c[i];
		dp[i]-=c[i];
	}
	for(int i=1;i<=mxv;++i){
		pre[i]=(pre[i-1]+dp[i])%mod;
	}
//	printf("dp:");
//	for(int i=1;i<=mxv;++i){
//		printf("%d ",dp[i]);
//	}
//	
//	printf("\npre:");
//	for(int i=1;i<=mxv;++i){
//		printf("%d ",pre[i]);
//	}
//	printf("\npcnt:");
//	for(int i=1;i<=mxv;++i){
//		printf("%d ",pcnt[i]);
//	}
//	
//	cout<<'\n';
	for(int i=1;i<=mxv;++i){
		int ad=(int)pow(2,pcnt[i]-1)-pcnt[i]-pre[i];
		if(ad<0ll) ad=0ll;
//		printf("%d:canmakepolygon %d\n",i,(int)pow(2,pcnt[i]-1)-pcnt[i]-pre[i]);
		ans=((long long)ans+(long long)ad)%mod;
	}
	cout<<ans;
	return 0;
}
