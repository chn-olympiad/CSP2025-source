#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int p=1;
int c=0,r=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
		if(a[i]>a[1])
		{
			p++;
		}
	}
	c=(p-1)/n+1;
	if(c%2==0)
	{
		r=n-(p-(c-1)*n)+1;
	}
	else
		{
			r=p-(c-1)*n;
		}
	cout <<c << " " << r << endl;
	return 0;
}
