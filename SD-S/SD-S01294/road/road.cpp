#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=3e6;
int n,m,k,ans;
int tot;
int f[N];
int findf(int x){
	if(x==f[x]) return x;
	return f[x]=findf(f[x]);
}
//struct node{
//	int nxt,to;
//}q[M*2];int cnt,head[N];
//void add(int x,int u){
//	q[++cnt].nxt=head[x];
//	q[cnt].to=u;
//	head[x]=cnt;
//}
struct Edge{
	int u,v,w;
}edge[N];
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
int mor[7][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i) f[i]=i;
	int sum=0;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin >> u >> v >> w;
		edge[++tot].u=u,edge[i].v=v,edge[i].w=w;
	}
	for(int i=1;i<=k;++i){
		int tt;
		cin >> tt;
		for(int j=1;j<=n;++j) cin >> mor[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int w=1e9+19;
			for(int kk=1;kk<=k;++kk){
				w=min(w,mor[kk][i]+mor[kk][j]);
			}
			edge[++tot].u=i,edge[tot].v=j,edge[tot].w=w;
		}
	}
		sort(edge+1,edge+tot+1,cmp);
		for(int i=1;i<=tot;++i){
			//cout << edge[i].u <<' '<< edge[i].v <<' '<< edge[i].w << '\n';
			int fx=findf(edge[i].u),fy=findf(edge[i].v);
			if(fx!=fy){
				f[fx]=fy;
				sum++;
				ans+=edge[i].w;
			}
			if(sum==n-1){
				break;
			}
		}
		cout << ans << '\n';
	return 0;
} 
