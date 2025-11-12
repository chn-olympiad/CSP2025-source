#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10090],c[10090],id,vis[10090],num=0;
long long sum=0;
struct Node{
	int u;
	int v;
	int w;
}tree[1200010];
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
} 
void Union(int x,int y){
	fa[Find(x)]=Find(y);
}
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		tree[i].u=u;
		tree[i].v=v;
		tree[i].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i+n]);
		for(int j=1;j<=n;j++){
			int u,v,w;m++;
			scanf("%d",&w);
			tree[m].u=n+i;
			tree[m].v=j;
			tree[m].w=w+c[i+n];
			//attetion
		}
	}
	//cout<<c[5]<<' '<<c[6];
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(tree+1,tree+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=tree[i].u,y=tree[i].v;
		if(Find(x)==Find(y)){
			continue;
		}
		Union(x,y);
		sum+=tree[i].w;
		//cout<<x<<' '<<y<<' '<<tree[i].w<<"\n";
		if(x<=n&&!vis[x]){
			num++;
			vis[x]=1;
		}
		if(y<=n&&!vis[y]){
			num++;
			vis[y]=1;
		}
		if(num>=n){
			break;
		}
		if(x>n&&!vis[x]&&c[x]!=0){
			vis[x]=1;
			for(int j=i+1;j<=m;j++){
				if(tree[j].u==x){
					tree[j].w-=c[x];
				}
			}
			sort(tree+i+1,tree+1+m,cmp);
		}
	}
	printf("%lld",sum);
	return 0; 
}
