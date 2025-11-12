#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],f[N][N],ans,p[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	p[0]=1;
	for(int i=1;i<=n;++i){
		p[i]=(p[i-1]<<1)%mod;
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	f[1][0]=f[1][a[1]]=1;
	for(int i=2;i<=n;++i){
		int res=p[i-1];
		for(int j=0;j<=a[i];++j){
			res=(res-f[i-1][j]+mod)%mod;
		}
		ans=(ans+res)%mod;
		for(int j=0;j<=5e3;++j){
			f[i][j]=f[i-1][j];
			if(j>=a[i]){
				f[i][j]=(f[i][j]+f[i-1][j-a[i]])%mod;
			}
		}
	}
	printf("%d\n",ans);
}