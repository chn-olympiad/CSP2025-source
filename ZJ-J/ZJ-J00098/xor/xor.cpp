#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],sum[500010];
int dp[500010];
vector<int>ve[3010];
int now[3010];
struct node
{
	int l,r;
	node(){}
	node(int L,int R)
	{
		l=L;
		r=R;
	}
};
bool operator<(node a,node b)
{
	return a.r>b.r;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		ve[sum[i]].push_back(i);
	}
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
	{
		int w=k^sum[i-1];
		for(;now[w]<(int)ve[w].size();now[w]++)
		{
			if(ve[w][now[w]]>=i)
			{
				q.push(node(i,ve[w][now[w]]));
				break;
			}
		}
	}
	int nw=0,ans=0;
	while(!q.empty())
	{
		node t=q.top();q.pop();
		if(t.l>nw)
		{
			nw=t.r;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}