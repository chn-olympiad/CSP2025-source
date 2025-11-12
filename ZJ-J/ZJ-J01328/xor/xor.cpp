#include<bits/stdc++.h>
using namespace std;
string x;
long long n,i,l,h,k,m,p,t,Max,a[505050],j,s;
struct XX
{
	long long zuo,you;
}jiao[500050];
bool cmp(XX x,XX y)
{
	return x.you<y.you;
}
int xor1(long long x,long long y)
{
	int i=0,l=0,b[505],c[505],p,s=0;
	if(x==0)
	{
		i=1;
		c[1]=0;
	}
	if(y==0)
	{
		l=1;
		b[1]=0;
	}
	while(x>0)
	{
		i++;
		c[i]=x%2;
		x=x/2;
	}
	while(y>0)
	{
		l++;
		b[l]=y%2;
		y=y/2;
	}
	p=min(i,l);
	for(t=1;t<=p;t++)
	{
		if(b[t]!=c[t])
		{
			s=s+pow(2,t-1);
		}
	}
	if(i>p)
	{
		for(t=p+1;t<=i;t++)
		{
			s=s+pow(2,t-1)*c[t];
		}
	}
	else if(l>p)
	{
		for(t=p+1;t<=l;t++)
		{
			s=s+pow(2,t-1)*b[t];
		}
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(l=i;l<=n;l++)
		{
			t=0;
			for(p=i;p<=l;p++)
			{
				t=xor1(t,a[p]);
			}
			if(t==k)
			{
				h++;
				jiao[h].zuo=i;
				jiao[h].you=l;
			}
		}
	}
	sort(jiao+1,jiao+h+1,cmp);
	for(i=1;i<=h;i++)
	{
		j=jiao[i].you;
		s=1;
		for(l=i+1;l<=h;l++)
		{
			if(jiao[l].zuo>j)
			{
				s++;
				j=jiao[l].you;
			}
		}
		Max=max(Max,s);
	}
	cout<<Max;
	return 0;
}