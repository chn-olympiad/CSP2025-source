#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define MAXM 1000005
#define i64 long long
int n,m,k;
struct Edge{
	int u,v;
	int w;
	bool operator<(const Edge& b)const {return w<b.w;}
}e[MAXM<<1];
int tot;
int fa[MAXN+15];
int c[15];
int a[15][MAXN];
int find(int u){
	if (fa[u]==u) return u;
	fa[u]=find(fa[u]);
	return fa[u]; 
}
i64 solve(vector<int>& p){
	for (int i = 1;i <= n+k;i ++) fa[i]=i;
	i64 res=0;
	int nump=n-1; 
	for (int i = 0;i < k;i ++){
//		cout <<p[i]<<' ';
		if (p[i]) res+=(long long)c[i+1],++nump; 
	}
//	cout <<'\n';
	int numn=0;
	for (int i = 1;i <= tot;i ++){
		int u=e[i].u,v=e[i].v; 
		if (v>n&&!p[v-n-1]||u>n&&!p[u-n-1]) continue;
		i64 w=e[i].w;
		u=find(u),v=find(v);
		if (u==v) continue;
//		cout <<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
		res+=w;
		fa[u]=v;
		++numn;
		if (numn>=nump) break;
//		if (e[i].v>n&&p[e[i].v-n-1]==0) cout <<"!!!!!!!";
//		assert(e[i].v<=n);
	}
//	cout <<'\n';
//	cout <<res<<'\n';
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >>n>>m>>k;
	for (int i = 1,u,v,w;i <= m;i ++){
		cin >>u>>v>>w;	
		e[++tot].u=u;
		e[tot].v=v;
		e[tot].w=w;
	}
	for (int i = 1;i <= k;i ++){
		cin >>c[i];
		for (int j = 1;j <= n;j ++){
			cin >>a[i][j];
			e[++tot].u=j;
			e[tot].v=n+i;
			e[tot].w=a[i][j];
		}
	}
	sort(e+1,e+tot+1);
//	for (int i = 1;i <= tot;i ++) cout <<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
	i64 ans=1e18;
	for (int i = 0;i <= k;i ++){
		vector<int> p(k,1);
		fill(p.begin(),p.begin()+i,0);
		do{
			ans=min(ans,solve(p));
		}while (next_permutation(p.begin(),p.end()));
	}
	cout <<ans;
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
