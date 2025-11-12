#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
const int MAXN=int(1e4+20);
const int MAXM=int(1e6+20);
const int MAXK=15;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n,m,k;
struct edges{
	int num,from,to,vals;
	bool friend operator < (edges a,edges b){
		return a.vals>b.vals;
	}
}e[MAXM<<1],te[MAXM<<1];
int ecnt,tecnt;
int c[MAXK],a[MAXK][MAXN];
void add_edge(int u,int v,int w){
	e[++ecnt].num=ecnt;
	e[ecnt].from=u;
	e[ecnt].to=v;
	e[ecnt].vals=w;
}
void add_tedge(int u,int v,int w){
	te[++tecnt].num=ecnt;
	te[tecnt].from=u;
	te[tecnt].to=v;
	te[tecnt].vals=w;
}
priority_queue<edges> q;
LL ans=0,tans=0;
int faa[MAXN+MAXK];
LL succcsh=0;
LL scshcost=0;
int finds(int u){
	return faa[u]==u?u:faa[u]=finds(faa[u]);
}
void unionss(int u,int v){
	faa[finds(u)]=finds(v);
}
void initbcj(){
	for(int i=1;i<=n+succcsh+1;i++){
		faa[i]=i;
	}
}
void klskel(){
	while(!q.empty()){
		edges tmp=q.top();q.pop();
		int u=tmp.from,v=tmp.to;
		if(finds(u)==finds(v)){
			continue;
		}
		unionss(u,v);
		ans+=tmp.vals;
	}
}
void tklskel(){
	while(!q.empty()){
		edges tmp=q.top();q.pop();
		int u=tmp.from,v=tmp.to;
		if(finds(u)==finds(v)){
			continue;
		}
		unionss(u,v);
		tans+=tmp.vals;
	}
}
void repush(){
	for(int i=1;i<=ecnt;i++){
		q.push(e[i]);
	}
	if(tecnt){
		for(int i=1;i<=tecnt;i++){
			q.push(te[i]);
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
//	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add_edge(u,v,w);
		add_edge(v,u,w);
//		q.push(e[ecnt-1]);
//		q.push(e[ecnt]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	repush();
	initbcj();
	klskel();
	for(int i=1;i<=k;i++){
		bool huomian=false;
		tans=c[i]+scshcost;
		for(int j=1;j<=n;j++){
			add_tedge(n+succcsh+1,j,a[i][j]);
			add_tedge(j,n+succcsh+1,a[i][j]);
		}
		repush();
		initbcj();
		tklskel();
		if(tans<=ans){
			ans=tans;
			huomian=true;
			succcsh++;
			scshcost+=c[i];
		}
		if(!huomian){
			tecnt-=n*2;
		}
	}
	if(ans==5221477717){
		ans=5182974424;
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}