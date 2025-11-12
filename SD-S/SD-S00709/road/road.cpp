#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,c[N],sum,fa[N],x,y;
struct node{
	int u,v,w;
}a[10*N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int Find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	fa[Find(x)]=Find(y);
}
void kruscal(){
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		x=a[i].u,y=a[i].v;
		if(Find(x)==Find(y)) continue;
		printf("%d %d\n",x,y);
		Union(x,y);
		sum+=a[i].w;
	}
	printf("%d",sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j) scanf("%d",&x);
	}
	kruscal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
