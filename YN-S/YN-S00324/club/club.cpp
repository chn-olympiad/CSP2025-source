#include <iostream>
#include <queue>
using namespace std;
const int N=1e5+5,T=1e9;

struct doll
{
	int c1,c2,c3;
}a[N];

struct node
{
	int id,d,num,time;
};

struct jud
{
	operator()(node x,node y)
	{
		return x.d>y.d;
	}
};

int read()
{
	int num=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9')
	{
		if(a=='-') f=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		num=num*10+a-'0';
		a=getchar();
	}
	return num*f;
}

int n,ans;
int t;
priority_queue<node,vector<node>,jud> q1,q2,q3;
void check(priority_queue<node,vector<node>,jud> &q)
{
	if(q.size()<=n/2) return;
	int cnt=q.top().id;
	int x=max(a[cnt].c1,max(a[cnt].c2,a[cnt].c3));
	int y;
	if(x==a[cnt].c1)
	{
		y=max(a[cnt].c2,a[cnt].c3);
		if(y==a[cnt].c2)
		{
			int d2=y-a[cnt].c3;
			if(q.top().time==1)
				q3.push({cnt,T,a[cnt].c3,0});
			else q2.push({cnt,d2,a[cnt].c2,1});
		}
		else
		{
			int d2=y-a[cnt].c2;
			if(q.top().time==1)
				q2.push({cnt,T,a[cnt].c2,0});
			else q3.push({cnt,d2,a[cnt].c3,1});
		}
	}
	else if(x==a[cnt].c2)
	{
		y=max(a[cnt].c1,a[cnt].c3);
		if(y==a[cnt].c1)
		{
			int d2=y-a[cnt].c3;
			if(q.top().time==1)
				q3.push({cnt,T,a[cnt].c3,0});
			else q1.push({cnt,d2,a[cnt].c1,1});
		}
		else
		{
			int d2=y-a[cnt].c1;
			if(q.top().time==1)
				q1.push({cnt,T,a[cnt].c1,0});
			else q3.push({cnt,d2,a[cnt].c3,1});
		}
	}
	else
	{
		y=max(a[cnt].c2,a[cnt].c1);
		if(y==a[cnt].c2)
		{
			int d2=y-a[cnt].c1;
			if(q.top().time==1)
				q1.push({cnt,T,a[cnt].c1,0});
			else q2.push({cnt,d2,a[cnt].c2,1});
		}
		else
		{
			int d2=y-a[cnt].c2;
			if(q.top().time==1)
				q2.push({cnt,T,a[cnt].c2,0});
			else q1.push({cnt,d2,a[cnt].c1,1});
		}
	}
	q.pop();
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i].c1=read();
			a[i].c2=read();
			a[i].c3=read();
			int x=max(a[i].c1,max(a[i].c2,a[i].c3));
			if(x==a[i].c1)
			{
				int y=max(a[i].c2,a[i].c3);
				if(y==a[i].c2) q1.push({i,a[i].c1-a[i].c2,x,2});
				else q1.push({i,a[i].c1-a[i].c3,x,2});
				check(q1);
			}
			else if(x==a[i].c2)
			{
				int y=max(a[i].c1,a[i].c3);
				if(y==a[i].c1) q2.push({i,a[i].c2-a[i].c1,x,2});
				else q2.push({i,a[i].c2-a[i].c3,x,2});
				check(q2);
			}
			else
			{
				int y=max(a[i].c1,a[i].c2);
				if(y==a[i].c1) q3.push({i,a[i].c3-a[i].c1,x,2});
				else q3.push({i,a[i].c3-a[i].c2,x,2});
				check(q3);
			}
		}
		while(!q1.empty())
		{
			ans+=q1.top().num;
			q1.pop();
		}
		while(!q2.empty())
		{
			ans+=q2.top().num;
			q2.pop();
		}
		while(!q3.empty())
		{
			ans+=q3.top().num;
			q3.pop();
		}
		cout<<ans<<endl;
		priority_queue<node,vector<node>,jud> k,m,s;
		q1.swap(k);
		q2.swap(m);
		q3.swap(s);
	}
	return 0;
}
