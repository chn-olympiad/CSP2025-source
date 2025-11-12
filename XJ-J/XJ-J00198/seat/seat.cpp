#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("seat.in","s");
	freopen("seat.out","s");
	int n,m,h=0;
	int lz=-1;
	cin >>n >>m;
	int a[n*m];
	for (int i=0;i<n*m;i++)
	{
		cin >>a[i];
	}
	for (int i=0;i<n*m;i++)
	{
		if(lz<a[i])
		{
			lz=a[i];
			h=i;
		}
	}
	if ((lz>a[0]) && (h-1!=1))
	{
	    cout <<n-1  <<" " <<m;
    }
    else
    {
    	cout <<n  <<" " <<m;
	}
	return 0;
}
