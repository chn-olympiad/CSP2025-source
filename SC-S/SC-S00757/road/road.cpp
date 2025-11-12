#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10,M=2e9+10;
long long n,m,k,fa[N],new_road[11][N],ans=0;
struct node{
	long long u,v,w;
}e[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}void bing(int x,int y){
	if(find(x)!=find(y))fa[y]=x;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void solve1(){
	ans=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			bing(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	}
	cout<<ans;
}
void solve2(){
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			bing(e[i].u,e[i].v);
			long long minn=M;
			for(int j=1;j<=n;j++)minn=min(minn,(new_road[j][e[i].u]+new_road[j][e[i].v]));
			ans+=min(minn,e[i].w);
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool fl=1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>new_road[i][0];
		if(new_road[i][0]!=0)fl=0;
		for(int j=1;j<=n;j++)cin>>new_road[i][j];
	}sort(e+1,e+1+m,cmp);
	if(k==0)solve1();
	else if(fl)solve2();
	return 0;
}