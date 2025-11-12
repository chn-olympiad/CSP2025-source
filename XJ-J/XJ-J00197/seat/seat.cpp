#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,k,xr,cnt=1;
	cin>>n>>m;
	int a[n+5][m+5],num[n*m+5];
	for(i=1;i<=n*m;i++)
		cin>>num[i];
	xr=num[1];
	sort(num+1,num+n*m+1,cmp);
	for(j=1;j<=m;j++)
	{
		if(j%2==0)
		{
			for(i=n;i>=1;i--)
			{
				a[i][j]=num[cnt];
				cnt++;
				if(a[i][j]==xr)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				a[i][j]=num[cnt];
				cnt++;
				if(a[i][j]==xr)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 
