#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
}e[1000010];
int n,m,k,fa[10010],c[20],a[20][10010];
bool operator < (edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=fa[fa[x]];
	return find(fa[x]);
}
void subtask1(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1);
	int tot=0,x,y,ans=0;
	for(int i=1;tot<n-1&&i<=m;i++){
		x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			fa[x]=y;
			tot++;
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		subtask1();
	}
	
	return 0;
} /*It might be the time for me to AFO*/