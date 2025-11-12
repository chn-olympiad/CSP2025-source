#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int x,y,z;
}a[100010];
int op[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ax=0,b=0,c=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			int mx=max({a[i].x,a[i].y,a[i].z});
			ans+=mx;
			if(a[i].x == mx)
			{
				ax++;
				op[i]=1;
			}
			else if(a[i].y == mx)
			{
				op[i]=2;
				b++;
			}
			else
			{
				op[i]=3;
				c++;
			}
		}
		if(ax>n/2)
		{
			priority_queue<int,vector<int>,greater<int>> q;
			for(int i=1;i<=n;i++)
			{
				if(op[i] == 1)
				{
					q.push(a[i].x-max(a[i].y,a[i].z));
				}
			}
			while(int(q.size())>n/2)
			{
				ans-=q.top();
				q.pop();
			}
		}
		else if(b>n/2)
		{
			priority_queue<int,vector<int>,greater<int>> q;
			for(int i=1;i<=n;i++)
			{
				if(op[i] == 2)
				{
					q.push(a[i].y-max(a[i].x,a[i].z));
				}
			}
			while(int(q.size())>n/2)
			{
				ans-=q.top();
				q.pop();
			}
		}
		else
		{
			priority_queue<int,vector<int>,greater<int>> q;
			for(int i=1;i<=n;i++)
			{
				if(op[i] == 3)
				{
					q.push(a[i].z-max(a[i].y,a[i].x));
				}
			}
			while(int(q.size())>n/2)
			{
				ans-=q.top();
				q.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}