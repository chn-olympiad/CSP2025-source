#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;int n,m,k;
int c[N],a[20][10010],cnt,vis[N];
struct node{
	int u,v,w;
}r[N*2],bian[N*2],tb[2*N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N],siz[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}return fa[x]=find(fa[x]);
}void merge(int x,int y){
	if(siz[y]>siz[x]){
		swap(x,y);
	}fa[y]=x;
}
void fun(){
	sort(r+1,r+cnt+1,cmp);
	for(int i=1;i<=n+11;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=cnt;i++){
		int x=r[i].u;
		int y=r[i].v;
		int w=r[i].w;
		x=find(x);
		y=find(y);
		if(x==y){
			continue;
		}merge(x,y);
		vis[i]=1;
	}
}int fun2(int tmp){
	sort(tb+1,tb+tmp+1,cmp);
	for(int i=1;i<=n+11;i++){
		fa[i]=i;
		siz[i]=1;
	}long long sum=0;
	for(int i=1;i<=tmp;i++){
		int x=tb[i].u;
		int y=tb[i].v;
		int w=tb[i].w;
		x=find(x);
		y=find(y);
		if(x==y){
			continue;
		}merge(x,y);
		sum+=w;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		r[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	fun();
	int tmp=0;
	for(int i=1;i<=cnt;i++){
		if(vis[i]){
			bian[++tmp]={r[i].u,r[i].v,r[i].w};
		}
	}cnt=tmp;
	long long aans=100000000000000000ll;
	for(int i=0;i<(1<<k);i++){
		long long ans=0;
		int tmp=cnt;
		for(int i=1;i<=cnt;i++){
			tb[i]={bian[i].u,bian[i].v,bian[i].w};
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ans+=c[j+1];
				for(int k=1;k<=n;k++){
					tb[++tmp]={n+j+1,k,a[j+1][k]};
				}
			}
		}
		aans=min(ans+fun2(tmp),aans);
	}cout<<aans;
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