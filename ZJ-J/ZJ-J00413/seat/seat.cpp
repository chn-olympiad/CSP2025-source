#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[50][50],k,cnt,l,h,r;
int b[1000];
main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[++k]=a[i][j];
		}
	}
	r=a[1][1];
	sort(b+1,b+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		cnt++;
		if(r==b[i])
			break;
	}
	if(cnt%n==0)
	{
		l=cnt/n;
		h=n;
	}
	else 
	{
		l=(cnt+n)/n;
		if(l%2==1)
		h=cnt%n;
		else h=(n-cnt%n+1);
	}
	cout<<l<<" "<<h;
}










