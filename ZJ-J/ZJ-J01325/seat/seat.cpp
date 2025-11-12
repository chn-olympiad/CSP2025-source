#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,num,ansx,ansy,a[329];
signed main()
{
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	sum=1;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			sum++;
	}
	for(int j=1;j<=m;j++)//m  lie
	{
		if(j%2==1)
			for(int i=1;i<=n;i++)//n  line
			{
				num++;
				if(num==sum)
				{
					ansy=i;
					break;
				}
			}
		else
			for(int i=n;i>=1;i--)//n  line
			{
				num++;
				if(num==sum)
				{
					ansy=i;
					break;
				}
			}
		if(ansy!=0)
		{
			ansx=j;
			cout<<ansx<<" "<<ansy;
			return 0;
		}
	}
 	return 0;
}