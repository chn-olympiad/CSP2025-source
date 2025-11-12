#include<bits/stdc++.h>
const int N=210;
using namespace std;
int n,a[N][4];
long long ans,f[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=min(n-i,n/2);j++){
				for(int k=0;k<=min(n-i-j,n/2);k++){
					int l=i+j+k;
					if(i)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[l][1]);
					if(j)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[l][2]);
					if(k)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[l][3]);
					if(l==n)ans=max(ans,f[i][j][k]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

