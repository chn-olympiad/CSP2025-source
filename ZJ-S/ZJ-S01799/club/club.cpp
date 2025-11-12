#include<bits/stdc++.h>
using namespace std;
int n,a[100005][10],ans;
bool b[100005];
struct node
{
	int sum,id;
	bool operator <(const node x)const
	{
		return this->sum<x.sum;
	}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		priority_queue<node> q,p;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			swap(a[i][1],a[i][3]);
			int x=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			node z;z.sum=-x,z.id=i;
			if(q.size()<n/2)
			{
				q.push(z);
				b[i]=1;
			}
			else
			{
				node t=q.top();
				if(-t.sum<x || -t.sum==x && a[t.id][2]-a[t.id][3]>a[i][2]-a[i][3])
				{
					q.pop();
					b[t.id]=0;b[i]=1;
					q.push(z);
				}
			}
		}
		while(q.size() && q.top().sum>0)
		{
			b[q.top().id]=0;
			q.pop();
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i])
			{
				ans+=a[i][1];
				b[i]=0;
			}
			else
			{
				node z;z.sum=a[i][3]-a[i][2],z.id=i;
				if(p.size()<n/2)
					p.push(z);
				else
				{
					node t=p.top();
					if(-t.sum<a[i][2]-a[i][3])
					{
						ans+=a[t.id][3];
						p.pop();
						p.push(z);
					}
					else
						ans+=a[i][3];
				}
			}
		}
		while(p.size() && p.top().sum>0 && p.size()+q.size()>n/2)
		{
			ans+=a[p.top().id][3];
			p.pop();
		}
		while(p.size())
		{
			ans+=a[p.top().id][2];
			p.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
