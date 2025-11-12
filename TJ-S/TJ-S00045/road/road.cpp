#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1000005

int n,m,k,cnt,num,ans;
struct node{
	int u;
	int v;
	int w;
	int col;
}e[M*4];
int f[N];
int c[15];
int vis[15];

void add(int u,int v,int w,int col){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].col=col;
	return;
}

bool cmp(node x,node y){
	return x.w<y.w;
}

void make(){
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	return ;
}

int find(int x){
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}

void join(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a==b) return;
	f[b]=a;
	return;
}

void Kruskal(){
	make();
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		int col=e[i].col;
		if(find(u)==find(v)) continue;
		join(u,v);
		ans+=w;
		if(vis[col]==0){
			ans+=c[col];
			vis[col]=1;
		}
		num++;
		if(num==n-1) return;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w,0);
		add(v,u,w,0);
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int w;
			cin>>w;
			if(i==j){
				c[i]+=w;
			}
			add(i,j,w,i);
			add(j,i,w,i);
		}
	}
	Kruskal();
	cout<<ans;
	return 0;
}
