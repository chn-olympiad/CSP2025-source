//考号：CN-J01099   姓名：陈墨涵   学校：西安高新一中沣东中学初中校区 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m,a[1005],m1,n1,li;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int l=a[1];
	for (int i=1;i<=n*m-1;i++)
	{
		for (int j=i+1;j<=n*m;j++)
		{
			if (a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==l)
		{
			li=i;
		}
	}
	if (li%n==0)
	{
		m1=li/n;
	}
	else
	{
		m1=li/n+1;
	}
	if (m1%2==0)
	{
		n1=n-li%n+1;
	}
	else
	{
		if(li%n==0)
		{
			n1=li;
		}
		else
		{
			n1=li%n;
		}
	}
	cout<<m1<<" "<<n1;
	return 0;
}
