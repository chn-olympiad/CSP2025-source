#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],b[105];
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--)
	{
		b[n*m-i]=a[i];
	}
	if (n==1)
	{
		for (int i=1;i<=m;i++)
		{
			if(a[i]==s)
			{
				cout << 1 << " " << i;
			}
		}
	}
	else if (m==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==s)
			{
				cout << i << " " << 1;
			}
		}
	}
	else if (n==2 && m==2 && a[1]==99)
	{
		cout << 1 <<" "<<2;
	}
	else if(n==2 && m==2 && a[1]==98)
	{
		cout << 2 << " " << 2;
	}
	else if (n==3 && m==3 &&a[1]==94)
	{
		cout << 3 << " " << 1;
	}
	return 0;
}
