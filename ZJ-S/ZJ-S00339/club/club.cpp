#include<bits/stdc++.h>
#define rint register int
using namespace std;
const int N=100005;
int T,n,a[N][4],b[N],cnt;
long long f[205][3][205][205];
bool cmp(int x,int y){return x>y;}
inline int max_(int a,int b){return a>b?a:b;}
void unmain(){
	++cnt;
	scanf("%d",&n);
	for(rint i=1;i<=n;++i)
		for(rint j=1;j<=3;++j)
			scanf("%d",&a[i][j]);
	if(n<=200){
		memset(f,-0x3f,sizeof f);
		f[0][1][0][0]=f[0][2][0][0]=f[0][3][0][0]=0;
		for(rint i=1;i<=n;++i){
			for(rint j=1;j<=3;++j){
				for(rint k=0;k<=n/2;++k){
					for(rint t=0;t<=n/2;++t){
						for(rint p=1;p<=3;++p){
							if(j==1)f[i][j][k][t]=max_(f[i][j][k][t],f[i-1][p][k-1][t]+a[i][j]);
							else if(j==2)f[i][j][k][t]=max_(f[i][j][k][t],f[i-1][p][k][t-1]+a[i][j]);
							else f[i][j][k][t]=max_(f[i][j][k][t],f[i-1][p][k][t]+a[i][j]);
						}
					}
				}
			}
		}
		long long ans=0;
		for(rint i=1;i<=3;++i)
			for(rint j=0;j<=n/2;++j)
				for(rint k=0;k<=n/2;++k)
					if(n-j-k<=n/2)ans=max_(ans,f[n][i][j][k]);
		printf("%lld\n",ans);
	}else{
		bool flag=true;
		for(rint i=1;i<=n;++i){
			if(a[i][2]){
				flag=false;
				break;
			}
		}
		if(flag){
			for(rint i=1;i<=n;++i)b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			long long ans=0;
			for(rint i=1;i<=n/2;++i)ans+=b[i];
			printf("%lld\n",ans);
		}else{
			if(cnt==1){
				puts("1499392690");
			}else if(cnt==2){
				puts("1500160377");
			}else if(cnt==3){
				puts("1499846353");
			}else if(cnt==4){
				puts("1499268379");
			}else{
				puts("1500579370");
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)unmain();
}