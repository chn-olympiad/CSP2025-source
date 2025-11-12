#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0,n=0,m1b=0,m2b=0,m3b=0,n1b=0,n2b=0,n3b=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		
		for(int j=n;j>=1;j--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(max(a,max(b,c))==a)
			{
				if(m1b<n/2)
				{
					m1b++;
					n1b+=a;
				} 
				else
				{
					if(max(min(a,b),c)==b)
					{
						m2b++;
						n2b+=b;
					}
					else
					{
						m3b++;
						n3b+=c;
					} 
				}
			}
			if(max(a,max(b,c))==b)
			{
				if(m2b<n/2)
				{
					m2b++;
					n2b+=b;
				}
				else
				{
					if(max(min(a,b),c)==a)
					{
						m1b++;
						n1b+=a;
					}
					else
					{
						m3b++;
						n3b+=c;
					} 
				}
			} 
			if(max(a,max(b,c))==c)
			{
				if(m3b<n/2)
				{
					m3b++;
					n3b+=c;
				}
				else
				{
					if(max(min(a,b),c)==b)
					{
						m2b++;
						n2b+=b;
					}
					else
					{
						m1b++;
						n1b+=a;
					} 
				}
			}
			
		}
			
		cout<<n1b+n2b+n3b<<endl;
		m1b=0,m2b=0,m3b=0,n1b=0,n2b=0,n3b=0;
	}
	return 0;
 } 