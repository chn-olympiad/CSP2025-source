#include<bits/stdc++.h>
#define lon long long
using namespace std;
int n,m,k;//1e4 1e6 10
int fa[10010];
lon c[110];
lon a[10010];
int wz;
lon ans;
struct edge{
	int u,v;
	lon w;
	const operator< (const edge a)const {return w<a.w;}
	const operator> (const edge a)const {return w>a.w;}
}d;
priority_queue<edge,vector<edge>,greater<edge> > q;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve(){
	int x,y;
	int xx,yy;
	lon z;
	while(!q.empty()){
		x=q.top().u;
		y=q.top().v;
		z=q.top().w;
		q.pop();
		xx=find(x);
		yy=find(y);
		if(xx!=yy){
			fa[xx]=yy;
			ans+=z;
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>d.u>>d.v>>d.w,q.push(d);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(!a[j]) wz=j;
		}
		for(int j=1;j<=n;j++) if(j!=wz){
			d.u=j;
			d.v=wz;
			d.w=a[j];
			q.push(d);
		}
	}
	solve();
	return 0;
}
