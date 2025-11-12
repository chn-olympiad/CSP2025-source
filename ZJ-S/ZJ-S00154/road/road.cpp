#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e6+5,M=1e4+5;
int n,m,k,z,cnt[1200],zt[1200],don,fa[M][1200];
bool d[1200];
ll c[15],ans[1200],fi=-1;
struct node{
	int u,v;
	ll w;
}E[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=0;i<=z;++i)
		zt[i]=n-1;
	for(int i=0;i<=z;++i)
		for(int j=1;j<=k;++j)
			if(i&(1<<(j-1))){
				++zt[i];
				ans[i]+=c[j];
			}
	for(int i=1;i<=n+k;++i)
		for(int j=0;j<=z;++j)
		 	fa[i][j]=i;
}
int find(int x,int y){
	if(fa[x][y]==x) return x;
	fa[x][y]=find(fa[x][y],y);
	return fa[x][y];
}
ll Min(ll x,ll y){
	return x==-1?y:(x<y?x:y);
}
bool A;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	z=(1<<k)-1;
	for(int i=1;i<=m;++i)
		scanf("%d%d%lld",&E[i].u,&E[i].v,&E[i].w);
	ll x;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		if(c[i]) A=true;
		for(int j=1;j<=n;++j){
			scanf("%lld",&x);
			E[++m]=(node){n+i,j,x};
		}
	}
	sort(E+1,E+m+1,cmp);
	init();
	int fx,fy;
	if(!A){
		for(int i=1;i<=m;++i){
			if(cnt[z]==zt[z]){
				fi=ans[z];
				break;
			}
			fx=find(E[i].u,z);fy=find(E[i].v,z);
			if(fx==fy) continue;
			fa[fx][z]=fy;
			++cnt[z];
			ans[z]+=E[i].w;
		}
		printf("%lld",fi);
		return 0;
	}
	for(int i=1;i<=m;++i){
		if(don==z+1) break;
		for(int j=0;j<=z;++j){
			if(d[j]) continue;
			if(cnt[j]==zt[j]){
				fi=Min(fi,ans[j]);
				d[j]=true;
				++don;
			}
			else if(ans[j]>=fi&&fi!=-1){
				d[j]=true;
				++don;
			}
			if(don==z+1) break;
			if(E[i].u>n&&(!(j&(1<<(E[i].u-n-1))))) continue;
			fx=find(E[i].u,j);fy=find(E[i].v,j);
			if(fx==fy) continue;
			fa[fx][j]=fy;
			++cnt[j];
			ans[j]+=E[i].w;
		}
	}
	printf("%lld",fi);
	return 0;
}
