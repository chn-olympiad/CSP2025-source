#include<bits/stdc++.h>
using namespace std;
long long t,a[100009],b[100009],c[100009];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		long long ans=0,i,j,n;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[j]>a[i])
				{
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					swap(c[j],c[i]);
				}
			}
		}
		long long sa=0,maxx=0,z;
		for(int i=1;i<=n/2;i++)
		{
			sa=sa+a[i];
		}
		if(sa>maxx)
		{
			maxx=sa;
			z=1;
		}

		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(b[j]>b[i])
				{
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					swap(c[j],c[i]);
				}
			}
		}
		long long sb=0;
		for(int i=1;i<=n/2;i++)
		{
			sb=sb+b[i];
		}
		if(sb>maxx)
		{
			maxx=sb;
			z=2;
		}

		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(c[j]>c[i])
				{
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					swap(c[j],c[i]);
				}
			}
		}
		long long sc=0;
		for(int i=1;i<=n/2;i++)
		{
			sc=sc+a[i];
		}
		if(sc>maxx)
		{
			maxx=sa;
			z=3;
		}

		ans=ans+maxx;
		if(z==1)
		{
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(a[j]>a[i])
					{
						swap(a[j],a[i]);
						swap(b[j],b[i]);
						swap(c[j],c[i]);
					}
				}
			}
			for(i=1;i<=n/2;i++)
			{
				a[i]=0;
				b[i]=0;
				c[i]=0;
			}
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(b[j]>b[i])
					{
						swap(b[j],b[i]);
						swap(c[j],c[i]);
					}
				}
			}
			long long sb=0,maxx=0;
			for(int i=1;i<=n/2;i++)
			{
				sb=sb+b[i];
			}
			if(sb>maxx)
			{
				maxx=sb;
				z=2;
			}

			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(c[j]>c[i])
					{
						swap(b[j],b[i]);
						swap(c[j],c[i]);
					}
				}
			}
			long long sc=0;
			for(int i=1;i<=n/2;i++)
			{
				sc=sc+c[i];
			}
			if(sc>maxx)
			{
				maxx=sc;
				z=3;
			}
			ans=ans+maxx;
		}
		else
		{
			if(z==2)
			{
				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(b[j]>b[i])
						{
							swap(a[j],a[i]);
							swap(b[j],b[i]);
							swap(c[j],c[i]);
						}
					}
				}
				for(i=1;i<=n/2;i++)
				{
					a[i]=0;
					b[i]=0;
					c[i]=0;
				}
				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(a[j]>a[i])
						{
							swap(a[j],a[i]);
							swap(c[j],c[i]);
						}
					}
				}
				long long sa=0,maxx=0;
				for(int i=1;i<=n/2;i++)
				{
					sa=sa+a[i];
				}
				if(sa>maxx)
				{
					maxx=sa;
					z=2;
				}

				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(c[j]>c[i])
						{
							swap(a[j],a[i]);
							swap(c[j],c[i]);
						}
					}
				}
				long long sc=0;
				for(int i=1;i<=n/2;i++)
				{
					sc=sc+c[i];
				}
				if(sc>maxx)
				{
					maxx=sc;
				}
				ans=ans+maxx;
			}
			else
			{
				for(i=1;i<=n/2;i++)
				{
					a[i]=0;
					b[i]=0;
					c[i]=0;
				}
				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(a[j]>a[i])
						{
							swap(a[j],a[i]);
							swap(b[j],b[i]);
						}
					}
				}
				long long sa=0,maxx=0;
				for(int i=1;i<=n/2;i++)
				{
					sa=sa+a[i];
				}
				if(sa>maxx)
				{
					maxx=sa;
				}

				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(b[j]>b[i])
						{
							swap(b[j],b[i]);
							swap(a[j],a[i]);
						}
					}
				}
				long long sb=0;
				for(int i=1;i<=n/2;i++)
				{
					sb=sb+b[i];
				}
				if(sc>maxx)
				{
					maxx=sb;
				}
				ans=ans+maxx;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}