#include <iostream>
using namespace std;
int a,b,c[5005],d[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	
	for (int i=1;i<=a;i++)
	{
		cin>>c[i];
		
	}
	
	for (int i=1;i<=a;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (c[i]<c[j])
			{
				swap(c[i],c[j]);
			}
		}
	}
	if (a==3)
	{
		if (c[1]+c[2]>c[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else
	{
		cout<<a;
	}
    return 0;
}
