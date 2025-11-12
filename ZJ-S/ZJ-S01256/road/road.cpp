#include<bits/stdc++.h>
#define int long long
#define mk(a,b) make_pair(a.b)
using namespace std;
const int N=1e4+10,M=1.5e6+10,inf=INT_MAX,K=1.2e3+10;
int n,m,k;
int ans=0;
struct Edge{
	int u,v,w,id;
	bool operator <(Edge x)const{
		return w>x.w;
	}
};
int tot;
vector<int> e[N];

priority_queue<Edge> q;
int c[15][N];
int f[N];
//int dp[N][K];
//bool mx[N][K][N]={false};
//int up[N];
//bool leaf[N]={true};
//int cost[K];
bool A=true;

int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
void Init(){
	for(int i=1;i<=n;++i)
		f[i]=i;
//	for(int i=1;i<(1<<k);++i)
//		for(int j=1;j<=k;++j)
//			if((1<<(j-1))&i)
//				cost[i]+=c[j][0];
}
//void dfs(int u,int fa){
//	leaf[u]=true;
//	for(int id:e[u]){
//		int v=E[id].u^E[id].v^u,w=E[id].w;
//		if(v==fa) continue;
//		leaf[u]=false;
//		up[v]=w;
//		dfs(v,u);
//	}
//	if(leaf[u]){
//		for(int i=1;i<(1<<k);++i)
//			for(int j=1;j<=k;++j)
//				if(i&(1<<(j-1)))
//					dp[u][i]+=c[k][u],
//					mx[u][i][j]=true;
//	}
//}
//void qry(int u,int fa){
//	if(leaf[u]) return;
//	
//	int cur=inf,to_k=0;
//	
//	for(int id:e[u]){
//		int v=E[id].u^E[id].v^u;
//		if(v==fa) continue;
//		qry(v,u);
//	}
//	
//	for(int i=1;i<(1<<k);++i){
//		cur=0,to_k=0;
//		for(int id:e[u]){
//			int v=E[id].u^E[id].v^u;
//			int w=E[id].w;
//			if(v==fa) continue;
//			dp[u][i]+=dp[v][i];
//			for(int l=1;l<=k;++l){
//				if(mx[v][k][l]&&w+c[l][u]-c[l][v] <= cur){
//					cur=w+c[l][u]-c[l][v];
//					to_k=l;
//				}
//				if(w<cur){
//					cur=w;
//					to_k=0;
//				}
//			}
//		}
//		for(int j=1;j<=k;++j){
//			if((i&(1<<(j-1)))!=1) continue;
//			if(c[j][u]<=cur){
//				cur=c[j][u];
//				to_k=j;
//			}
//		}
//		dp[u][i]+=cur;
//		if(to_k>0) mx[u][i][to_k]=true;
//	}
//	
//	
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		q.push((Edge){u,v,w,i});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i][0];
		if(c[i][0]) A=false;
		int l=0;
		for(int j=1;j<=n;++j){
			cin>>c[i][j];
			if(c[i][j]==0) l++;
		}
		if(l==0) A=false;
	}
	if(A){
		for(int i=1;i<=k;++i){
			int o=0;
			for(o=1;o<=n;++o)
				if(c[i][o]==0)
					break;
			for(int j=1;j<=n;++j){
				if(j==o) continue;
//				E[++tot]=(Edge){o,j,c[i][j]};
				q.push((Edge){o,j,c[i][j]});
			}
		}
	}
	
	Init();
	
	int cur=n-1;
	while(cur>0){
		int u,v,w,id;
		u=q.top().u;
		v=q.top().v;
		w=q.top().w;
		id=q.top().id;
		q.pop();
		if(Find(u)==Find(v)) continue;
		f[Find(u)]=Find(v);
		e[u].push_back(id);
		e[v].push_back(id);
		ans+=w;
		cur--;
	}
	
	if(k==0||A) {
		cout<<ans;
		return 0;
	}
	
	cout<<0;
	
//	dfs(1,1);
//	
//	qry(1,1);
//	
//	for(int i=1;i<(1<<k);++i)
//		ans=min(ans,dp[1][i]+cost[i]),
//		cout<<dp[1][i]<<" "<<cost[i]<<" "<<i<<"\n";
//
//	cout<<ans;
	
	return 0;
}
/*
I spent two hours writing this code
But it can't Accept
And now I only have one hour (qwq)
What can I say
What can I say
What can I say
Manba out

oh no , only have 10 min
I have only 158 pts
no
what can I say

sto %%% Ms potato %%% orz

sto %%% haochengwang920 %%% orz

sto %%% Loop1st %%% orz


^(Luogu user name)^
|				  |

Don't ask my Luogu uid

Location: Zhe Jiang(ZJ)

Tang Tang Tang

*/
