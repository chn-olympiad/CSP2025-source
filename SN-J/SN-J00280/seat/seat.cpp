#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int a[m*n];
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	int a1=a[0],r=a[0];
	for(int i=0;i<m*n;i++)
	{
		for(int j=0;j<m*n;j++)
			if(a[j]>a[j+1])
			{
				a1=a[j];
				a[j]=a[j+1];
				a[j+1]=a1;			
			}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(r=a[j])
			{
				cout<<i<<' '<<j;	
				break;
			}
		}
	}
	return 0;
 } 
