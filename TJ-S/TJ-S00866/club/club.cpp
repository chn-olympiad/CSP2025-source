#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int a,b,c,d,e;
};
bool cmp(stu a1,stu a2)
{
	return a1.d>a2.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	stu m[100005];
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>m[j].a>>m[j].b>>m[j].c;
			m[j].d=max(m[j].a,m[j].b);
			m[j].d=max(m[j].d,m[j].c);   
			if(m[j].d==m[j].a)
			{
				m[j].e=1;
			}
			else if(m[j].d==m[j].b)
			{
				m[j].e=2;
			}
			else if(m[j].d==m[j].c)
			{
				m[j].e=3;
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int k=1;k<n;k++)
			{
				if(m[k-1].d<m[k].d)
			{
				swap(m[k-1].d,m[k].d);
			}
			}
		}
		int x=0,y=0,z=0;
		for(int j=0;j<n;j++)
		{
			if(m[j].e==1)
			{
				x++;
			}
			if(m[j].e==2)
			{
				y++;
			}
			if(m[j].e==3)
			{
				z++;
			}
		}     
		if(x>n/2)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(m[j].e==1)
				{
					int r=0;
					for(int k=0;k<j;k++)
					{
						if(m[k].e==1&&max(m[k].b,m[k].c)>max(m[j].b,m[j].c))
						{
							m[k].d=max(m[k].b,m[k].c);
							if(m[k].d==m[k].c)
							{
								m[k].e=3;
							}
							if(m[k].d==m[k].b)
							{
								m[k].e=2;
							}
							r=1;
							break;
						}
					}
					if(r==0)
					{
						m[j].d=max(m[j].c,m[j].b);
					}
					x--;
					
					
				}
				if(x==n/2)
				{
					break;
				}
			}
		}
		if(y>n/2)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(m[j].e==2)
				{
					int r=0;
					for(int k=0;k<j;k++)
					{
						if(m[k].e==2&&max(m[k].c,m[k].a)>max(m[j].c,m[j].a))
						{
							m[k].d=max(m[k].c,m[k].a);
							if(m[k].d==m[k].a)
							{
								m[k].e=1;
							}
							if(m[k].d==m[k].c)
							{
								m[k].e=3;
							}
							r=1;
							break;
						}
					}
					if(r==0)
					{
						m[j].d=max(m[j].a,m[j].c);
					}
					y--;
					
					
				}
			
			if(y==n/2)
				{
					break;
				}
			}
		}
		if(z>n/2)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(m[j].e==3)
				{
					int r=0;
					for(int k=0;k<j;k++)
					{
						if(m[k].e==3&&max(m[k].b,m[k].a)>max(m[j].b,m[j].a))
						{
							m[k].d=max(m[k].b,m[k].a);
							if(m[k].d==m[k].a)
							{
								m[k].e=1;
							}
							if(m[k].d==m[k].b)
							{
								m[k].e=2;
							}
							r=1;
							break;
						}
					}
					if(r==0)
					{
						m[j].d=max(m[j].a,m[j].b);
					}
					z--;
					
				}
				if(z==n/2)
				{
					break;
				}
			}
		}
		int sum=0;
		for(int j=0;j<n;j++)
		{
			
			sum+=m[j].d;
		}
		cout<<sum<<endl;
	}
	return 0;
}
