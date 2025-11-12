#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct wt
{
	int value,name,id;
	bool operator<(const wt &x)const
	{
		return value<x.value;
	}
	bool operator>(const wt &x)const
	{
		return value>x.value;
	}
	bool operator==(const wt &x)const
	{
		return value==x.value;
	}
};
int t,n;
long long ans;
int sum[5];
wt a[100005][5];
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(sum,0,sizeof(sum));
		ans=0;
		priority_queue< wt,vector<wt>,greater<wt> > q[5];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j].value;
				a[i][j].id=j;
				a[i][j].name=i;
			}
			sort(a[i]+1,a[i]+4);
		}
		for(int i=1;i<=n;i++)
		{
			if(sum[a[i][3].id]<n/2)
			{
				q[a[i][3].id].push(a[i][3]);
				sum[a[i][3].id]++;
			}
			else
			{
				wt ft=q[a[i][3].id].top();
				if(a[i][3].value+a[ft.name][2].value-a[ft.name][3].value>a[3][2].value)
				{
					q[ft.id].pop();
					q[ft.id].push(a[i][3]);
					q[a[ft.name][2].id].push(a[ft.name][2]);
					sum[a[ft.name][2].id]++;
				}
				else
				{
					q[a[i][2].id].push(a[i][2]);
					sum[a[i][2].id]++;
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())
			{
				ans+=q[i].top().value;
				q[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
