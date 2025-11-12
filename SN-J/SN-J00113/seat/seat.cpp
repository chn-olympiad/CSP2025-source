#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int sum=n*m;
	int a1;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			a1=a[i];
		}
	}
	sort(a+1,a+sum+1,cmp);
	int h,l,a2;
	for(int i=1;i<=sum;i++)
	{
		if(a1==a[i])
		{
			a2=i;
		}
	}
	l=a2/n+1;
	if(l%2==1)
	{
		h=n-a2%n;
	}
	else
	{
		h=a2%n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
