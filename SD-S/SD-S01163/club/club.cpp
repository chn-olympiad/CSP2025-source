#include <bits/stdc++.h>
using namespace std;
long long n;
struct nn
{
	long long a,b,c;
}t[100005];
long long f[505][505],ff[505][505];
bool lkj(nn x,nn y)
{
	return (x.a-x.b)>(y.a-y.b);
}
bool asd(nn x,nn y)
{
	return (x.c-x.a)>(y.c-y.a);
}
bool asdd(nn x,nn y)
{
	return (x.c-x.b)>(y.c-y.b);
}
vector<nn> c,v;
long long ca[100005],va[100005],cb[100005],vb[100005];
long long gong(long long x)
{
	long long maxn=0;
	for(int i=0;i<=x;i++)
	{
		maxn=max(maxn,ca[i]-cb[i]+va[x-i]-vb[x-i]); 
	}
	return maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int asdf;
	cin>>asdf;
	while(asdf--)
	{
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>t[i].a>>t[i].b>>t[i].c; 
			if(t[i].c!=0)	flag=0;
		}
		if(flag)
		{
			sort(t+1,t+n+1,lkj);
			long long cnt=0;
			for(int i=1;i<=n/2;i++)
				cnt+=t[i].a;
			for(int i=n/2+1;i<=n;i++)
				cnt+=t[i].b;
			cout<<cnt<<endl; 
			continue;
		}
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						if(i-j-k>n/2)	continue;
						if(j!=0)
						{
							if(i-j-k<=n/2) 	ff[j][k]=max(ff[j][k],f[j-1][k]+t[i].a);
						}
						if(k!=0)
						{
							if(i-j-k<=n/2)	ff[j][k]=max(f[j][k-1]+t[i].b,ff[j][k]);
						}
						if(i-j-k>0)	ff[j][k]=max(ff[j][k],f[j][k]+t[i].c);
					}
				}
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						f[j][k]=ff[j][k];
						ff[j][k]=0;
					}
				}
			}
			long long maxn=0;
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					if(n-i-j<=n/2)
					{
						maxn=max(maxn,f[i][j]);
					}
					f[i][j]=0;
				}
			}
			cout<<maxn<<endl;
			continue;
		}
		sort(t+1,t+n+1,lkj);
		for(int i=1;i<=n/2;i++)
		{
			c.push_back(t[i]);
		}
		for(int i=n/2+1;i<=n;i++)
		{
			v.push_back(t[i]);
		}
		sort(c.begin(),c.end(),asd);
		sort(v.begin(),v.end(),asdd);
		for(int i=0;i<c.size();i++)
		{
			ca[i+1]=ca[i]+c[i].c;
			cb[i+1]=cb[i]+c[i].a;
			va[i+1]=va[i]+v[i].c;
			vb[i+1]=vb[i]+v[i].b;
		}
		long long l=0,r=n/2;
		while(l<r-3)
		{
			long long u=(r-l+1)/3;
			long long xx=gong(l+u),yy=gong(l+u+u);
			long long eeie=max(xx,yy);
			if(xx==eeie)
			{
				r=yy;
			}
			if(yy==eeie)
			{
				l=xx+1;
			}
		}
		long long maxn=0;
		for(int i=l;i<=r;i++)
		{
			maxn=max(maxn,gong(i));
		}
		maxn+=cb[n/2];
		maxn+=vb[n/2];
		for(int i=0;i<=n/2;i++)
		{
			ca[i]=cb[i]=va[i]=vb[i]=0;
		}
		v.clear();
		c.clear();
		cout<<maxn<<endl;
	}
	return 0;
 } 
