#include<bits/stdc++.h>
#define endl '\n'
#define ri register int
#define int long long
#define fixedset(a) fixed << setprecision(a)
#define pii pair<int,int>
#define mp make_pair
#define ls(x) x<<1
#define rs(x) x<<1|1
#define eps 1e-7
#define inf 1014514
#define mf 5011
#define sf 1011
#define MOD 114514
#define mod(x) (x+MOD)%MOD;
using namespace std;
int n,m,p,ans,num[inf],dis[sf][sf];
struct route{
	int u,v,w;
	friend bool operator <(route A,route B){
		return A.w<=B.w;
	}
}rcd[inf];
struct DSU{
	vector<int> fa;
	DSU(int g){
		fa.resize(g+1);
		for(ri i=1;i<=g;i++) fa[i]=i;
	}
	int find(int g){
		if(fa[g]==g) return g;
		else return fa[g]=find(fa[g]);
	}
	void merge(int u,int v){
		u=find(u),v=find(v);
		if(u!=v) fa[u]=v;
	}
	bool query(int u,int v){
		if(find(u)==find(v)) return true;
		else return false;
	}
};
bool checkans1(){ //纯生成树
	if(p==0) return true;
	else return false;
}
bool checkans2(){
	if(n<=1001) return true;
	else return false;
}
void getans1(){
	for(ri i=1;i<=m;i++){
		int u,v,w; cin >> u >> v >> w;
		rcd[i].u=u,rcd[i].v=v,rcd[i].w=w;
	}
	sort(rcd+1,rcd+1+m);
	DSU dsu(n);
	for(ri i=1;i<=m;i++){
		int u=rcd[i].u,v=rcd[i].v,w=rcd[i].w;
		if(!dsu.query(u,v)){
			dsu.merge(u,v); ans+=w;
		}
	}
	return ;
}
void getans2(){
	int idx=0;
	for(ri i=1;i<=n;i++) for(ri j=1;j<=n;j++) dis[i][j]=20000000000;
	for(ri i=1;i<=m;i++){
		int u,v,w; cin >> u >> v >> w;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(ri i=1;i<=p;i++){
		int q; cin >> q;
		for(ri j=1;j<=n;j++) cin >> num[j];
		for(ri j=1;j<=n;j++) for(ri k=1;k<=n;k++) dis[j][k]=min(dis[j][k],q+num[j]+num[k]);
	}
	
	for(ri i=1;i<=n;i++) for(ri j=1;j<=n;j++){
		if(i==j) continue;
		idx++;
		rcd[idx].u=i; rcd[idx].v=j; rcd[idx].w=dis[i][j];
	}
	sort(rcd+1,rcd+idx+1);
	DSU dsu(n);
	for(ri i=1;i<=idx;i++){
		int u=rcd[i].u,v=rcd[i].v,w=rcd[i].w;
		if(!dsu.query(u,v)){
			dsu.merge(u,v); ans+=w;
		}
	}
	return ;
}
void getans3(){
	ans=0;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> p;
	if(checkans1()) getans1();
	else if(checkans2()) getans2();
	else getans3();
	cout << ans << endl;
	return 0;
}