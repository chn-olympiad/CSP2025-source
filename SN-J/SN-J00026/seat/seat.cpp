#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],ren,qian=1,hangg,liee;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ren=n*m;
	cin>>a[1];
	for(int i=2;i<=ren;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			qian++;
		}
	}
	if(qian%n==0)
	{
		if((qian/n)%2==1)
		{
			liee=qian/n;
			hangg=n;
		}
		else
		{
			liee=qian/n;
			hangg=1;
		}
	}
	else if((qian/n+1)%2==1)
	{
		liee=qian/n+1;
		hangg=qian%n;
	}
	else
	{
		liee=qian/n+1;
		hangg=n-(qian%n)+1;
	}
	cout<<liee<<" "<<hangg;
	return 0;
} 
