#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=222,INF=-2.1e9;
int t,n,a[3][N],f[M][M][M],ans;
bool t_A;
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),ans=INF,t_A=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]),t_A|=(a[1][i]|a[2][i]);
		if(!t_A){
			sort(a[0]+1,a[0]+1+n),ans=0;
			for(int i=n;i>(n>>1);i--)ans+=a[0][i];
			printf("%d\n",ans);
			continue;
		}
		for(int i=0;i<=(n>>1);i++){
			for(int j=0;j<=(n>>1);j++)f[0][i][j]=INF;
		}
		f[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(n>>1);j++){
				for(int k=0;k<=(n>>1);k++){
					if(i-j-k>(n>>1))continue;
					f[i][j][k]=INF;
					if(j&&f[i-1][j-1][k]>INF)f[i][j][k]=f[i-1][j-1][k]+a[0][i];
					if(k&&f[i-1][j][k-1]>INF)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[1][i]);
					if(j+k<i&&f[i-1][j][k]>INF)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[2][i]);
				}
			}
		}
		for(int j=0;j<=(n>>1);j++){
			for(int k=0;k<=(n>>1);k++){
				if(j+k>=(n>>1))ans=max(ans,f[n][j][k]);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin),fclose(stdout);
	return 0;
}