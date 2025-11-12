#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+9;
struct Data{
	int num;
	int dis;
};
struct Node{
	int id;
	int dis;
	friend bool operator<(const Node&a,const Node&b){
		return a.dis<b.dis;
	}
};
priority_queue<Node>q;
bool vis[N]={false};
int mp[N][N];
int cz[15][N];
bool book[N][N]={false};
vector<Data>t[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	memset(mp,127,sizeof mp);
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
		mp[i][i]=0;
		book[u][v]=true;
		book[v][u]=true;
		book[i][i]=true;
	}
	for(int i=1;i<=k;++i){
		int num;
		cin>>num;
		for(int j=1;j<=n;++j){
			cin>>cz[i][j];
			if(num==0){
				for(int x=1;x<j;++x){
					mp[x][j]=min(mp[x][j],cz[i][j]+cz[i][x]);
					mp[j][x]=min(mp[x][j],cz[i][j]+cz[i][x]);
					book[x][j]=true;
					book[j][x]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(book[i][j]==true){
				t[i].push_back({j,mp[i][j]});
			}
		}
	}
	q.push({1,0});
	vis[1]=true;
	int cnt=0;
	int ans=0;
	while(!q.empty()){
		if(cnt==n){
			break;
		}
		Node h=q.top();
		q.pop();
		++cnt;
		ans+=h.dis;
		for(int i=0;i<(int)t[h.id].size();++i){
			if(!vis[t[h.id][i].num]){
				q.push({t[h.id][i].num,t[h.id][i].dis});
				vis[t[h.id][i].num]=true;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
