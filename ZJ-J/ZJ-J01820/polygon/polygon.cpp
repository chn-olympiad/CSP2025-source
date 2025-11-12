#include<stdio.h>
#include<algorithm>
const int N=5e3+5,mod=998244353;
//O(2^n)+special 60 pts
namespace{
	int n,a[N],s[N],f[N][N],ans,flag=1;
}
int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),s[i]=s[i-1]+a[i];
		if(a[i]!=1) flag=0;
	}
	std::sort(a+1,a+1+n);
	if(n<=20){
		for(int i=7;i<(1<<n);i++){
			if(__builtin_popcount(i)<3) continue;
			int j,x=i,sum=0;
			for(j=0;x;j++,x>>=1) if(x&1) sum+=a[j+1];
			if(a[j]*2<sum) ans++;
		}
	}
	else if(flag) ans=(qpow(2,n)-1-n-n*(n-1)/2+mod)%mod;
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}