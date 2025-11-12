#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long n,m,r[N],xr,map[N][N],cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>r[i];
	}
	xr=r[1];
	sort(r+1,r+1+(n*m));
	reverse(r+1,r+1+(n*m));
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(r[cnt]==xr)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(r[r[cnt]==xr])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
