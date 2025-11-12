#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,ans=0,t,z=0,x=0,p=0;
struct l
{
	long long a,b,c,f;	
};
l m[100005];
l q[100005];
l w[100005];
l e[100005];
bool cmp(l x,l y)
{
	return x.f>y.f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			q[i].a=0;
			q[i].b=0;
			q[i].c=0;
			q[i].f=0;
			w[i].a=0;
			w[i].b=0;
			w[i].c=0;
			w[i].f=0;
			e[i].a=0;
			e[i].b=0;
			e[i].c=0;
			e[i].f=0;
		}
		ans=0;
		z=0;
		x=0;
		p=0;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>m[i].b && m[i].a>m[i].c)
			{
				z++;
				q[z].a=m[i].a;
				q[z].b=m[i].b;
				q[z].c=m[i].c;
				q[z].f=min(m[i].a-m[i].b,m[i].a-m[i].c);
			}
			else if(m[i].b>m[i].a && m[i].b>m[i].c)
			{
				x++;
				w[x].a=m[i].a;
				w[x].b=m[i].b;
				w[x].c=m[i].c;
				w[x].f=min(m[i].b-m[i].a,m[i].b-m[i].c);
			}
			else
			{
				p++;
				e[p].a=m[i].a;
				e[p].b=m[i].b;
				e[p].c=m[i].c;
				e[p].f=min(m[i].c-m[i].a,m[i].c-m[i].b);
			}
		}
		if(z>n/2)
		{
			sort(q+1,q+n+1,cmp);
			for(int i=n/2+1;i<=n;i++)
			{
				if(((q[i].a-q[i].b)<(q[i].a-q[i].c))&& x<n/2)
				{
					x++;
					w[x].a=q[i].a;
					w[x].b=q[i].b;
					w[x].c=q[i].c;
					w[x].f=q[i].f;
				}
				else
				{
					p++;
					e[p].a=q[i].a;
					e[p].b=q[i].b;
					e[p].c=q[i].c;
					e[p].f=q[i].f;
				}
				q[i].a=0;
				q[i].b=0;
				q[i].c=0;
				q[i].f=0;
			}
			z=n/2;
		}
		//
		if(x>n/2)
		{
			sort(w+1,w+n+1,cmp);
			for(int i=n/2+1;i<=n;i++)
			{
				if((w[i].b-w[i].a>w[i].b-w[i].c)&& p<n/2)
				{
					p++;
					e[p].a=w[i].a;
					e[p].b=w[i].b;
					e[p].c=w[i].c;
					e[p].f=w[i].f;
				}
				else
				{
					z++;
					q[z].a=w[i].a;
					q[z].b=w[i].b;
					q[z].c=w[i].c;
					q[z].f=w[i].f;
				}
				w[i].a=0;
				w[i].b=0;
				w[i].c=0;
				w[i].f=0;
			}
			x=n/2;
		}
		//
		if(p>n/2)
		{ 
			sort(e+1,e+n+1,cmp);
			for(int i=n/2+1;i<=n;i++)
			{
				if((e[i].c-e[i].a>e[i].c-e[i].b )&& x<n/2)
				{
					x++;
					w[x].a=e[i].a;
					w[x].b=e[i].b;
					w[x].c=e[i].c;
				}
				else  
				{
					z++;
					q[z].a=e[i].a;
					q[z].b=e[i].b;
					q[z].c=e[i].c;
				}
				e[i].a=0;
				e[i].b=0;
				e[i].c=0;
				e[i].f=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=q[i].a;
			ans+=w[i].b;
			ans+=e[i].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}

