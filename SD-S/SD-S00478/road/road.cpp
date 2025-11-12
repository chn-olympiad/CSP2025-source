#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//value
const int inf=1e9+5;
const int mod=1e9+7;
const int N=1e4+5;
const int M=1e6+5;
struct edge{
	int u,v,w;
}e[M];
struct node{
	int v,w;
};
int n,m,k;
int fa[N],c[N],a[15][N];
int g[1005][1005],dis[N];
int vis[50][10],dp[10],tot;


//function
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void solve1(){
	//1~4
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		fa[find(u)]=find(v);
		ans+=w;
		cnt++;
		if(cnt==n)break;
	}
	cout<<ans<<endl;
	
	return;
}
void dfs(int x){
	if(x>k){
		for(int i=1;i<=k;i++)vis[++tot][i]=dp[i];
		return;
	}
	dp[x]=0;
	dfs(x+1);
	dp[x]=1;
	dfs(x+1);
	
	return; 
}
void solve2(){
	dfs(1);
	ll ans=2e18+5;
	for(int _=1;_<=tot;_++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=inf;
			}
			g[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			g[u][v]=min(g[u][v],w);
			g[v][u]=min(g[v][u],w);
		}
		ll sum=0;
		for(int j=1;j<=k;j++){
			if(vis[_][j]==1){
				for(int i1=1;i1<=n;i1++){
					for(int j1=1;j1<=n;j1++){
						g[i1][j1]=min(g[i1][j1],a[j][i1]+a[j][j1]);
					}
				}
				sum+=c[j];
			}
		}
		for(int i=1;i<=n;i++)dis[i]=inf;
		int tmp=1,mi=inf;
		for(int i=1;i<n;i++){
			dis[tmp]=0;
			mi=inf;
			for(int j=1;j<=n;j++){
				if(dis[j]==0)continue;
				dis[j]=min(dis[j],g[tmp][j]);
			}
			for(int j=1;j<=n;j++){
				if(dis[j]==0)continue;
				if(dis[j]<mi){
					tmp=j;
					mi=dis[j];
				}
			}
			sum+=mi;
		}
		ans=min(ans,sum);
	}
	
	cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(0); 
	cin.tie(); 
	cout.tie();
	
	freopen("road.in","r",stdin); 	
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	} 
	int cnt=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		if(c[i]==0)cnt++;
	}
	if(k==0)solve1();
	else solve2();
	
	 
	
	//15:42严肃思考，感觉是最小生成树
	//15:46输出0有32分？？
	//15:49有点不行了，有点晕
	//15:51不对，性质A不是输出0，让我看看这个性质A是给什么的
	//15:54纯MST有16pts，利用乡村缩点后的MST有32pts
	//16:09咖啡喝完了，没有任何食物
	//16:15主要性质好像在村庄上啊，那我k轮最小生成树有没有说法
	//16:42我好像有了一个O(m log m + 2^k nk)的一个想法
	//原图跑一边最小生成树，求出当前的答案
	//对于所有的村庄选择方案进行枚举
	//如果我选择了某村庄，则我对于(i,j)连了一条权为a_i+a_j的边
	//尝试用这个东西去更新最小生成树上的边
	//判断最后答案是否能更新
	//等等，这玩意真的对吗
	//16:51先写暴力 
	//17:18草草草 我的关于性质A的想法好像是错的 
	//谢谢你ccf
	
	return 0;
}

