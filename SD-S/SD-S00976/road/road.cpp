#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+100,INF=1e18;
int n,m,k;
int u[M],v[M],w[M],a[20][N],c[20];
struct edge{
	int u,v,w;
	friend bool operator<(edge x,edge y){
		return x.w>y.w;
	}
};
int f[N+200],sz[N+200];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y,int w,int &sum,int &cnt){
	int fx=find(x),fy=find(y);
	if(fx==fy) return ;
	if(sz[fx]>=sz[fy]) f[fy]=fx,sz[fx]+=sz[fy];
	else f[fx]=fy,sz[fy]+=sz[fx];
	sum+=w,cnt++;
}
priority_queue<edge> pq;
bool check(){
	int fff=find(1);
	for(int i=1;i<=n;i++){
		if(find(i)!=fff) return 0;
	}
	return 1;
}
int solve(int S){
	while(!pq.empty()) pq.pop();
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++) pq.push({u[i],v[i],w[i]});
	for(int i=1;i<=k;i++){
		if(S&(1<<(i-1))){
			sum+=c[i];
			for(int j=1;j<=n;j++){
				pq.push({n+i,j,a[i][j]});
			}
		}
	}
	while(!pq.empty()){
		int summ=sum;
		if(cnt+1>n && check()) return sum;
		edge t=pq.top();
		pq.pop();
		merge(t.u,t.v,t.w,sum,cnt);
	}
	return INF;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int minn=INF;
	for(int i=0;i<=(1<<k)-1;i++){
		minn=min(minn,solve(i));
	}
	cout<<minn;
	return 0;
}

