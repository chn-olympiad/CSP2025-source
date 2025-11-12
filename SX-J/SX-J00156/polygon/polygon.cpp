#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	long long n,s=0,c=0,x,y,o,ma;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ma=LLONG_MIN;
			for(int l=i;l<j;l++)
			{
				if(ma<a[l])ma=a[l];
    			if(i==l)
				{
					x=a[l],y=a[l+1];
					o=x+y;
					s=o;
				}
				else
				{
					y=a[l+1];
     				o=o+y;
					s=o;
				}
			}
			if(ma<a[j])ma=a[j];
			if(i==j)s=a[i];
			if(s>ma*2)
			{
				c++;
			}
			else continue;
		}
	}
	cout<<c;
	return 0;
}