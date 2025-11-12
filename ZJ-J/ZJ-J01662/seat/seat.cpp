#include<bits/stdc++.h>
using namespace std;
int a[300][300],b[90000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,x=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			cnt++;
			b[cnt]=a[i][j];
		}
	}
	x=a[1][1];
	sort(b+1,b+1+cnt);
	for(int i=cnt;i>=1;i--)
	{
		if(b[i]==x)
		{
			sum=cnt-i+1;
			break;
		}
	}
	if(sum/n%2==0)
	{
		if(sum%n==0)
		{
			cout<<sum/n<<" "<<n;
		}
		else
		{
			cout<<sum/n+1<<" "<<sum%n;
		}
	}
	else
	{
		if(sum%n==0)
		{
			cout<<sum/n<<" "<<n;
		}
		else
		{
			cout<<sum/n+1<<" "<<n-sum%n+1;
		}
	}
	return 0;
} 
