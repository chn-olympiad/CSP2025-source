#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int a[5000]={0},b=0;
int main ()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int n,g=0;
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	if (n==3)
	{
		b=max(a[1],max(a[2],a[3]));
		if (2*b<a[1]+a[2]+a[3])
			g++;
		cout << g;
		return 0;
	}
	if (n==4)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				for (int z=j+1;z<=n;z++)
				{
					b=max(a[i],max(a[j],a[z]));
					if (2*b<a[i]+a[j]+a[z])
					{
						g++;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		if (a[1]<a[2]+a[3]+a[4])
			g++;
		cout << g;
		return 0;
	}
	return 0;
}
