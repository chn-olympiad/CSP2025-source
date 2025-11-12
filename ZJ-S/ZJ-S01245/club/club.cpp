#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=100010;
ll t,n,sx,sy,sz,sum,maxa,maxb;
priority_queue<ll>q;
struct node
{
	ll x,y,z;
}a[maxn];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		while(!q.empty())
		{
			q.pop();
		}
		sum=0;
		sx=0;
		sy=0;
		sz=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				sx++;
				sum+=a[i].x;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				sy++;
				sum+=a[i].y;
			}
			else
			{
				sz++;
				sum+=a[i].z;
			}
		}
		if(sx<=n/2&&sy<=n/2&&sz<=n/2)
		{
			cout<<sum<<endl;
			continue;
		}
		if(sx>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				maxa=max(a[i].x,max(a[i].y,a[i].z));
				if(maxa==a[i].x)
				{
					maxb=max(a[i].y,a[i].z);
				}
			}
			for(int i=1;i<=sx-n/2;i++)
			{
				sum-=q.top();
				q.pop();
			}
		}
		else if(sy>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				maxa=max(a[i].x,max(a[i].y,a[i].z));
				if(maxa==a[i].y)
				{
					maxb=max(a[i].x,a[i].z);
				}
			}
			for(int i=1;i<=sy-n/2;i++)
			{
				sum-=q.top();
				q.pop();
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				maxa=max(a[i].x,max(a[i].y,a[i].z));
				if(maxa==a[i].z)
				{
					maxb=max(a[i].x,a[i].y);
					q.push(maxa-maxb);
				}
			}
			for(int i=1;i<=sz-n/2;i++)
			{
				sum-=q.top();
				q.pop();
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
