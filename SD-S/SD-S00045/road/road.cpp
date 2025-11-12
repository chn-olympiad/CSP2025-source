#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
int n,m,k,c[15],con[10005][15],fa[10005];
struct node{
	int u,v,w;
}edge[1000005];
long long ans;
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
	return;
}
int findfa(int x){
	if(x==fa[x]) return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}
void kruskal(){
	init();
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		//cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
		int uu=edge[i].u,vv=edge[i].v;
		int ffu=findfa(uu),ffv=findfa(vv);
		if(ffu!=ffv){
			//cout<<"%%%%"<<uu<<" "<<ffu<<";"<<vv<<" "<<ffv<<endl;
			fa[ffu]=ffv;
			ans+=1ll*edge[i].w;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&con[j][i]);
		}
	}
	kruskal();
//	for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
	printf("%lld",ans);
	return 0;
}
