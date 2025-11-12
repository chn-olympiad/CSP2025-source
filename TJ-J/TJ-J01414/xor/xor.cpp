#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct num
{
	int b,c;
}s[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,d=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int m=0;
			for(int l=i;l<=j;l++)
			{
				m^=a[l];
			}
		//	cout<<m<<endl;
			if(m==k)
			{
				int flag=0;
				for(int g=0;g<d;g++)
				{
					int flag2=0;
					for(int h=0;h<n;h++)
					{
						if(h>=s[g].b&&h<=s[g].c&&h>=i&&h<=j)
						{
							flag=1;
							flag2=1;
							break;
						}
					}
					if(flag2==1)
					{
						break;
					}
				}
				if(flag==0)
				{
					
					s[d].b=i;
					s[d].c=j;
					d++;
				}
			}
		}	
	}
	cout<<d;
	return 0;
 } 
