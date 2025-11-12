#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int c[15],a[15][10005];
struct node{
	int u,v,w;
}b[2000010];
int cnt;
int fa[10005];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void smalltree(){
	int cntx=0;
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int v=b[i].v,u=b[i].u;
		if(find(v)!=find(u)){
			cntx++;
			ans+=b[i].w;
			fa[v]=find(u);
		}
		if(cntx==n-1) return ;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[++cnt].u=u;
		b[cnt].v=v;
		b[cnt].w=w;
		fa[u]=u;
		fa[v]=v;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(k==0){
		smalltree();//¸Ğ¾õÒª·Ï  
		cout<<ans;
		return 0;
	}
	return 0;
}

