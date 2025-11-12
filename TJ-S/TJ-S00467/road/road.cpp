#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
int n,m,k;
int fa[N];
struct node{
	int u,v,w;
};
node edge[M];
bool operator <(node &a,node &b){
	return a.w<b.w;
}
int findfa(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=findfa(fa[x]);
}
void kruskal(){
	int ans=0;
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edge+1,edge+m+1);
//	for(int i=1;i<=m;i++){
//		printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
//	}
	int fl=1;
	while(fl<=m){
		node tmp=edge[fl];
		fl++;
		if(findfa(tmp.u)!=findfa(tmp.v)){
			ans+=tmp.w;
			fa[tmp.v]=fa[tmp.u];
		}
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	if(k==0){
		kruskal();
	}
	
	return 0;
}
