#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010],m=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]-a[i]==k)
			{
				if(a[i]!=0)
				{
					m++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			m++;
		}
	}
	cout<<m;
	return 0;
}
