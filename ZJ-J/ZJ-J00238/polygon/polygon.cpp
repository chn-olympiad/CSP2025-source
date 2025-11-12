#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=5005,mod=998244353;
int n,a[N],maxa,sum;
long long f[N][N<<1],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n<3){
		putchar('0');
		return 0;
	}
	for(ri i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	maxa=a[n];
	if(maxa*2>=sum){
		putchar('0');
		return 0;
	}
	f[0][0]=1;
	ci maxa2=maxa<<1|1;
	for(ri i=1;i<=n;++i){
		for(ri j=0;j<=maxa2;++j){
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
			f[i][min(maxa2,j+a[i])]=(f[i][min(maxa2,j+a[i])]+f[i-1][j])%mod;
		}
	}
	for(ri i=1;i<=n;++i){
		for(ri j=a[i]<<1|1;j<=maxa2;++j){
			ans=(ans+f[i][j])%mod;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}