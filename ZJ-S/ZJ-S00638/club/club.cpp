#include<bits/stdc++.h>
using namespace std;
#define int long long
#define k (x-i-j)
int T,n,a[4][100005],f[205][205][205],ans,A=1;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		memset(f,0,sizeof f),ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			if(a[3][i]||a[2][i]) A=0;
		}
		if(A){
			sort(a[1]+1,a[1]+1+n);
			for(int i=n,j=1;i>=1&&j<=n/2;i--,j++) ans+=a[1][i];
			printf("%lld\n",ans);
			continue;
		}
		for(int x=1;x<=n;x++){
			for(int i=0;i<=n/2;i++){
				for(int j=x-i-n/2;j<=n/2&&k>=0;j++){
					if(k>n/2) continue;
					if(i>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[1][x]);
					if(j>0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[2][x]);
					if(k>0) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[3][x]);
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
rp++, please! I love you, CCF!
*/
