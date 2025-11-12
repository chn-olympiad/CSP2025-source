#include<bits/stdc++.h>
#define N 10005
#define M 1100005
#define K 15
using namespace std;

int n,m,k,c[K],a[K][N],fa[N],ans=2e9;
struct edge{
	int u,v,w;
}e[M],e2[M];

bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int kruskal(int u){
//	cout<<3;
	memcpy(e2,e,sizeof(e2));
	int res=0,cnt=0,m2=m,n2=n;
	for(int i=1;i<=k;i++){
		if(u&(1<<(i-1))){
			n2++;
			res+=c[i];
			for(int j=1;j<=n;j++){
				e2[++m2]=edge{n+i,j,a[i][j]};
			}
		}
	}
	for(int i=1;i<=n2;i++){
//		cout<<2;
		fa[i]=i;
	}
	sort(e2+1,e2+m2+1,cmp);
	for(int i=1;i<=m2;i++){
		int u=e2[i].u,v=e2[i].v,w=e2[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			cnt++;
			fa[fu]=fv;
			res+=w;
		}
		if(cnt==n2-1) return res;
	}
	return res;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	int mx=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		mx=max(mx,c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			mx=max(mx,a[i][j]);
		}
	}
	if(mx==0){
		cout<<0;
		return 0;
	}
	for(int u=0;u<(1<<k);u++){
//		cout<<1;
		ans=min(ans,kruskal(u));
	}
	printf("%d",ans);
//	printf("\n%.0lf",(double)clock());
	return 0;
}//知颖你太美