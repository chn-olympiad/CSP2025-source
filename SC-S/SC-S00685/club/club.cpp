#include <bits/stdc++.h>
using namespace std;
struct yy
{
	int c[3];

};
yy h[5][100010];
bool qq(yy a,yy b)
{
	if(max(a.c[0],max(a.c[1],a.c[2]))-(a.c[0]+a.c[1]+a.c[2]-max(a.c[0],max(a.c[1],a.c[2])))/2>max(b.c[0],max(b.c[1],b.c[2]))-(b.c[0]+b.c[1]+b.c[2]-max(b.c[0],max(b.c[1],b.c[2])))/2)
	{

		return 1;
	}
	else
	{

		return 0;
	}
}
int n[5];
int a1=0,b1=0,c1=0,ans=0;
int a=0;
int main()
{
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int i,t,w=0;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		cin>>n[j];
		for(int i=0; i<n[j]; i++)
		{
			cin>>h[j][i].c[0]>>h[j][i].c[1]>>h[j][i].c[2];
		}
		sort(h[j],h[j]+n[j],qq);
		w=n[j]/2;
	
	a1=0;
	b1=0;
	c1=0;

		for(int i=0; i<n[j]; i++)
		{

			if(max(h[j][i].c[0],max(h[j][i].c[1],h[j][i].c[2]))==h[j][i].c[0])
			{

				if(a1+1>w)
				{

					if(h[j][i].c[1]>h[j][i].c[2])
					{
						b1++;
						ans+=h[j][i].c[1];
					}
					else
					{
						c1++;
						ans+=h[j][i].c[2];
					}
				}
				else
				{
					a1++;
					ans+=h[j][i].c[0];
				
				}
			}
			else if(max(h[j][i].c[0],max(h[j][i].c[1],h[j][i].c[2]))==h[j][i].c[1])
			{
				if(b1+1>w)
				{
				
					if(h[j][i].c[0]>h[j][i].c[2])
					{
						a1++;
						ans+=h[j][i].c[0];
					}
					else
					{
						c1++;
						ans+=h[j][i].c[2];
					}
				}
				else
				{
					b1++;	
					ans+=h[j][i].c[1];
				}
			}
			else
			{
				if(c1+1>w)
				{
					if(h[j][i].c[0]>h[j][i].c[1])
					{
						a1++;
						ans+=h[j][i].c[0];
					}
					else
					{
						b1++;
						ans+=h[j][i].c[1];
					}
				}
				else
				{
					c1++;
					ans+=h[j][i].c[2];
				}
			}
	
		}

		cout<<ans<<'\n';
		ans=0;
	}
}
