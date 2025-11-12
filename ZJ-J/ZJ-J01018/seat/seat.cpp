#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int nn=1;
	for (int i=1;i<=n*m;i++)
	{
		if (x==a[i])
		{
			cout<<nn<<' ';
			if (nn%2==1)
			{
				if (i%m==0)
					cout<<m;
				else
					cout<<i%m;
			}
			else
				cout<<m-i%m+1;
		}
		if (i%m==0)
			nn++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
