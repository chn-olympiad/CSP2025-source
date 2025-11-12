#include<bits/stdc++.h>
using namespace std;
int a[10102],b[102][102],l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
			cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=m;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(i%2==1)
			b[i][j]=a[++l];
			else
			b[i][n-j+1]=a[++l];

		}

	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==x){
cout<<i<<" "<<j;
				break;
			}


		}

	}
	return 0;
}