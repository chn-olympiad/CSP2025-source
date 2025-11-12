#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
struct node
{
	long long ind,toi,val;
	bool operator > (const node &x) const
	{
		return val > x.val;
	} 
};
bool vis[15000];
bool vis1[15000];
long long vis2[15000];
long long wei[15];
long long n,m,k,from,to,tow,ans;
vector<long long> edge[15000];
vector<long long> edgew[15000];
priority_queue<node,vector<node>,greater<node> > q;
long long prim(long long nowstate)
{
	long long nans = 0;
	node newnode;
	for(long long i = 0;i < k;i++)
		if(((1<<i)&nowstate))
			nans+=wei[i+1];
	while(!q.empty())
		q.pop();
	for(long i = 0;i <= n+k;i++)
		vis[i] = false;
	for(long long i = 0;i < edge[1].size();i++)
	{
		if(edge[1][i] > n&&(!((1<<(edge[1][i]-n-1))&nowstate)))
			continue;
		newnode.ind = 1;
		newnode.toi = i;
		newnode.val = edgew[1][i];
		q.push(newnode);
	}
	long long nowans = 1;
	vis[1] = true;
	while(!q.empty())
	{
		node topn = q.top();
		q.pop();
		long long now = edge[topn.ind][topn.toi];
		if(vis[now])
			continue;
		//cout<<topn.ind<<" "<<now<<endl;
		vis[now] = true;
		nans+=topn.val;
		if(now <= n)
			nowans++;
		if(nowans == n)
			return nans;
		for(long long i = 0;i < edge[now].size();i++)
		{
			if(edge[now][i] > n&&(!((1<<(edge[now][i]-n-1))&nowstate)))
				continue;
			if(vis[edge[now][i]])
				continue;
			newnode.ind = now;
			newnode.toi = i;
			newnode.val = edgew[now][i];
			//cout<<newnode.ind<<"   "<<edge[now][i]<<endl;
			q.push(newnode);
		}
	}
	return 1e18+7;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i = 1;i <= m;i++)
	{
		cin>>from>>to>>tow;
		edge[from].push_back(to);
		edgew[from].push_back(tow);
		edge[to].push_back(from);
		edgew[to].push_back(tow);
	}
	for(long long i = 1;i <= k;i++)
	{
		cin>>wei[i];
		for(long long j = 1;j <= n;j++)
		{
			cin>>tow;
			edge[n+i].push_back(j);
			edgew[n+i].push_back(tow);
			edge[j].push_back(n+i);
			edgew[j].push_back(tow);
		}
	}
	if(n == 1)
	{
		cout<<0<<endl;
		return 0;
	}/*
	for(long long i = 1;i <= n+k;i++){
		for(long j = 0;j < edge[i].size();j++)
			cout<<edgew[i][j]<<" ";
		cout<<endl;
	}*/
	ans = 1e18+7;
	for(long long i = 0;i < (1<<k);i++)
	{
		ans = min(ans,prim(i));
		//cout<<i<<" "<<prim(i)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//long long long long
