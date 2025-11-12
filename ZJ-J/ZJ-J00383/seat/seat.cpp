#include<bits/stdc++.h>
using namespace std;
int a[10005];
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
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	int f;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(sum==a[i])
		{
			f=i;
		}
	}
	int i=(f-1)/m+1,j;
	if(i%2==1)
	{
		j=(f-1)%m+1;
	}
	else
	{
		j=m-(f-1)%m;
	}
	cout<<i<<" "<<j;
	return 0;
}
