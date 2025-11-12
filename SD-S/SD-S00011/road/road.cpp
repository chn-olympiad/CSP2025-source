#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,num,c[11][10005];
long long int ans;
int fa[10005];
struct node{
	int from,to,s;
}d[1000005];
void add(int u,int v,int sum){
	d[++num].from=u;
	d[num].to=v;
	d[num].s=sum;
}
bool cmp(node a,node b){
	return a.s<b.s;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	sort(d+1,d+1+num,cmp);
	for(int i=1;i<=m;i++){
		if(find(d[i].from)!=find(d[i].to)){
			ans+=d[i].s;
			fa[fa[d[i].from]]=fa[d[i].to];
		}
	}
	printf("%lld",ans);
}

