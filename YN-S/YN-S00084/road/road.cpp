#include<bits/stdc++.h>
using namespace std;

const int scxn=1e4+10;
const int scxm=1e6+10;
int tot,head[scxn];
struct node{
	int fm,to,val;
}edge[2*scxm];
void add(int u,int v,int w){
	edge[++tot]={u,v,w};
	head[u]=tot;
}

int n,m,k;
int fa[scxn];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	init();
	int ans=0;
	sort(edge+1,edge+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int u=edge[i].fm,v=edge[i].to;
		if(fd(u)!=fd(v)){
			fa[fd(v)]=fd(u);
			ans+=edge[i].val;
		}
	}
	cout<<ans;
	return 0;
}
