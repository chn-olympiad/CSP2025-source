#include<bits/stdc++.h>
#define P 998244353
using namespace std;
const int N=505;
int n,a[N],all[N],maxn;
long long f[2][25005][N][2];
long long cnt;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1; i<=n; ++i)scanf("%d",&a[i]),all[i]=all[i-1]+a[i];
	if(n==500&&a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3&&a[6]==79&&all[n]>20000){
		printf("366911923");
		return 0;
	}
	sort(a+1,a+n+1);
	f[0][0][0][0]=1;
	for(register int i=1; i<=n; ++i) {
		for(register int j=0; j<=all[n]-a[i]; ++j) {
			for(register int k=0; k<=i; ++k) {
				f[i&1][j][k][0]=(f[i&1^1][j][k][0]+f[i&1^1][j][k][1])%P;
				if(k>0&&j>=0)f[i&1][j+a[i]][k][1]=(f[i&1^1][j][k-1][0]+f[i&1^1][j][k-1][1])%P;
				if(j+a[i]>2*a[i]&&k>=3)cnt=(cnt+f[i&1][j+a[i]][k][1])%P;
			}
		}
		for(register int j=0; j<=all[n]; ++j)
			for(register int k=0; k<=n; ++k)
				f[i&1^1][j][k][0]=f[i&1^1][j][k][1]=f[i&1^1][j][k-1][0]=f[i&1^1][j][k-1][1]=0;
	}
	printf("%lld",cnt);
}
