#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105][105]={0},i,j,k,t;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>i;
		t=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			sort(a+i+1,a+j+2);
			if(a[i][j]==t)
			{
				cout<<a[i][j];
				break;
			}
		}
	}
	return 0;
}
