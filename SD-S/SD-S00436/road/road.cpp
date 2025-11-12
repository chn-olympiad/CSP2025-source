#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define fir first
#define sec second
#define endl '\n'
const int N=1e6+5,M=5e3+5;

//T2 prim ji ke.
int n,m,k;
int a[N];
struct C{
	int u,v,w;
	bool operator <(const C &b) const {
		if(w==b.w){
			if(v==b.v)return u<b.u;
			return v<b.v;
		}
		return w<b.w;
	}
};
vector<C> edge;
set<C> e2;
vector<pair<int,int> > g[N];
int fa[N],s[N];
int fifa(int x){
	if(fa[x]==x)return x;
	return fa[x]=fifa(fa[x]);
}
void clo(int u,int v){
	int x=fifa(u),y=fifa(v);
	if(s[x]>s[y])swap(x,y);
	s[y]+=s[x];
	fa[x]=y;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edge.push_back({u,v,w});
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		s[i]=1;
	}
	sort(edge.begin(),edge.end());
	int ans=0;
	for(auto e:edge){
		int u=e.u,v=e.v;
		int w=e.w;
		if(fifa(e.u)==fifa(e.v)){
			continue;
		}
		e2.insert(e);
		ans+=w;
		clo(u,v);
	}
	for(int i=1;i<=k;i++){
		cin >> a[i];
		for(int j=1;j<=n;j++){
			int w;
			cin >> w;
			g[j].push_back({i,w});
			g[i].push_back({j,w});
		}
	}
	for(int i=0;i<(1<<k);i++){
		int res=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				for(auto e:g[j+1]){
					e2.insert({j+n+1,e.fir,e.sec});
				}
				res+=a[j+1];
			}
		}
		for(int i=1;i<=n+k+1;i++){
			fa[i]=i;
			s[i]=1;
		}
		for(auto it=e2.begin();it!=e2.end();it++){
			if(fifa(it->u)==fifa(it->v)){
				continue;
			}
			res+=it->w;
//			if(it->w==501020)cerr << i << "asdfghjkl;\n";
//			cout << i->u << ' ' << i->v << "florr.io" << endl;
			clo(it->u,it->v);
		}
		ans=min(ans,res);
//		cout << i << ' ' << res << endl;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				for(auto e:g[j+1]){
					e2.erase({j+n,e.fir,e.sec});
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}






//* Some strong music rings...
/*
Today is 20251101.
The code is by XYM!!!

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
//We are strange to love.
//You know the rules and so do I~
//
//Never gonna give you up.
//Never gonna let you down.
//Never gonna run around and hurt you.
//Never gonna make you cry.
//Never gonna say goodbye.
//Never gonna run around and hurt you.
//
//luogu UID 1433474,luogu name Meng_Xiangyu
//I AKed CSP-J this morning.

