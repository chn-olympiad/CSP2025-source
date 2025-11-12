#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=1e6+5;
struct Node{
	int u,v,w;
	bool operator<(Node h)const{
		return w<h.w;
	}
}node[M];
int n,m,k,c[N],a[15][N],vnt,fa[N<<1],nodew[N<<1],flag,id[N<<1],out[N<<1];
long long ans,cnt;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		node[i]={u,v,w};
	}
	sort(node+1,node+m+1);
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}vnt=n;
	for(int i=1;i<=m;i++){
		int u=node[i].u,v=node[i].v,w=node[i].w;
		int su=find(u),sv=find(v);
		if(su==sv)continue ;
		fa[su]=fa[sv]=++vnt;
		nodew[vnt]=w;
		ans+=w;
		if(vnt==2*n-1)break;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)flag=1;
		}
	}
	if(!flag){
		printf("0");
		return 0;
	}
	for(int t=1;t<(1<<k);t++){
		vnt=n;int now=m,mnt=n;
		for(int j=1;j<=k;j++){
			if(!(t&(1<<(j-1))))continue ;
			vnt++;cnt+=c[j];id[vnt]=c[j];out[vnt]=0;
			for(int i=1;i<=n;i++){
				node[++now]={vnt,i,a[j][i]};
			}
		}sort(node+1,node+now+1);
		for(int i=1;i<=vnt*2;i++)fa[i]=i;
		for(int i=1;i<=now;i++){
			int u=node[i].u,v=node[i].v,w=node[i].w;
			int su=find(u),sv=find(v);
			if(su==sv)continue ;
			cnt+=w;mnt++;
			if(u>n||v>n)out[max(u,v)]++,id[max(u,v)]+=w;
			if(mnt==vnt*2-1)break;
		}
		for(int j=n+1;j<=vnt;j++){
			if(out[j]==1)cnt-=id[j];
		}ans=min(ans,cnt);
	}printf("%lld",ans);
	return 0;
}
