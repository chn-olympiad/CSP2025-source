#include<bits/stdc++.h>
#define P 998244353
#define int long long
using namespace std;
int n,ans,sum;
int a[502];
int f[502][50003];
int g[502];
int c[5002][5002];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	if(n>=500){
		c[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%P;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=2;j<i;j++){
			for(int k=a[i]+1;k<=sum+1;k++){
				g[i]=(g[i]+f[j][k])%P;
			}
		}
		for(int j=0;j<i;j++){
			for(int k=0;k+a[i]<=sum+1;k++){
				f[i][k+a[i]]=(f[i][k+a[i]]+f[j][k])%P;
			}
		}
//		printf("%d\n",g[i]);
	}
	for(int i=1;i<=n;i++){
		ans=(ans+g[i])%P;
	}
	printf("%lld",ans);
	return 0;
}
/*
TMD n<=5000,who won't know the answer is dp???
*/