#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct node
{
	int u,v;
	long long w;
	inline bool operator <(const node &x)const
	{
		return w>x.w;
	}
};
priority_queue<node> que;
int fa[10005];
int f(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	else
	{
		return f(fa[x]);
	}
}
int cnt;
void find()
{
	while(!que.empty())
	{
		node q=que.top();
		que.pop();
		int w=f(q.u),e=f(q.v);
		if(w!=e)
		{
			fa[w]=fa[e];
			ans+=q.w;
		}
	}
}
int h[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		que.push(node{u,v,w});
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	if(k==0)
	{
		find();
		cout<<ans<<endl;
		return 0;
	}
	int c;
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>h[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j!=k)
				{
					que.push(node{j,k,c+h[j]+h[k]});
				}
			}
		}
	}
	find();
	cout<<ans<<endl;
	return 0;
}

