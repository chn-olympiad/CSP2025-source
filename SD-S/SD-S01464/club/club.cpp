#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node
{
	int dat,op,id,ori;
	bool operator<(const node &x) const
	{
		return dat<x.dat;
	}
};
priority_queue<node> q;
bool vis[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			q.push({a-max(b,c),1,i,a});
			q.push({b-max(a,c),2,i,b});
			q.push({c-max(a,b),3,i,c});
		}
		int cnt[4]={0,0,0,0};
		int ans=0;
		while(q.size())
		{
			node u=q.top();
			q.pop();
			if(vis[u.id])
			{
				continue;
			}
			if(cnt[u.op]>=(n>>1))
			{
				continue;
			}
			vis[u.id]=1;
			cnt[u.op]++;
			ans+=u.ori;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

