#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long N=1018;
const long long mod=998244353;
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long c[N],s[N];
char ch[N];
inline long long ksm(long long a,long long b,long long mod){
	long long res=1;
	while(b){
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n=read(),m=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)
		c[i]=read();
	bool ok=true;
	for(int i=1;i<=n;i++)
		if(ch[i]!='1')
			ok=false;
	if(ok){
		long long sum=0;
		for(int i=1;i<=n;i++)
			if(!c[i])
				sum++;
		s[0]=1;
		for(int i=1;i<=n;i++)	
			s[i]=s[i-1]*i%mod;
		long long k=n-sum;
		for(int i=1,j=1;i<m;i++,j++)
			k=(k+(n-j))%mod;
		printf("%lld",k);
	}
	return 0;
}

