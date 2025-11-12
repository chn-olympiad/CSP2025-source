#include <cstdio>
const int N=505,mod=998244353;
int n,m,a2[N],b1[N],b2[N],f1[N][N],f2[N][N],fact[N],finv[N]; char a1[N];
int pow(int a,int b){
	int ans=1;
	while(b>0){
		if(b&1) ans=1ll*ans*a%mod;
		a=1ll*a*a%mod; b>>=1;
	}
	return ans;
}
void init_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=1ll*fact[i-1]*i%mod;
	finv[n]=pow(fact[n],mod-2);
	for(int i=n;i> 0;i--) finv[i-1]=1ll*finv[i]*i%mod;
}
inline int C(int a,int b){
	if(a<0||b<0||b>a) return 0;
	return 1ll*fact[a]*finv[b]%mod*finv[a-b]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,k,l,x,ans=0;
	scanf("%d%d%s",&n,&m,&a1[1]),f1[0][0]=1,init_fact(n);
	for(i=1;i<=n;i++) scanf("%d",&x),b1[x]++;
	for(i=1;i<=n;i++) a2[i]=a2[i-1]+(a1[i]=='0');
	for(i=0;i<=n;i++) b2[i]=(!i?0:b2[i-1])+b1[i];
	for(i=1;i<=n;i++){
		for(j=a2[i-1];j<=i-1;j++)
			for(k=j;k<=i-1;k++)
				f2[j][k]=f1[j][k],f1[j][k]=0;
		if(a1[i]=='0'){
			for(j=a2[i-1];j<=i-1;j++)
				for(k=j;k<=i-1;k++)
					for(l=0;l<=b1[j+1]&&l<=i-1-k;l++)
						f1[j+1][k+l+1]=(f1[j+1][k+l+1]+1ll*f2[j][k]*C(b1[j+1],l)%mod*
						C(i-1-k,l)%mod*fact[l])%mod;
		}else{
			for(j=a2[i-1];j<=i-1;j++)
				for(k=j;k<=i-1;k++)
					for(l=0;l<=b1[j+1]&&l<=i-1-k;l++)
						if(k-a2[i-1]<=b2[j])
							f1[j+1][k+l+1]=(f1[j+1][k+l+1]+1ll*f2[j][k]*(b2[j]-k+a2[i-1])%mod*
							C(b1[j+1],l)%mod*C(i-1-k,l)%mod*fact[l])%mod;
			for(j=a2[i-1];j<=i-1;j++)
				for(k=j;k<=i-1;k++)
					f1[j][k]=(f1[j][k]+f2[j][k])%mod;
		}
	}
	for(i=a2[n];i<=n-m;i++)
		for(j=i;j<=n&&j<=b2[i];j++)
			ans=(ans+1ll*f1[i][j]*C(b2[n]-b2[i],n-j)%mod*fact[n-j])%mod;
	printf("%lld\n",1ll*ans*fact[a2[n]]%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}