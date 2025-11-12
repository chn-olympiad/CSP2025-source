#include <bits/stdc++.h>
using namespace std;
int n,m,k,num,mun;
int a[110];
int l,c;//c hang,l lie
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==k)
		{
			num=i;
		}
		c=num%n;
		if (num%n==0)
		{
			c=n;
		}
		l=num/n+1;
	}

	cout << c << " " << l;
	return 0;
}
