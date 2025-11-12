#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define itn int
#define int ll
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=1e4+5;
const int M=1e6+5;
const int K=10+5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &b)const{
		return w<b.w;
	}
}e[M+N*K*2];
int n,m,k,tot,ans=1e18,fa[N+K*2];
bool vis[N+K*2];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
void Solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		tot++;
		cin>>e[tot].u>>e[tot].v>>e[tot].w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		e[++tot]=(Edge){i+n,k+i+n,c};
		for(int j=1;j<=n;j++){
			cin>>c;
			e[++tot]=(Edge){k+i+n,j,c};
		}
	}
	for(int i=1;i<=n;i++)
		vis[i]=1;
	sort(e+1,e+tot+1);
	for(int S=0;S<(1<<k);S++){
		int cm=n+2*__builtin_popcount(S);
		fill(vis+n+1,vis+n+2*k+1,0);
		for(int i=1;i<=k;i++)
			if(S&(1<<(i-1)))
				vis[n+i]=vis[n+k+i]=1;
		int res=0,cnt=0;
		for(int i=1;i<=n+k*2;i++)
			fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(res>=ans)break;
			if(vis[e[i].u] and vis[e[i].v]){
				int u=find(e[i].u);
				int v=find(e[i].v);
				if(u!=v){
					fa[u]=v;
					res+=e[i].w;
					cnt++;
					if(cnt==cm-1){
						ans=min(ans,res);
						break; 
					}
				}
			}
		}
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}
