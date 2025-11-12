#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,cj;
int  cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[15][15],t=0,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s[j][i]=a[j+t];
			}
		}
		else if(i%2==0)
		{
			k=1;
			for(int j=n;j!=0;j--)
			{
				s[j][i]=a[k+t];
				k++;
			}
		}
		t=t+m;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(cj==s[i][j])
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
