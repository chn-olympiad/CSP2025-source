#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e4+5,M=2e6+5,inf=1e18;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
struct edge{
	int x,y,z;
	bool operator<(edge xx)const{
		return z<xx.z;
	}
}e[M],ee[M];
int n,m,k,ans=inf,c[15],a[15][N];
int fa[N],siz[N];
int find(int u){
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}
inline void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return;
	if(siz[x]>siz[y]){
		fa[y]=x;
		siz[x]+=siz[y];
	}
	else{
		fa[x]=y;
		siz[y]+=siz[x];
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].z=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int s=0;s<(1<<k);s++){
//		puts("#########");
		int nn=n,tot=m,res=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				res+=c[i];
			}
		}
		if(res>ans)continue;
		for(int i=1;i<=m;i++)ee[i]=e[i];
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				nn++;
				for(int j=1;j<=n;j++)ee[++tot]={nn,j,a[i][j]};
			}
		}
//		printf("N%lld\n",nn);
		sort(ee+1,ee+tot+1);
		for(int i=1;i<=nn;i++)fa[i]=i,siz[i]=1;
		int num=0;
		for(int i=1;i<=tot;i++){
			if(find(ee[i].x)==find(ee[i].y))continue;
			merge(ee[i].x,ee[i].y);
//			printf("%lld %lld %lld\n",ee[i].x,ee[i].y,ee[i].z);
			num++;
			res+=ee[i].z;
			if(num==nn-1)break;
			if(res>ans)break;
		}
		if(res>ans)continue;
		if(num!=nn-1)continue;
		ans=min(ans,res);
//		printf("%lld %lld\n",ans,res);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
