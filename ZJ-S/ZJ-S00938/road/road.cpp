#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=1e4+5;
int n,m,k;
vector<pair<int,int> >g[N];
struct node{
	int now;
	long long w;
	bool operator<(const node x)const{
		return w>x.w;
	}
};
bitset<N>vis;
const long long LINF=0x3f3f3f3f3f3f3f3f;
const int IINF=0x3f3f3f3f;
int dis[N][N];
int a[10][N];
long long RES=LINF;
long long solve(int I){
	long long valc=0;
	for(int i=0;i<k;++i)if((I>>i)&1)valc+=a[i+1][0]*1ll;
	if(valc>RES)return RES;;
	priority_queue<node>q;
	vis[1]=true;
	for(int i=2;i<=n;++i){
		vis[i]=false;
		long long mi=dis[1][i]*1ll;
		for(int j=1;j<=k;++j){
			if((I>>(j-1))&1){
				mi=min(mi,a[j][i]*1ll+a[j][1]*1ll);
			}
		}
		if(valc+mi>RES)return RES;
		q.push(node{i,valc+mi});
	}
	long long res=0;
	while(!q.empty()){
		int now=q.top().now;
		long long w=q.top().w;
		q.pop();
		if(vis[now])continue;
		vis[now]=true;
		res+=w;
		if(res>RES)return RES;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			long long mi=dis[now][i]*1ll;
			for(int j=1;j<=k;++j){
				if((I>>(j-1))&1){
					mi=min(mi,a[j][now]*1ll+a[j][i]*1ll);
				}
			}
			q.push({i,mi});
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			dis[i][j]=IINF;
		}
	}
	for(int i=1;i<=m;++i){
		int x,y,w;
		cin>>x>>y>>w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
		dis[x][y]=dis[y][x]=min(dis[x][y],w);
	}
	for(int i=1;i<=k;++i)for(int j=0;j<=n;++j)cin>>a[i][j];
	if(k==0){
		priority_queue<node>q;
		vis[1]=true;
		int len=g[1].size();
		for(int i=0;i<len;++i)q.push(node{g[1][i].first,g[1][i].second*1ll});
		long long res=0;
		while(!q.empty()){
			int now=q.top().now;
			long long w=q.top().w;
			q.pop();
			if(vis[now])continue;
			vis[now]=true;
			res+=w;
			len=g[now].size();
			for(int i=0;i<len;++i){
				int y=g[now][i].first;
				w=g[now][i].second*1ll;
				if(vis[y])continue;
				q.push(node{y,w});
			}
		}
		cout<<res<<endl;
	}
	else{
		RES=LINF;
		for(int I=0;I<(1<<k);++I){
			RES=min(RES,solve(I));
			if(RES==0){
				cout<<RES<<endl;
				return 0;
			}
		}
		cout<<RES<<endl;
	}
	return 0;
}