#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ont","r",stdout);
	int n,s=0,w=0;
	cin >> n;
	int a[n],d[n];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s+=a[i];
	}
	for(int i=3;i<=n;i++)
	{
		d[i]=s/i;
		w+=d[i];
	}
	cout <<  w-2;
	return 0;
}
