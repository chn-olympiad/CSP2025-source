#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int z;
	cin>>z;
	a[1]=z;
	for (int i=2;i<=s;i++)
	{
		cin>>a[i];
	}
	int nm=-1;
	sort(a+1,a+s+1);
	for (int i=1;i<=s;i++)
	{
		if (a[i]==z) nm=i;
	}
	nm=s-nm+1;
	if (nm <=m)
	{
		cout<<1<<" ";
	}
	else
	{
		cout<<nm-nm/m*m+nm/m<<" ";
	}
	if (nm%(n*2) > n)
	{
		cout<<nm-(nm%(n*2)-n);
	}
	else
	{
		cout<<nm%(n*2);
	}
	return 0;
}
