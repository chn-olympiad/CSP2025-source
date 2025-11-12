#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
int n,m,k,c[20],a[20][N],fa[N],num,siz[N],gx[20];
long long ans;
struct edge{
	int u,v,w;
};
vector<edge> e;
map<int,map<int,int> > edg;
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(siz[x]<siz[y]) swap(x,y);
	fa[y]=x;siz[x]+=siz[y];
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		for(int i=1,u,v,w;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			e.push_back({u,v,w});
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;siz[i]=1;
		}
		sort(e.begin(),e.end(),cmp);
		int len=e.size();
		for(int i=0;i<len;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv){
				merge(fu,fv);ans+=e[i].w;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) edg[i][j]=-1;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edg[u][v]=w;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;siz[i]=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int ii=j+1;ii<=n;ii++){
				if(edg[ii][j]==-1) edg[ii][j]=edg[j][ii]=a[i][j]+a[i][ii];
				else edg[ii][j]=edg[j][ii]=min(edg[ii][j],a[i][j]+a[i][ii]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e.push_back({i,j,edg[i][j]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	int len=e.size();
	for(int i=0;i<len;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			merge(fu,fv);ans+=e[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
