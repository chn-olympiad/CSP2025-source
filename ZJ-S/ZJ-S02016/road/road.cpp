#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e4+5,maxk=15;
const LL inf=1e18+1;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
struct edge{
	int u,v,w;
	bool operator<(const edge& a)const{
		return w<a.w;
	}
};
vector<edge> e,ve;
int n,m,k;
int f[maxn],cp[maxn],mn[maxn][maxk];
int p[maxk][maxn];
void init_dsu(int s){
	for(int i=1;i<=s;i++) f[i]=i;
}
int find_f(int u){
	if(f[u]==u) return u;
	else return f[u]=find_f(f[u]);
}
bool merge(int u,int v){
	u=find_f(u),v=find_f(v);
	if(u==v) return false;
	f[u]=v;
	return true;
}
void kruscal(){
	sort(e.begin(),e.end());
	init_dsu(n);
	for(int i=0;i<(int)e.size();i++){
		if(merge(e[i].u,e[i].v)){
			ve.push_back(e[i]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	edge in;
	for(int i=1;i<=m;i++){
		read(in.u),read(in.v),read(in.w);
		e.push_back(in);
	}
	for(int i=1;i<=k;i++){
		read(cp[i]);
		for(int j=1;j<=n;j++){
			read(p[i][j]);
		}
	}
	kruscal();
	int tp=(1<<k);
	LL ans=inf;
	for(int i=0;i<tp;i++){
		vector<int> d;
		LL ansi=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)) d.push_back(j+1),ansi+=cp[j+1];
		}
		init_dsu(n);
		for(int j=1;j<=n;j++){
			for(int k=0;k<(int)d.size();k++){
				mn[j][d[k]]=p[d[k]][j];
			}
		}
		for(int j=0;j<(int)ve.size();j++){
			int l=ve[j].w,ui,vi;
			for(int k=0;k<(int)d.size();k++){
				ui=find_f(ve[j].u),vi=find_f(ve[j].v);
				l=min(l,mn[ui][d[k]]+mn[vi][d[k]]);
				mn[vi][d[k]]=min(mn[ui][d[k]],mn[vi][d[k]]);
			}
			ansi+=l,merge(ve[j].u,ve[j].v);
		}
		ans=min(ans,ansi);
	}
	printf("%lld",ans);
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
