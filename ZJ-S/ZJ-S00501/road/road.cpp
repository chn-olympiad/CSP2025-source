#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int fa[N],tot=0,k,ans=0,c[N],a[20][N],n,cnt=0;
struct node{
	int u,v,w,id;
}e[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]); 
}
void kruscal(){
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		//int res=w,resj=0;
		//cout<<u<<" "<<v<<" "<<w<<endl;
		if(find(u)==find(v))continue;
		fa[find(u)]=find(v);
		/*for(int j=1;j<=k;j++){
			if(a[j][u]+a[j][v]+c[j]<=res){
				res=a[j][u]+a[j][v]+c[j];
				resj=j;
			}
		}*/
		//if(resj)c[resj]=0;
		/*if(e[i].id){
			w-=c[e[i].id];
			c[e[i].id]=0;
		}*/
		ans+=w;
		cnt++;
		if(cnt==n-1)return;
		//cout<<ans<<endl;
	}
}
void dfs(int u){
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int p=j+1;p<=n;p++){
				e[++tot]={j,p,0,i};
			}
		}
	}
	//for(int i=1;i<=tot;i++)if(e[i].id)e[i].w=c[e[i].id]+a[e[i].id][e[i].u]+a[e[i].id][e[i].v];
//	for(int i=1;i<=tot;i++)cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	sort(e+1,e+tot+1,cmp);
	kruscal();
	/*for(int i=1;i<=n;i++){
		dfs(i);
	}*/
	cout<<ans;
}
//16pts
