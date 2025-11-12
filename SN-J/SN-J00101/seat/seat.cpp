#include <bits/stdc++.h> #SN-J00101
using namespace std;
int n,m,a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=i+1;j<=q-i;j++)
		{
			if(a[i]<a[j])
			{
				b[i]=a[j];
			}
			else if(a[i]>a[j])
			{
				b[i]=a[i];
			}
		}
	}
	int num=0;
	for(int i=1;i<=q;i++)
	{
		if(b[i]=a[i])
		{
			num=b[i];
		}
	}
	int c=num%n;
	int p=(num-c)/n;
	if(p%2==1)
	{
		cout<<p<<c;
	}
	else if(p%2==0)
	{
		cout<<p<<n-c;
	}
	return 0;
}
