#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+9;
int T,n,id,mx,a[N][4],ans;
vector<int> sum[4];
priority_queue<int,vector<int> > pq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		for(int i=1;i<=3;i++)sum[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			id=1;
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][id])id=j;
			}
			sum[id].push_back(i);
			ans+=a[i][id];
		}
		for(int i=1;i<=3;i++)
		{
			if(sum[i].size()>n/2)
			{
				for(auto j:sum[i])
				{
					mx=0;
					for(int k=1;k<=3;k++)
					{
						if(k==i)continue;
						mx=max(mx,a[j][k]);
					}
					pq.push(a[j][i]-mx);
					if(pq.size()>sum[i].size()-n/2)pq.pop();
				}
				while(!pq.empty())
				{
					ans-=pq.top();
					pq.pop();
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/
