#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		priority_queue<int,vector<int>,greater<int> > q[4];
		cin>>n;
		int mx;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]);
			mx=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=mx;
			if(mx==a[i][1])
			{
				q[1].push(mx-max(a[i][2],a[i][3]));
			}
			else if(mx==a[i][2])
			{
				q[2].push(mx-max(a[i][1],a[i][3]));
			}
			else
			{
				q[3].push(mx-max(a[i][1],a[i][2]));
			}
		}
		while(q[1].size()>n/2)
		{
			ans-=q[1].top();
			q[1].pop();
		}
		while(q[2].size()>n/2)
		{
			ans-=q[2].top();
			q[2].pop();
		}
		while(q[3].size()>n/2)
		{
			ans-=q[3].top();
			q[3].pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
