#include<iostream>
using namespace std;
int main()
{
	int n,i,a[10005];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i==n/2)
			{
				cout<<i;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
 } 
