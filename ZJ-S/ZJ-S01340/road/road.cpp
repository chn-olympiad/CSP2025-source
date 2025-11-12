#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=10050;
int n,m,k,u,v,w,c[11],a[11][MAXN];
struct node{
	int to,w;
};
struct cmp{
	bool operator ()(const node &l,const node &r){
		return l.w>r.w;
	}
};
node make_node(int to,int w){
	node tmp;
	tmp.to=to;
	tmp.w=w;
	return tmp;
}
vector<node>e[MAXN];
bool allzero=true;
priority_queue<node,vector<node>,cmp>q;
bool vis[MAXN];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back(make_node(v,w));
		e[v].push_back(make_node(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c)allzero=false;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k||allzero){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				//cerr<<m+i<<endl;
				e[j].push_back(make_node(n+i,a[i][j]));
				e[n+i].push_back(make_node(j,a[i][j]));	
			}
		vis[1]=true;
		for(int i=0;i<e[1].size();i++)
			q.push(e[1][i]);
		int sizeq=e[1].size();
		int ans=0;
		while(sizeq){
			auto t=q.top();
			q.pop();
			int to=t.to;
			sizeq--;
			if(vis[to])
				continue;
			vis[to]=true;
			ans+=t.w;
			for(int i=0;i<e[to].size();i++)
				if(!vis[e[to][i].to]){
					q.push(e[to][i]);
					sizeq++;
				}
		}
		cout<<ans;
	}
	return 0;
} 
/*
5 6 0
1 5 3
2 1 5
1 4 4
2 4 2
3 4 1
2 3 7
*/
