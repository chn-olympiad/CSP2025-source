#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+50;
const int MAXM=2e6+10;

int n,m,k,ans=INT_MAX;

struct edge{
	int u,v,w;
	bool operator>(const edge & o)const{
		return w>o.w;
	}
};

priority_queue<edge,vector<edge>,greater<edge> > e;

int c[15],g[15][MAXN],fa[MAXN];

int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

void dfs(int x,int num,int sum){
	if(x==k+1){
		priority_queue<edge,vector<edge>,greater<edge> > e2;
		e2=e;
		for(int i=1;i<=n+num;i++){
			fa[i]=i;
		}
		while(!e2.empty()){
			edge o=e2.top();
			e2.pop();
			if(find(o.u)==find(o.v))continue;
			fa[find(o.u)]=find(o.v);
			sum+=o.w;
		}
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,num,sum);
	for(int i=1;i<=n;i++){
		edge o;
		o.u=x+n;
		o.v=i;
		o.w=g[x][i];
		e.push(o);
	}
	dfs(x+1,num+1,sum+c[x]);
	priority_queue<edge,vector<edge>,greater<edge> > e2;
	while(!e.empty()){
		edge o=e.top();
		if(o.u==n+x){
			e.pop();
		}else{
			e2.push(o);
			e.pop();
		}
	}
	e=e2;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	bool flag=1;
	for(int i=1;i<=m;i++){
		edge o;
		scanf("%d%d%d",&o.u,&o.v,&o.w);
		e.push(o);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		int Min=INT_MAX;
		for(int j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			Min=min(Min,g[i][j]);
		}
		if(c[i]!=0||Min!=0)flag=0;
	}
	if(!flag){
		dfs(1,0,0);
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==0){
				if(find(i+n)!=find(j))
					fa[find(i+n)]=find(j);
			}else{
				edge o;
				o.u=n+i;
				o.v=j;
				o.w=g[i][j];
				e.push(o);
			}
		}
	}
	ans=0;
	while(!e.empty()){
		edge o=e.top();
		e.pop();
		if(find(o.u)==find(o.v))continue;
		fa[find(o.u)]=find(o.v);
		ans+=o.w;
	}
	cout<<ans<<'\n';
	return 0;
}

/*
3 2 1
1 2 2
2 3 3
0 0 1 1
*/
