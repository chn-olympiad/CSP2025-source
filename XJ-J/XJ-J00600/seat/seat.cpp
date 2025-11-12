#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],rs,pl,pm,pn;
int y(int a)
{
	return int(float(a));
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
	rs=a[1];
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==rs)
		{
			pl=i;
			break;
		}
	}
	pl=n*m-pl+1;
	if (pl%n==0)
		pm=y(pl/n);
	else
		pm=y(pl/n)+1;
	if (pm%2==0)
		pn=n-pl%n+1;
	else
		pn=pl%n;
	if (pn==0)
		pn+=n;
	cout << pm << " " << pn << endl;
	return 0;
} 
