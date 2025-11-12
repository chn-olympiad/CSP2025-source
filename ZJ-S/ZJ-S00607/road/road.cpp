#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
const int N=1e4+15;
int vis[N];
int n,m,k;
struct node{
	int v,w,t;
};
vector<node>G[N];
bool f[100];
int c[15];
int a[15][N];
bool zf[N];
signed main(void){
     freopen("road.in","r",stdin);
     freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w,0});
        G[v].push_back({u,w,0});
    }
    for(int i=1;i<=k;i++){
    	cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            G[n+i].push_back({j,a[i][j]+c[i],i});
            G[j].push_back({n+i,a[i][j]+c[i],i});
        }
    }
	priority_queue<pair<int,pair<int,int>>>q;
    for(auto i:G[1]){
    	q.push({-i.w,{i.v,i.t}});
	}
	vis[1]=1;
	int cnt=1,ans=0;
	while(cnt<n){
		int dis=q.top().first,u=q.top().second.first,t=q.top().second.second;
		q.pop();
		if(t>0){
			if(f[t]==1)
				dis+=c[t];
//			}else{
				if(vis[u]==0){
					vis[u]=1;
					f[t]=1;
					if(u<=n)
					cnt++;
					ans-=dis;
		cout<<u<<" "<<dis<<endl;
				    for(auto i:G[u]){
    					q.push({-i.w,{i.v,i.t}});
					}
				}
//			}
		}else{
			if(vis[u]==0){
				vis[u]=1;
				if(u<=n)
				cnt++;
				ans-=dis;
		cout<<u<<" "<<dis<<endl;
			    for(auto i:G[u]){
    				q.push({-i.w,{i.v,i.t}});
				}
			}
		}
	}
    cout<<ans<<endl;
    return 0;
}