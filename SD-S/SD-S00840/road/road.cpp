#include<bits/stdc++.h>
#define ll long long
#define getchar() (p1==p2&&(p1 = buf)==(p2 = buf+fread(buf,1,1<<20,stdin))?EOF:*p1++)
using namespace std; 
namespace FI{
	char buf[1<<20],*p1 = buf,*p2 = buf;
	inline int read(){
		int s = 0;char ch = getchar();
		while(!isdigit(ch))ch = getchar();
		while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
		return s;
	}
}
using FI::read;
const int N = 10012,M = 1e6+5;
struct Re{
	int u,v,w;
	bool operator<(const Re& b)const{return w<b.w;}
}re[M],te[12][N];
int n,m,K,sz[N],f[N],ec[12],cs[12],a[12][N],ai[12][N],id[N];
ll ans;
int getf(int p){
	if(f[p]==p)return p;
	return f[p] = getf(f[p]);
}
inline bool merge(int u,int v){
	u = getf(u);v = getf(v);
	if(u==v)return 0;
	if(sz[u]<sz[v])swap(u,v);
	f[v] = u;sz[u]+=sz[v];
	return 1;
}
void initf(const int pn){
	for(int i = 1;i<=pn;i++){
		sz[i] = 1;
		f[i] = i;
	}
}
void solve(int pc,int pi,ll pv){
	if(pi==K+1)return;
	solve(pc,pi+1,pv);
	initf(n+K);
	const int lc = pc++,ps = lc+n;
	pv+=cs[pi];
	ll res = pv;
	ec[pc] = 0;
	int pa = 1,pb = 1;
	Re pe;
	while(ec[pc]<ps){
		if(te[lc][pa].w<a[pi][ai[pi][pb]])pe = te[lc][pa++];
		else{
			pe = {pi+n,ai[pi][pb],a[pi][ai[pi][pb]]};
			pb++;
		}
		if(merge(pe.u,pe.v)){
			te[pc][++ec[pc]] = pe;
			res+=pe.w;
		}
	}
	te[pc][++ec[pc]] = {0,0,1<<30};
	ans = min(ans,res);
	solve(pc,pi+1,pv);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();K = read();
	for(int i = 1,u,v,w;i<=m;i++){
		u = read();v = read();w = read();
		re[i] = {u,v,w};
	}
	sort(re+1,re+m+1);
	initf(n);
	for(int i = 1;i<=m;i++){
		if(merge(re[i].u,re[i].v)){
//			cerr << re[i].u << ' ' << re[i].v << "\n";
			te[0][++ec[0]] = re[i];
			ans+=re[i].w;
		}
	}
	te[0][++ec[0]] = {0,0,1<<30};
	for(int i = 1;i<=K;i++){
		cs[i] = read();
		for(int j = 1;j<=n;j++){
			a[i][j] = read();
			id[j] = j;
		}
		a[i][0] = 1<<30;
		sort(id+1,id+n+1,[&](int x,int y){return a[i][x]<a[i][y];});
		for(int j = 1;j<=n;j++)ai[i][j] = id[j];
	}
	solve(0,1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

