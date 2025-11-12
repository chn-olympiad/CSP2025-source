#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
const int N=1e7+10;
int n,m,k,fa[N];
ll tot;
struct note{
	int u,v,w;
}e[N];
bool cmp(note a,note b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	for(int i=1;i<=m;++i)
		cin>>e[i].u>>e[i].v>>e[i].w;
	int c;
	for(int j=n+1;j<=n+k;++j){
		cin>>c;
		int a;
		for(int i=1;i<=n;++i){
			cin>>a;
			e[++m].u=j,e[m].v=i,e[m].w=a+c;
		}
	}
	for(int i=1;i<=n+k;++i) fa[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;++i){
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu!=fv){
			fa[fv]=fu;
			tot+=e[i].w;
			cnt++;
		}
		else if(e[i].w<0) tot+=e[i].w;
	} 
	cout<<tot;
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	solve1();
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
