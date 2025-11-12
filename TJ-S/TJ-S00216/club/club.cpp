#include <bits/stdc++.h> 
using namespace std;

int const N=510;
int t,n,res;
int f[N][N][N],a[100010][4],b[100010];
bool spa=1;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for (int x=1;x<=t;x++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			b[i]=a[i][1];
			if (spa && a[i][2] || a[i][3]) spa=0;
		}
		memset(f,0,sizeof(f));res=0;
		if (spa){
			sort(b+1,b+n+1);reverse(b+1,b+n+1);
			for (int i=1;i*2<=n;i++) res+=b[i];
			printf("%d\n",res);
			continue;
		}
		for (int k=1;k<=n;k++){
			for (int i=0;i<=k;i++){
				if (i>n/2) continue;
				for (int j=0;i+j<=k;j++){
					if (j>n/2 || (k-i-j)>n/2) continue;
					if (i) f[k][i][j]=max(f[k][i][j],f[k-1][i-1][j]+a[k][1]);
					if (j) f[k][i][j]=max(f[k][i][j],f[k-1][i][j-1]+a[k][2]);
					if (k-i-j) f[k][i][j]=max(f[k][i][j],f[k-1][i][j]+a[k][3]);
					res=max(res,f[k][i][j]);
				}
			}
		}
		printf("%d\n",res);
	}
	
	return 0;
}
