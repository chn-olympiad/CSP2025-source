#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x,y,z,id;
};


const int N=2e5+5;
int d[N];
int t;
int n;
node a[N],b[N];
bool cmp(node x,node y)
{
	if(x.x==y.x)
	{
		if(x.y==y.y)	return x.z>y.z;
		return x.y>y.y;
	}
	return x.x>y.x;
}
bool cmp1(int x,int y)
{
	return b[x].x-b[x].y>b[y].x-b[y].y;
}
bool cmp2(int x,int y)
{
	return b[x].y-b[x].z>b[y].y-b[y].z;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		int tx=a[i].x,ty=a[i].y,tz=a[i].z;
		b[i].id=i;
		b[i].x=max(max(tx,ty),tz);
		b[i].z=min(min(tx,ty),tz);
		b[i].y=a[i].x+a[i].y+a[i].z-b[i].x-b[i].z;
	}
	sort(b+1,b+n+1,cmp);
	queue<int> q1,q2,q3;
	for(int i=1;i<=n;i++)
	{
		int j=b[i].id;
		if(a[j].x==b[i].x)	q1.push(i);
		else if(a[j].y==b[i].x)	q2.push(i);
		else if(a[j].z==b[i].x)	q3.push(i);
		
	}
	int lst=0,ans=0;
	if(q1.size()>n/2)
	{
		while(!q1.empty())
		{
			d[++lst]=q1.front();
			q1.pop();
		}
		
		sort(d+1,d+lst+1,cmp1);
		for(int i=1;i<=n/2;i++)	q1.push(d[i]);
		for(int i=n/2+1;i<=lst;i++)
		{
			int j=b[d[i]].id;
			if(a[j].y==b[d[i]].y)	q2.push(d[i]);
			else if(a[j].z==b[d[i]].y)	q3.push(d[i]);
		}
		lst=0;
		if(q2.size()>n/2)
		{
			while(!q2.empty())
			{
				d[++lst]=q2.front();
				q2.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q2.push(d[i]);
			for(int i=n/2+1;i<=lst;i++)
			{
				int j=b[d[i]].id;
				q3.push(d[i]);
			}
		}
		if(q3.size()>n/2)
		{
			while(!q3.empty())
			{
				d[++lst]=q3.front();
				q3.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q3.push(d[i]);

			for(int i=n/2+1;i<=lst;i++)
			{
				q2.push(d[i]);
			}
		}
	}
	if(q2.size()>n/2)
	{
		while(!q2.empty())
		{
			d[++lst]=q2.front();
			q2.pop();
		}
		sort(d+1,d+lst+1,cmp1);
		for(int i=1;i<=n/2;i++)	q2.push(d[i]);
		for(int i=n/2+1;i<=lst;i++)
		{
			int j=b[d[i]].id;
			if(a[j].x==b[d[i]].y)	q1.push(d[i]);
			else if(a[j].z==b[d[i]].y)	q3.push(d[i]);
		}
		lst=0;
		if(q1.size()>n/2)
		{
			while(!q1.empty())
			{
				d[++lst]=q1.front();
				q1.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q1.push(d[i]);
			for(int i=n/2+1;i<=lst;i++)
			{
				int j=b[d[i]].id;
				q3.push(d[i]);
			}
		}
		if(q3.size()>n/2)
		{
			while(!q3.empty())
			{
				d[++lst]=q3.front();
				q3.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q3.push(d[i]);
			for(int i=n/2+1;i<=lst;i++)
			{
				int j=b[d[i]].id;
				q1.push(d[i]);
			}
		}
	}if(q3.size()>n/2)
	{
		while(!q3.empty())
		{
			d[++lst]=q3.front();
			q3.pop();
		}
		sort(d+1,d+lst+1,cmp1);
		for(int i=1;i<=n/2;i++)	q3.push(d[i]);
		for(int i=n/2+1;i<=lst;i++)
		{
			int j=b[d[i]].id;
			if(a[j].y==b[d[i]].y)	q2.push(d[i]);
			else if(a[j].x==b[d[i]].y)	q1.push(d[i]);
		}
		lst=0;
		if(q2.size()>n/2)
		{
			while(!q2.empty())
			{
				d[++lst]=q2.front();
				q2.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q2.push(d[i]);
			for(int i=n/2+1;i<=lst;i++)
			{
				int j=b[d[i]].id;
				q1.push(d[i]);
			}
		}
		if(q1.size()>n/2)
		{
			while(!q1.empty())
			{
				d[++lst]=q1.front();
				q1.pop();
			}
			sort(d+1,d+lst+1,cmp2);
			for(int i=1;i<=n/2;i++)	q1.push(d[i]);
			for(int i=n/2+1;i<=lst;i++)
			{
				int j=b[d[i]].id;
				q2.push(d[i]);
			}
		}
	}
	while(!q1.empty())
	{
		ans+=a[b[q1.front()].id].x;
		q1.pop();
	}
	while(!q2.empty())
	{
		ans+=a[b[q2.front()].id].y;
		q2.pop();
	}
	while(!q3.empty())
	{
		ans+=a[b[q3.front()].id].z;
		q3.pop();
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
