#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cassert>
int n,m,k;
const int maxn=1e3+5,maxm=4e6+5,maxk=20;
struct edge{
	int x,y;
	long long z;
	edge(){}
	edge(int x,int y,int z):x(x),y(y),z(z){}
	friend bool operator <(edge x,edge y){
		return x.z<y.z;
	}
}a[maxm];int len=0;
int c[maxk];
long long f[maxn][maxn];
namespace Force{//k=0
	struct UFS{
		int fa[maxn];
		void init(){for(int i=1;i<=n;i++) fa[i]=i;}
		int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
		void merge(int x,int y){x=find(x),y=find(y),fa[y]=x;}
	}ufs;
	edge tmp[maxm];
	void solve(){
		for(int i=1;i<=len;i++) tmp[i]=a[i];
		std::sort(tmp+1,tmp+len+1);
		ufs.init();
		long long sum=0;
		for(int i=1;i<=len;i++){
			if(ufs.find(tmp[i].x)!=ufs.find(tmp[i].y)){
				ufs.merge(tmp[i].x,tmp[i].y);
				sum+=tmp[i].z;
			}
		}
		printf("%lld\n",sum);
	}
}
namespace Spe1{//ci=0
	const int smaxn=1e3+5;
	long long G[smaxn][smaxn];
	struct UFS{
		int fa[maxn];
		void init(){for(int i=1;i<=n;i++) fa[i]=i;}
		int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
		void merge(int x,int y){x=find(x),y=find(y),fa[y]=x;}
	}ufs;
	edge tmp[maxm];
	void solve(){
		for(int p=1;p<=n;p++)
			for(int q=1;q<=n;q++) if(p!=q)
				G[p][q]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=k;i++)
			for(int p=1;p<=n;p++)
				for(int q=1;q<=n;q++)
					G[p][q]=std::min(G[p][q],f[i][p]+f[i][q]);
		for(int t=1;t<=n;t++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) 
					G[i][j]=std::min(G[i][j],G[i][t]+G[t][j]);
		for(int i=1;i<=len;i++) tmp[i]=a[i];
		std::sort(tmp+1,tmp+len+1);
		ufs.init();
		long long sum=0;
		for(int i=1;i<=len;i++){
			if(ufs.find(tmp[i].x)!=ufs.find(tmp[i].y)){
				ufs.merge(tmp[i].x,tmp[i].y);
				sum+=std::min(tmp[i].z,G[tmp[i].x][tmp[i].y]);
			}
		}
		printf("%lld\n",sum);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[++len]=edge(x,y,z);
		a[++len]=edge(y,x,z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&f[i][j]);
	}
	bool flag=true;
	for(int i=1;i<=k;i++) if(c[i]!=0) flag=false;
	if(flag) Spe1::solve(); 
	else Force::solve();
	return 0;
}
