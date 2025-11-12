#include<cstdio>
namespace force{
	int n,m,k;
	const int MAXN=1e4+5;
	const int MAXM=1e6+5;
	const int MAXK=18;
	const int INF=0x3f3f3f3f;
	int u[MAXN],v[MAXN],w[MAXN];
	int c[MAXM][MAXK];
	int ans=INF;
	void solve(){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
		}
		for(int i=0;i<=m;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&c[i][j]);
			}
		}
		for(int l=1;l<=k;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					int temp=w[i];
					for(int o=1;o<=m;o++){
						if(o!=j)temp+=c[l][k];
					}
					if(temp<ans) ans=temp;
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	force::solve();
	return 0;
}
