//road
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e6+5;
const ll inf=1e15;

int n,m,k,x,y,z,tot,len;
int fa[N],sz[N],c[N],d[N];
ll ans,ns;
struct line{
	int x,y,z;
	bool operator<(line b)const{return z<b.z;}
}g[15][N];
priority_queue<pair<int,int>> q;

inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

inline void merge(int x,int y){
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y];
	fa[y]=x;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>z;
		g[k+1][i]={x,y,z};
	}
	sort(g[k+1]+1,g[k+1]+m+1); 
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>x;
			g[i][j]={n+i,j,x};
		}
		sort(g[i]+1,g[i]+n+1);
	}
	for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i){
		x=find(g[k+1][i].x);
		y=find(g[k+1][i].y);
		if(x==y) continue;
		merge(x,y);
		g[0][++tot]=g[k+1][i];
		if(tot==n-1) break;
	}
	ans=inf;
	for(int st=0;st<(1<<k);++st){
		ns=0;len=n;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
		d[0]=1;
		q.push({-g[0][1].z,0});
		for(int i=1;i<=k;++i){
			if((st>>i-1)&1){
				len++;
				d[i]=1;
				ns+=c[i];
				fa[n+i]=n+i,sz[n+i]=1;
				q.push({-g[i][1].z,i});
			}
		}
		while(!q.empty()){
			int now=q.top().second;q.pop();
			x=g[now][d[now]].x,y=g[now][d[now]].y;
			x=find(x),y=find(y);
			if(x^y){
				ns+=g[now][d[now]].z;
				len--;
				if(len==1) break;	
				merge(x,y);
			}
			d[now]++;
			if(d[now]<=n-(!now)) q.push({-g[now][d[now]].z,now}); 
		}
		ans=min(ans,ns);
	}
	cout<<ans;
	return 0;
}
