#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x<=9){
		putchar('0'+x);
		return ;
	}
	write(x/10);
	putchar('0'+x%10);
	return ;
}
const int N=5e2+5;
const int M=1e3+5;
const int mod=998244353;
const int inf=1e18+7;
int a[N],c[N],sum[N],he[N];
int dp[N][N],g[N][N];
int jc[N];
void ycl(){
	jc[0]=jc[1]=1;
	for(int i=2;i<=N-5;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ycl();
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		he[i]=(!a[i]);
	}
	for(int i=1;i<=n;i++){
		he[i]+=he[i-1];
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		sum[c[i]]++;
	}
	for(int i=n;~i;i--){
		sum[i]+=sum[i+1];
	}
	int zong1=n-he[n]-m;
	for(int i=0;i<=zong1;i++){
		dp[i][0]=1;
	}
//	for(int i=0;i<=n;i++){
//		cout<<"i "<<i<<" "<<sum[i]<<" "<<he[i]<<endl;
//	}
	for(int i=n;i;i--){
		if(!a[i])continue;
//		cout<<"i "<<i<<" "<<a[i]<<endl;
		memcpy(g,dp,sizeof(dp));
		memset(dp,0,sizeof(dp));
		for(int j=0;j<=zong1;j++){
			for(int k=0;k<=n-he[n];k++){
				dp[j][k+1]=(dp[j][k+1]+g[j][k]*max(0ll,sum[he[i]+j+1]-k))%mod;
				if(j!=0)dp[j-1][k]=(dp[j-1][k]+g[j][k])%mod;
				if(j!=0)dp[j-1][k+1]=(dp[j-1][k+1]+g[j][k]*max(0ll,sum[he[i]+j]-k)%mod*(mod-1))%mod;
			}
		}
	}
	int ans=0;
	for(int k=0;k<=n-he[n];k++){
		ans=(ans+dp[0][k]*jc[n-k])%mod;
	}
	write(ans);
	puts("");
	return 0;
} 