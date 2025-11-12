#include <bits/stdc++.h>
#define int long long
using namespace std;
int in(){
	int w = 0;
	char ch = getchar();
	while(ch<'-') ch = getchar();
	while(ch>'-') w = (w<<3)+(w<<1)+(ch&15) , ch = getchar();
	return w;
}
const int K = 15 , N = 1e4+15 , M = 1e6+15;
int n,m,k,a[K][N],tot,fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct Edge{
	int u,v,w;
	bool operator < (const Edge & b)const &{
		return w<b.w;
	}
}tmp[N*K],e[M],b[N];
void kruskal1(){
	sort(e+1,e+m+1);
	for(int i = 1 ; i<=n ; i++) fa[i] = i;
	int cnt = 0;
	for(int i = 1 ; i<=m ; i++){
		int fx = find(e[i].u) , fy = find(e[i].v);
		if(fx!=fy) b[++cnt] = e[i] , fa[fx] = fy;
	}
//	for(int i = 1 ; i<=cnt ; i++) cout<<"i:"<<i<<" b:"<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<"\n";
	return ;
}
int kruskal(int num){
	sort(tmp+1,tmp+tot+1);
	for(int i = 1 ; i<=n+k ; i++) fa[i] = i;
	int ret = 0;
	for(int i = 1 , cnt = 0 ; i<=tot&&cnt<num ; i++){
		int fx = find(tmp[i].u) , fy = find(tmp[i].v);
		if(fx!=fy) ++cnt , ret+=tmp[i].w , fa[fx]=fy;
	}
	return ret;
}
int sta[K];
int ans = 1e17;
void dfs(int step){
	if(step>k){
		tot = 0;
		for(int i = 1 ; i<n ; i++) tmp[++tot] = b[i];
		int res = 0 , cnt = 0;
		for(int i = 1 ; i<=k ; i++)
			if(sta[i]){
				++cnt;
				res+=a[i][1];
				for(int j = 1 ; j<=n ; j++)
					tmp[++tot]={j,n+i,a[i][j+1]};
			}
		ans = min(ans,res+kruskal(n+cnt));
		return ;
	}
	sta[step] = 0;
	dfs(step+1);
	sta[step]=1;
	dfs(step+1);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = in() , m = in() , k = in();
	for(int i = 1 ; i<=m ; i++) e[i].u=in(),e[i].v=in(),e[i].w=in();
	for(int i = 1 ; i<=k ; i++){
		for(int j = 1 ; j<=n+1 ; j++){
			a[i][j] = in();
		}
	}
	kruskal1();
	dfs(1);
	cout<<ans;
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/