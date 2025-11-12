#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int u[N],v[N],w[N];
int c[15],a[10][N];
int ml[N];
struct cmp{
	bool operator ()(const int x,const int y)
	{
		return w[x]<w[y];
	}
};
priority_queue<int,vector<int>,cmp>q;
priority_queue<int,vector<int>,cmp>q2[N];
int q3[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		q2[u[i]].push(i);
		q2[v[i]].push(i);
		q.push(i);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	long long ans=0,cnt=0,head=1,tail;
	ml[u[q.top()]]=ml[v[q.top()]]=1;
	cnt=2;
	ans+=w[q.top()];
	q3[1]=u[q.top()];
	q3[2]=v[q.top()];
	tail=2;
	q.pop();
	while(!q.empty()) q.pop();
	while(cnt<n)
	{
		int now=q3[head];
		head++;
		while(!q2[now].empty())
		{
			if(ml[q2[now].top()]==0) 
			{
				q.push(q2[now].top());
			}
			q2[now].pop();
		}
		ml[v[q.top()]]=1;
		cnt++;
		ans+=w[q.top()];
		tail++;
		q3[tail]=v[q.top()];
	//	cout<<q3[tail]<<" ";
	}
	cout<<ans<<'\n';
	return 0;
}
