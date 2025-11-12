#include<bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],r,b[15][15],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			r=a[1][1];
			if(r<=a[i][j])
			{
				cnt++;
			}
		}
	}
	if(cnt%n==0)
	{
		cout<<cnt/n<<" ";
		if((cnt/n)%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2==1)
		{
			cout<<cnt%n;
		}
		else
		{
			cout<<abs(cnt%n-n)+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
