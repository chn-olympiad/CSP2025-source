#include<bits/stdc++.h>
using namespace std;
int a[15][15],m,n,b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m>>n;
	int c=1;
	for(int i=1;i<=m*n;i++)
	{
		cin >> b[i];
	}
	int p=b[1];
	for(int i=1;i<=m*n;i++)
	{
		for(int j=i+1;j<=m*n;j++)
		if(b[i]<b[j])
		{
			swap(b[i],b[j]);
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[c];
				c++;
				if(a[i][j]==p)
				{
					cout << i <<" " <<  j;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[c];
				c++;
				if(a[i][j]==p)
				{
					cout << i <<" " <<  j;
				}
			}
		}
	}
	return 0;
}
