#include<bits/stdc++.h>
using namespace std;
int a[1100];
int cnt=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int num=n*m;
	int xr=a[1];
	sort(a+1,a+num+1,cmp);

	for(int i=1;i<=n;i++)
	{

		for(int j=1;j<=m;j++)
		{
			if(a[cnt]==xr)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			cnt++;
		}
		i++;
		if(i>n)
		{
			return 0;
		}
		for(int k=m;k>=1;k++)
		{
			if(a[cnt]==xr)
			{
				cout<<i<<" "<<k;
				return 0;
			}
			cnt++;
		}
	}
	return 0;
 }
