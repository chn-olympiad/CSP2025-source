#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,c=0;
	cin>>n;
	int q[n],s[n];
	cin>>q[1];
	s[0]=0;
	s[1]=q[1];
	for(int a=2;a<=n;a++)
	{
		cin>>q[a];
		s[a]=q[a]+s[a-1];
	}
	
	for(int a=3;a<=n;a++)
	{
		int z=a;
		for(int b=1;b<=n-a+1;b++)
		{
			if(s[z]-s[b-1]>(2*q[z]))
			{
				c++;
			}	
			z++;
		}
	}
	cout<<c+c/2;
	return 0;
}
