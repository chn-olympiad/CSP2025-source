#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &o)const{
		return w<o.w;
	}
}e[M],cd[N],tmp[M],oth[11][N];
struct Dsu{
	int siz[N],fa[N];
	void reset(int _n){
		for(int i=1;i<=_n;i++)
			fa[i]=i,siz[i]=1;
	}
	int get(int x){
		return (fa[x]==x?x:(fa[x]=get(fa[x])));
	}
	bool issame(int x,int y){
		return get(x)==get(y);
	}
	void merge(int x,int y){
		if(issame(x,y)) return;
		x=get(x),y=get(y);
		if(siz[x]>siz[y]) swap(x,y);
		fa[x]=y,siz[y]+=siz[x];
	}
}dsu;
typedef long long ll;
int n,m,k,pm,c[12];
ll kruskal(int n,int m,bool first=false){
	dsu.reset(::n+k);ll ans=0;
	for(int i=1;i<=m and n;i++){
		if(dsu.issame(tmp[i].u,tmp[i].v)) continue;
		dsu.merge(tmp[i].u,tmp[i].v),n--;
		if(first) cd[++pm]=tmp[i];
		ans+=tmp[i].w;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++) tmp[i]=e[i];
	ll ans=kruskal(n,m,true);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			oth[i][j].u=n+i,oth[i][j].v=j,cin>>oth[i][j].w;
		sort(oth[i]+1,oth[i]+1+n);
	}
	for(int i=1;i<(1<<k);i++){
		int cm=pm,nn=n;ll res=0;
		for(int j=1;j<=pm;j++) tmp[j]=cd[j];
		for(int j=1;j<=k;j++){
			if(!((i>>(j-1))&1)) continue;
			res+=c[j];nn++;
			for(int b=1;b<=n;b++) tmp[cm+b]=oth[j][b];
			inplace_merge(tmp+1,tmp+cm+1,tmp+cm+n+1);
			cm+=n;
		}
		ans=min(ans,kruskal(nn,cm)+res);
	}
	cout<<ans;
	return 0;
}
/*FOOTNOTE
好的，现在拿到 100 分，我们其实已经够了，不过让我们看看这个题目吧
无向连通图一张，首先可以修复路，如果只有这个
那么就是 MST 板子，不过，你还能选择前 k 个点中的任意几个
改造为特殊点，需要花一点钱，然后可以在它和任意点之间修路，或许
会便宜一点点。
k 果然很小，显然，我们能使用 2^k 的代价枚举他们，
然后我们就会多出 nk 条可选边，此时我们如果直接 MST，
复杂度为 2^kpolylog(nk+m) = 2^kmlogm 不可接受。
我们每次枚举 1e6 个边都不行，但是我们显然需要 2^k 的枚举。
考虑 kruskal 的过程，排序之后尽量选择小的边
不对，我理解错了，乡镇不是这 n 个点的一部分。而是相当于可以
额外添加的点。
对于特性 A，我们能够直接使用 kruskal。
考虑性质很复杂，但是我们考虑如下策略：
第一，先做一次 kruskal，排除无用边，缩减边数为 O(N) 级别，
第二，保留枚举 2^k，为了避免 log，全部提前排序并使用归并进行
合并。
这个方法已经足够优秀了，但是计算量可能仍然是 1e8 级别的，
但是这个可能无法继续优化， 实现。 
验证：一个边如不被选择，那么一定是两边已经连起来了，
现在我排除边这个操作合法吗？原先被排除的边是因为两边已经
连起来了，现在我加入一些别的点，不可能导致连通性反而变差，
所以它该被排除还是会被排除的，因此我的操作是合法的。 
*/
