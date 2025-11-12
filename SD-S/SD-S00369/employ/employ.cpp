#include<iostream>
#include<cstdio>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		x*=10;
		x+=(c-'0'); 
		c=getchar();
	}
	return x;
}
const int N=505;
const int M=505;
const long long MOD=998244353;
long long s[N],c[N],a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	int f1=0,f2=0;
	for (int i=1;i<=n;i++){
		s[i]=read();
		if (!s[i]) f1=1;
	}
	for (int i=1;i<=n;i++){
		c[i]=read(); 
		if (!c[i]) f2=1;
	}
	if (m==n){
		if (f1 || f2) printf("0");
		else{
			long long ans=1;
			for (int i=1;i<=n;i++){
				ans=(ans*i)%MOD;
			}
			printf("%lld",ans);
		}
	}
    return 0;
}

