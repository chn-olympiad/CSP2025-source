#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
priority_queue<pair<int,int> > q[4];
int n,m,s;
int ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int i,j,k,a,b,c;
		ans=0;
		s=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			k=max(c,max(a,b));
			if (k==a) q[1].push(make_pair(max(b,c)-a,a));
			else if (k==b) q[2].push(make_pair(max(a,c)-b,b));
				else q[3].push(make_pair(max(a,b)-c,c));
		}
		int maxn=max(q[1].size(),max(q[2].size(),q[3].size()));
		if (maxn>n/2)
		{
			if (maxn==q[1].size()) k=1;
			if (maxn==q[2].size()) k=2;
			if (maxn==q[3].size()) k=3;
			while (q[k].size()>n/2)
			{
				int d=q[k].top().first,p=q[k].top().second;
				q[k].pop();
				s+=(p+d);
			}
		}
		for (i=1;i<=3;i++)
		{
			while (q[i].size())
			{
				ans+=q[i].top().second;
				q[i].pop();
			}
		}
		printf("%d\n",ans+s);
	}
	return 0;
} 
