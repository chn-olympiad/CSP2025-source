#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1005][1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+x+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			b[i][j]=a[i];
			if(b[i][j]==r)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
