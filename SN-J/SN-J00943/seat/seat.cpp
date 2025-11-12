#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	int b=0;
	cin>>n>>m;
	int a[15][15],s[300];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[b]=a[i][j];
			b++;
		}
	}
	int p=0;
    int c=n*m;
	sort(b+1,b+c+1);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i]==a[1][1])
		{
			p=i;
		}
	}
	int d=p/n;
	int y=p%n;
	d+=1;
	if(d%2==1)
	{
		cout<<d<<" "<<y;
	}
	else
	{
		cout<<d<<" "<<n+1-y;
	}
	return 0;
}
