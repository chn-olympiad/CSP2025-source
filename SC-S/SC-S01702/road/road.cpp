#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
using AR=array<int,3>;
int n,m,k;
vector<AR> Edges;
VI ctcost;
vector<VI> newct;
const int MAXN=1e4+50;
const LL INF=1e18;
int fa[MAXN];
int find(int x){
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void solve1(){
	LL ans=INF;
	FOR(i,0,1<<k){
		LL res=0;
		vector<AR> Edge2=Edges;
		REP(j,1,k)if((i>>(j-1))&1){
			REP(t,1,n)Edge2.push_back({newct[j][t],n+j,t});
			res+=ctcost[j];
		}
		sort(begin(Edge2),end(Edge2));
		REP(j,1,n+k)fa[j]=j;
		FOR(j,0,(int)Edge2.size()){
			int a=Edge2[j][1],b=Edge2[j][2],w=Edge2[j][0];
			if(find(a)==find(b))continue;
			fa[find(a)]=find(b),res+=w;
		}
		ans=min(ans,res);
	}
	cout<<ans;
}
void solve2(){
	LL ans=0;
	REP(i,1,k){
		REP(t,1,n)Edges.push_back({newct[i][t],n+i,t});
		ans+=ctcost[i];
	}
	sort(begin(Edges),end(Edges));
	REP(i,1,n+k)fa[i]=i;
	FOR(i,0,(int)Edges.size()){
		int a=Edges[i][1],b=Edges[i][2],w=Edges[i][0];
		if(find(a)==find(b))continue;
		fa[find(a)]=find(b),ans+=w;
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	Edges.resize(m);
	ctcost.resize(k+1),newct.resize(k+1,VI(n+1));
	FOR(i,0,m)cin>>Edges[i][1]>>Edges[i][2]>>Edges[i][0];
	REP(i,1,k){
		cin>>ctcost[i];
		REP(j,1,n)cin>>newct[i][j];
	}
	if(k<=5)solve1();//32pts
	else solve2();//24pts
	return 0;
}
