#include <bits/stdc++.h>
using namespace std;
int n;
int a[5012];
int c(int ma)
{
	int suma;
	for (int i=3;i<=ma;i++)
	{
		int sumb=0;
		int j=i;
		while (j--)
		{
			sumb*=((ma-j+1)/j);
			sumb%=998;
			sumb%=244;
			sumb%=353;
		}
		suma+=sumb;
		suma%=998;
		suma%=244;
		suma%=353; 
	}
	return suma; 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (a[1]==1)
	{
		cout<<c(n);
	}
	return 0;
 } 
