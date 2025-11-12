#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,k,zjl;
bool AAA;
vector<int>aa;
vector<int>sub;
vector<int>c;
vector<vector<pair<int,int>>>ed;
vector<int>siz;
vector<int>nos;
vector<vector<int>>edc;
int prim(){
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pr;
    vector<bool>vis(n+1);
    bool zjl=false;
    for(int i=1;i<=k;i++){
    	if(sub[i]==1){
    		zjl=true;
    		for(int j=1;j<=n;j++){
    			if(nos[j]>edc[i][j]){
    				pr.push({edc[i][j],j});
				}
			}
		}
	}
	if(!zjl)pr.push({0,1});
    while(!pr.empty()){
        auto now=pr.top();
        pr.pop();
        if(vis[now.second])continue;
        vis[now.second]=1;
        ans+=now.first;
		if(now.second<=n){
			for(int i=0;i<siz[now.second];i++){
    			if(!vis[ed[now.second][i].second]&&nos[ed[now.second][i].second]>ed[now.second][i].first){
    				pr.push(ed[now.second][i]);
				}
			}
		}
    }
    return ans;
}
int dfs(int i){
    if(i>k){
    	int res=prim();
    	return res;
	}
        sub[i]=1;
        int res=dfs(i+1);
        res+=c[i];
        sub[i]=0;
        res=min(res,dfs(i+1));
        return res;
}
signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    sub.resize(k+1);
    ed.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ed[u].push_back({w,v});
        ed[v].push_back({w,u});
    }
    siz.resize(n+1);
    for(int i=1;i<=n;i++){
    	siz[i]=(int)(ed[i].size());
	}
    c.resize(k+1);
    edc.resize(k+1,vector<int>(n+1));
    aa.resize(n+1);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>edc[i][j];
        }
    }
    nos.resize(n+1,INT_MAX);
    cout<<dfs(1)<<endl;
}