#include<bits/stdc++.h>
using namespace std;
const int N=210;
int t,n,ans,f[N][N][N],a[N][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					f[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					int x=i-j-k;
					if(x&&x<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
					if(j)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
					if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				}
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				ans=max(ans,f[n][i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}