#include<iostream>
using namespace std;
int a[10005];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==a[j])
			{
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
 } 
