#include <bits/stdc++.h>
using namespace std;
struct cl{
	int id,w,c; 
} d[100005];

int num[5];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while (T--)
	{
		priority_queue<int> q[4];
		num[1]=num[2]=num[3]=0;
//		cout<<num[1]<<'#'<<endl;
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			long long a1,a2,a3;
			cin>>a1>>a2>>a3;
			if (a1>=a2)
			{
				if (a1>=a3)
				{
					d[i].w=a1;
					d[i].id=1;
					if (a2>=a3)
						d[i].c=a2-a1;
					else
						d[i].c=a3-a1;
				}
				else
				{
					d[i].w=a3;
					d[i].id=3;
					d[i].c=a1-a3;
				}
			}
			else
			{
				if (a2>=a3)
				{
					d[i].w=a2;
					d[i].id=2;
					if (a1>=a3)
						d[i].c=a1-a2;
					else
						d[i].c=a3-a2;
				}
				else
				{
					d[i].w=a3;
					d[i].id=3;
					d[i].c=a2-a3;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
//			cout<<d[i].id<<' '<<d[i].w<<' '<<d[i].c<<'#'<<endl;
			if (num[d[i].id]<n/2)
			{
				ans+=d[i].w;
				num[d[i].id]++;
				q[d[i].id].push(d[i].c);
			}
			else
			{
				ans+=d[i].w;
				if (d[i].c>=q[d[i].id].top())
				{
					ans+=d[i].c;
				}
				else
				{
					ans+=q[d[i].id].top();
					q[d[i].id].pop();
					q[d[i].id].push(d[i].c);
				}
			}
		}
		cout<<ans<<endl;	
	}
	
	return 0;
}
