#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int fa[100005];
struct node{
	int u,v,w,id;
}e[N*2],ee[N*2];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int vis[11],vv[11];
int wz[N*2];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		vv[i]=c;
		for(int j=1;j<=n;j++){
			int s;
			scanf("%d",&s);
			e[m+(i-1)*n+j].u=0;
			e[m+(i-1)*n+j].v=j;
			e[m+(i-1)*n+j].w=c+s;
			e[m+(i-1)*n+j].id=i;
		} 
	}
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
	m+=k*n;
	int ycx=0;
	ll ans=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(u==0||v==0){
			if(!vis[e[i].id]){
				vis[e[i].id]=1;
				wz[e[i].id]=i;
			}
			else{
				e[i].w-=vv[e[i].id];
			}
		}
	}
	sort(wz+1,wz+1+k);
	for(int i=1;i<=k;i++){
		sort(e+wz[i-1],e+wz[i-1]+m,cmp);
	}
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		if(ycx==n-1) break;
		if(u==0||v==0){
			n++;
		}
		merge(u,v);
		ycx++;
		ans+=w;
	}
	printf("%lld",ans);
	return 0;
}

