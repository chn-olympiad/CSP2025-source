//段宇晨  SN-S00435  西安滨河学校 
#include <bits/stdc++.h>
using namespace std;
int dx(int n)
{
	int a[n],b[n],c[n];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	int maxa = 0,maxb = 0,maxc = 0;
	int a1,b1,c1;
	for(int i = 1;i <= n;i++)
	{
		if(maxa <= a[i])
		{
			maxa = a[i];
			a1 = i;
		}
		if(maxa <= b[i])
		{
			maxa = b[i];
			b1 = i;
		}
		if(maxc <= c[i])
		{
			maxc = c[i];
			c1 = i;
		}
	}
	cout << a[a1]+b[b1]+c[c1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		dx(n);
	}
}
