#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[5000],num=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b=2;
	while(b!=n)
	{
		int sum=0;
		for(int j=1;j<=n-b;j++)
		{
			int m=-1;
			for(int k=j;k<=b+j;k++)
			{
				sum+=a[k];
				if(m<a[k])
    			{
					m=a[k];
				}
		    }
		    m*=2;
		    if(m<sum)
		    {
		    	num++;
			}
		}
		b++;
	}
	cout<<num;
}
