#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000];
int m,n,sum,summ;
int ox,son;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=m*n;i++)
	{
		if(sum==a[i])
		{
			summ=m*n-i+1;
		}
	}
	if(summ%m==0)
	{
		ox=summ/m;
	}
	if(summ%m!=0)
	{
		ox=summ/m+1;
	}
	cout<<ox<<" ";
	son=summ+m-ox*m;
	if(ox%2==0)
	{
		cout<<m-son+1;
	}
	if(ox%2!=0)
	{
		cout<<son;
	}
	return 0;
}
