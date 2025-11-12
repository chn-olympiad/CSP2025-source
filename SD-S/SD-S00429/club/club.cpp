#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[1000009][4],ans,cnt1,cnt2,cnt3;
priority_queue<pair<int,pair<int,int> > >q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		while(!q.empty())
		{
			q.pop();
		}
		cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
			{
				ans+=a[i][2];
				q.push({a[i][1]-a[i][2],{1,2}});
			}
			else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
			{
				ans+=a[i][3];
				q.push({a[i][1]-a[i][3],{1,3}});
			}
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
			{
				ans+=a[i][1];
				q.push({a[i][2]-a[i][1],{2,1}});
			}
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
			{
				ans+=a[i][3];
				q.push({a[i][2]-a[i][3],{2,3}});
			}
			else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
			{
				ans+=a[i][1];
				q.push({a[i][3]-a[i][1],{3,1}});
			}
			else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
			{
				ans+=a[i][2];
				q.push({a[i][3]-a[i][2],{3,2}});
			}
		}
		for(int i=1;i<=n;i++)
		{
			pair<int,pair<int,int> > f=q.top();
			q.pop();
			if(f.second.first==1)
			{
				if(cnt1+1<=(n>>1))
				{
					ans+=f.first;
					cnt1++;
				}
				else
				{
					if(f.second.second==2)
					{
						cnt2++;
					}
					else
					{
						cnt3++;
					}
				}
			}
			if(f.second.first==2)
			{
				if(cnt2+1<=(n>>1))
				{
					ans+=f.first;
					cnt2++;
				}
				else
				{
					if(f.second.second==1)
					{
						cnt1++;
					}
					else
					{
						cnt3++;
					}
				}
			}
			if(f.second.first==3)
			{
				if(cnt3+1<=(n>>1))
				{
					ans+=f.first;
					cnt3++;
				}
				else
				{
					if(f.second.second==2)
					{
						cnt2++;
					}
					else
					{
						cnt1++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
