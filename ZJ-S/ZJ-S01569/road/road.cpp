#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cost[20],goo[10][11451],fa[20],mp1[11451][11451],cnt;
vector<pair<int,int>> mp[11451];
bool vis[11451],used[10];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n+k;i++) {
		mp[i].reserve(114514);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp1[i][j]=LLONG_MAX;
	for(int i=1;i<=m;i++) {//build
		cin>>u>>v>>w;
		mp1[u][v]=min(w,mp1[u][v]);
		mp1[v][u]=min(w,mp1[v][u]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp1[i][j]!=LLONG_MAX)
				mp[i].push_back(make_pair(mp1[i][j],j));
	for(int i=1;i<=k;i++) {//let village as last 10 point,total n+k points
		cin>>cost[i];
		for(int j=1;j<=n;j++) {
			cin>>goo[i][j];
			mp[j].push_back(make_pair(goo[i][j]+cost[i],n+i));
			mp[n+i].push_back(make_pair(goo[i][j]+cost[i],j));
		}
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> > > pq;
	int p,sz,ans=0,fat;
	pair<int,pair<int,int> >top1;
	for(auto i:mp[1])
		pq.push(make_pair(i.first,make_pair(i.second,1)));
	vis[1]=1;
	
	while(!pq.empty()) {
		if(vis[p=pq.top().second.first]) {
			pq.pop();
			continue;
		}
		if(cnt++==n+k)
			break;
		top1=pq.top();
		pq.pop();
		ans+=top1.first;
		fat=top1.second.second;
		vis[p]=1;
		if(fat>n)//if comes from village
			used[fat-n]=1;
		
		if(p<=n) {
			for(auto i:mp[p])
				if(vis[i.second]==0)
					pq.push(make_pair(i.first,make_pair(i.second,p)));
			}
		else {
			fa[p-n]=fat;
			for(auto i:mp[p])
				if(vis[i.second]==0)
					pq.push(make_pair(i.first-cost[p-n],make_pair(i.second,p)));
		}
	}
	for(int i=1;i<=k;i++)
		if(used[i]==0)
			ans-=cost[i]+goo[i][fa[i]];
	cout<<ans;
	return 0;
}
//mintree
//CCF help me ac this tks.I spend too much money.
//**** ***?!Why MLE?
//f**k 1.009s