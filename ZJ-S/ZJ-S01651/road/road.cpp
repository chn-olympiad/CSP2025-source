#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int f[10025],nrd[15][10005],n,m,k;
struct edge{
	int u,v,w;
	void read(){
		cin >> u >> v >> w;
	}
	void clear(){
		u=v=w=0;
	}
}rdp[1000005],rd[1100005];
bool use[15];
void init(int sz){for(int i = 1; i <= sz; i++)f[i]=i;}
int found(int x){return f[x]==x?x:f[x]=found(f[x]);}
int cost[10015];
bool out[10015],in[10015];
struct edge2{
	int v,w;
};
struct node{
	int v,w,las;
	bool operator <(node b)const
	{return w==b.w?las>b.las:w>b.w;}
};
vector<edge2> ve[10015];
long long dfs(int step){
	if(step>k){
		int cnt=n,pos=m;
		for(int i = 1; i <= m; i++)rd[i]=rdp[i];
		long long ans=0;
		for(int i = 1; i <= k; i++)
			if(use[i]){
				cnt++;
				ans+=nrd[i][0];
				for(int j = 1; j <= n; j++)
					rd[++pos]={cnt,j,nrd[i][j]};
			}
		init(cnt);
		sort(rd+1,rd+pos+1,[](edge a,edge b){return a.w<b.w;});
		for(int i = 1; i <= pos; i++){
			int fu=found(rd[i].u),fv=found(rd[i].v);
			if(fu==fv)continue;
			ans+=rd[i].w;
			f[fv]=fu;
//			cout << rd[i].u << ' ' << rd[i].v << endl;
		}
//		cout << ans << endl;
		for(int i = m+1; i <= pos; i++)rd[i].clear();
		return ans;
	}
	long long ans=4e18;
	use[step]=0;
	ans=min(ans,dfs(step+1));
	use[step]=1;
	ans=min(ans,dfs(step+1));
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(m<=100000&&k<=5){
		for(int i = 1; i <= m; i++)rdp[i].read();
		for(int i = 1; i <= k; i++)
			for(int j = 0; j <= n; j++)
				cin >> nrd[i][j];
		cout << dfs(1);
	}
	else{
		for(int i = 1; i <= m; i++){
			int u,v,w;
			cin >> u >> v >> w;
			ve[u].push_back({v,w});
			ve[v].push_back({u,w});
		}
		for(int i = 1; i <= k; i++){
			int a;
			cin >> a;
			for(int j = 1; j <= n; j++){
				int t;
				cin >> t;
				ve[i+n].push_back({j,t});
				ve[j].push_back({i+n,t+a});
			}
		}
		priority_queue<node> q;
		long long ans=0;
		q.push({1,0,0});
		while(!q.empty()){
			node t=q.top();
			q.pop();
			if(in[t.v])continue;
			out[t.las]=1;
			in[t.v]=1;
			cost[t.v]=t.w;
			ans+=t.w;
			for(auto it:ve[t.v])
				q.push({it.v,it.w,t.v});
		}
		for(int i = 1; i <= k; i++)
			if(!out[i+n]){
				ans-=cost[i+n];
			}
		cout << ans;
	}
	return 0;
}
