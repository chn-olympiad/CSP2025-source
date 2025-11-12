#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
pair<int,int>a[N][5];
int c[N][5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&c[i][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				a[i][j]={c[i][j],j};
			for(int k=1;k<=3;k++)
				for(int j=1;j<3;j++)
					if(a[i][j].first<a[i][j+1].first)
						swap(a[i][j],a[i][j+1]);
		}
		priority_queue<pair<int,int> >q[4];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int t=a[i][1].second;
			q[t].push({-(a[i][1].first-a[i][2].first),i});
			if((int)q[t].size()>n/2)
			{
				int b=q[t].top().second;q[t].pop();
				q[a[b][2].second].push({-(a[b][2].first-a[b][3].first),b});
			}
		}
		
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())
			{
				int u=q[i].top().second;q[i].pop();
				ans+=c[u][i];
			}		
		}
		printf("%lld\n",ans);

	}
	
	return 0;
}