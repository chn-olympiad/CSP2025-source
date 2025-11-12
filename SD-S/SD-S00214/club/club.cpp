#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int f[1011][1011],a[100011][3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		int m=n>>1;
		for(int i=1; i<=n; i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int x=1; x<=n; x++) {
			for(int i=min(x,m); i>=0; i--) {
				for(int j=min(x,m); j>=0; j--) {
					if(i+j<x-m||i+j>x)continue;
					int tmp=f[i][j];
					if(i>0)f[i][j]=max(f[i][j],f[i-1][j]+a[x][0]);
					if(j>0)f[i][j]=max(f[i][j],f[i][j-1]+a[x][1]);
					if(x>i+j)f[i][j]=max(f[i][j],tmp+a[x][2]);
				}
			}
//			for(int i=0; i<=n; i++) {
//				for(int j=0; j<=n; j++) {
//					printf("%d,",f[i][j]);
//				}
//				puts("");
//			}
//			puts("\n\n\n");
		}
		int ans=0;
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				ans=max(ans,f[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
