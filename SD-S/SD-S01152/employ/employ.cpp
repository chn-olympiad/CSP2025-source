#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
char s[505];
int a[505],c[505],di[505];
int f[502][502][502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++c[a[i]];
	for(int i=1;i<=n;++i)c[i]+=c[i-1];
	di[0]=1;
	for(int i=1;i<=n;++i)di[i]=1ll*i*di[i-1]%mod;
	f[0][0][0]=1;
	for(int i=1;i<=n;++i)for(int j=0;j<i;++j)for(int k=0;k<i;++k){
		int z=f[i-1][j][k];
		if(!z)continue;
		if(s[i]=='0'){
			f[i][j+1][k]=(f[i][j+1][k]+z)%mod;
		}else{
			f[i][j+1][k+1]=(f[i][j+1][k+1]+1ll*z*(c[j]-k))%mod;//2
			f[i][j][k]=(f[i][j][k]+z)%mod;//1 no 32
			f[i][j][k+1]=(f[i][j][k+1]-1ll*z*(c[j]-k))%mod;//1 with 32
		}
	}
	int ans=0;
	for(int k=0;k<=n;++k)for(int j=0;j<=n;++j){
		if(n-j<m)continue;
		ans=(ans+1ll*f[n][j][k]*di[n-k])%mod;
	}
	ans=(ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
