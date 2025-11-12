#include<bits/stdc++.h>
using namespace std;
#define maxk 13
#define maxn 10019
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
void file(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
int n,m,k;
struct Edge{
	int u,v;
	ll w;
	bool operator < (const Edge &ano)const{
		return w<ano.w;
	}
};
vector<Edge> G;
int cntc;
int lst[maxk];
ll c[maxk],a[maxk][maxn];
int fa[maxn];
void init(){
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
}
int get_fa(int pos){
	return (fa[pos]==pos)?pos:fa[pos]=get_fa(fa[pos]);
}
ll cst;
vector<Edge> kG;
void kruskal(){
	init();
	sort(G.begin(),G.end());
	for(Edge now:G){
		int fu=get_fa(now.u),fv=get_fa(now.v);
		if(fu==fv){
			continue;
		}
		fa[fu]=fv;
		cst+=now.w,kG.push_back(now);
	}
}
vector<Edge> tmpG,tmpkG;
ll tmpcst,sumc;
int cnt[maxk];
void solve(int id){
	init();
	tmpG=kG;
	tmpkG.clear();
	for(int i=1;i<=n;++i){
		Edge tmp;
		tmp.u=n+lst[id],tmp.v=i,tmp.w=a[lst[id]][i];
		tmpG.push_back(tmp);
	}
	tmpcst=sumc=0;
	for(int i=1;i<=k;++i){
		cnt[i]=0;
		sumc+=c[i];
	}
	init();
	sort(tmpG.begin(),tmpG.end());
	for(Edge now:tmpG){
		int fu=get_fa(now.u),fv=get_fa(now.v);
		if(fu==fv){
			continue;
		}
		fa[fu]=fv;
		tmpcst+=now.w,tmpkG.push_back(now);
		if(now.u>n){
			++cnt[now.u-n];
		}
	}
	for(int i=1;i<=k;++i){
		if(cnt[i]==0){
			sumc-=c[i];
		}else if(cnt[i]==1){
			sumc-=c[i];
			int pos=0;
			while(tmpkG[pos].u!=n+i){
				++pos;
			}
			tmpcst-=tmpkG[pos].w;
			tmpkG.erase(tmpkG.begin()+pos);
		}
	}
	if(cst>sumc+tmpcst){
		cst=sumc+tmpcst;
		kG=tmpkG;
	}
}
bool cmp(int x,int y){
	return c[x]>c[y];
}
int main(){
	file();
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		Edge tmp;
		cin>>tmp.u>>tmp.v>>tmp.w;
		G.push_back(tmp);
	}
	kruskal();
	for(int i=1;i<=k;++i){
		lst[i]=i;
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	sort(lst+1,lst+k+1,cmp);
	for(int i=1;i<=k;++i){
		solve(i);
	}
	cout<<cst;
	return 0;
}
