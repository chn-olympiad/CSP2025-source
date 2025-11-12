#include<bits/stdc++.h>
using namespace std;
int a[500],dp[20][20],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int al=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		cnt++;
		if(a[i]==al)
		{
			break;
		}
	}
	cnt=n*m-cnt+1; 
	int c=cnt/n;
	if(c*n==cnt)
	{
		cout<<c<<" ";
	}
	else
	{
		c++;
		cout<<c<<" ";
	}
	int r=cnt%n;
	if(c%2==1)
	{
		cout<<r;
	}
	else
	{
		cout<<n-r+1;
	}
	return 0; 
	
}

 
