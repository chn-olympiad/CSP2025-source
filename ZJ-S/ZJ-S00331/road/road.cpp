#include<bits/stdc++.h>
using namespace std;
long long fa[10005],n,m,k,cnt,c[10005],ans=0;
struct edge{
	long long u,v,w;
}e[2000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void init(){
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
}
long long find(long long x){
	if(x==fa[x])return x;
	//if(find(fa[x])==fa[x])return fa[x];
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(long long x,long long y){
	fa[find(x)]=find(y);//cout<<x<<y<<'\n';
}
signed main(){//no villages
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=0;
	for(long long i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		cnt++;
		e[cnt].u=u,e[cnt].v=v,e[cnt].w=w;
	//	cnt++;		
	//	e[cnt].u=v,e[cnt].v=u,e[cnt].w=w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[1];
		for(long long j=1;j<=n;j++)cin>>c[j];
		
	}
	init();
	sort(e+1,e+1+m,cmp);
	//for(int i=1;i<=m;i++)cout<<e[i].w;
	for(long long i=1;i<=cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	//for(int i=1;i<=n;i++)cout<<fa[i];
	cout<<ans;
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
/*
4 6 0
1 2 2
3 2 7
4 2 5
3 1 1
3 4 4
1 4 6
*/