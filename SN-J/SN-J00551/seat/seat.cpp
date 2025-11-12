#include<bits/stdc++.h>
using namespace std;
int n,m,xx,zong,wei,hang,lie;
int a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zong=n*m;
	for(int i=1;i<=zong;i++)
	{
		cin>>a[i];
	}
	xx=a[1];
	sort(a+1,a+zong+1);
	for(int i=1;i<=zong;i++)
	{
		b[i]=a[zong-i+1];
		if(b[i]==xx)
		{
			wei=i;
		}
	}
	if(wei%n==0)
	{
		hang=n;
	}
	else
	{
		hang=wei%n;
	}
	lie=(wei-hang+n)*1.0/n;
	if(lie%2==1)
	{
		cout<<lie<<" "<<hang;
	}
	else
	{
		cout<<lie<<" "<<(n-hang+1);
	}
	return 0;
}
