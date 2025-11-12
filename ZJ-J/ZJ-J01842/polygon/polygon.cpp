#include<bits/stdc++.h>
#define int long long
//#define il inline
#define put putchar
#define pii pair<int,int>
#define mk make_pair
using namespace std;
 int rd(){
	int sum=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
 void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=5e3+10,V=5e3,mod=998244353;
int n,a[N],ans,f[V+10],g[V+10],sum[V+10],res,inv[N],fac[N];
 int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
 int C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	//system("fc polygon.out polygon4.ans");
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	/*n=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=V;++j)g[j]=f[j];
		for(int j=0;j+a[i]<=V;++j)g[j+a[i]]=(g[j+a[i]]+f[j])%mod;
		for(int j=0;j<=V;++j)f[j]=g[j];
		int sum=0;
		if(i>=2&&i<n)for(int j=V;j>=a[i+1]+1;--j)sum=(sum+f[j])%mod;
		ans=(ans+sum)%mod;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=15;++j){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=n;++i){
		sum[i][V]=f[i][V];
		for(int j=V-1;j>=0;--j){
			sum[i][j]=(f[i][j]+sum[i][j+1])%mod;
		}
	}
	for(int i=3;i<=n;++i)ans=(ans+sum[i-1][a[i]+1])%mod;
	wr(ans);*/
	n=rd();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=inv[i+1]*(i+1)%mod;
	//cout<<C(2,1)<<' '<<C(2,2);
	for(int i=1;i<=n;++i)a[i]=rd();
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=V;++j)g[j]=f[j];
		for(int j=0;j+a[i]<=V;++j)g[j+a[i]]=(g[j+a[i]]+f[j])%mod;
		for(int j=0;j<=V;++j)f[j]=g[j];
		if(i>=2&&i<n){
			int sum=0;
			for(int j=0;j<=a[i+1];++j)sum=(sum+f[j])%mod;
			int ss=1;
			for(int j=1;j<=i;++j)ss=(ss+C(i,j))%mod;
		//	cout<<ss<<' '<<sum<<endl;
			ans=(ans+ss-sum+mod)%mod;
		}
	}
	wr(ans);
	return 0;
}
