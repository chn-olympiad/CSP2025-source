#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005,mod=998244353;
int n,up,l[maxn],f[maxn],s[maxn],ans;
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
inline int qpow(int a,int b,int p){
	int ret=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)ret=ret*a%p;
	return ret;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)up=max(up,l[i]=read());
	sort(l+1,l+n+1),f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=up;j>=l[i];j--)f[j]=(f[j]+f[j-l[i]])%mod;
		s[0]=0;for(int j=1;j<=up;j++)s[j]=s[j-1]+f[j];
		ans=((ans+qpow(2,i-1,mod)-s[l[i]])%mod+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
